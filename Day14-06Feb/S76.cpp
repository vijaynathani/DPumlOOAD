#include <string>
#include <vector>
using namespace std;
namespace  extractInjectKillDeepInheritanceHierarchy {

//To avoid compilation errors, the following classes are created
class VoucherService {
	public: double getVoucherValue(string *voucher) {
        return 0;
    }
};
class User {
	public: bool isPrime() {
        return false;
    }
};
class Product {
	public: double getPrice() {
        return 0;
    }
};
class Item {
	public: 
	Product *getProduct() {
		return NULL;
	}
	int getQuantity() {
		return 0;
	}
};
class ShoppingBasket {
	public: 
	vector<Item *> *items() {
        return NULL;
    }
};

//Main Logic starts here
class PriceCalculation {
	public: virtual double calculateProductPrice(Product *product, int quantity) = 0;
	virtual ~PriceCalculation() {}
};
class PricingService {
    VoucherService *voucherService;
    PriceCalculation *priceCalculation;
	public: 
	PricingService(VoucherService *v, PriceCalculation *pc) {
        voucherService = v;
        priceCalculation = pc;
    }
    double calculatePrice(ShoppingBasket *shoppingBasket,
            User *user, string *voucher) {
        double discount = calculateDiscount(user);
		vector<Item *> *items = shoppingBasket->items();
        double total = 0;
		for (unsigned int i=0; i< items->size(); i++) 
            total += priceCalculation->calculateProductPrice(items->at(i)->getProduct(),
                    items->at(i)->getQuantity());
        total += applyAdditionalDiscounts(total, user, voucher);
        return total * ((100 - discount) / 100);
    }
    double calculateDiscount(User *user) {
        int discount = 0;
        if (user->isPrime()) {
            discount = 10;
        }
        return discount;
    }
    double applyAdditionalDiscounts(double total, User *user,
            string *voucher) {
        double voucherValue = voucherService->getVoucherValue(voucher);
        double totalAfterValue = total - voucherValue;
        return (totalAfterValue > 0) ? totalAfterValue : 0;
    }
};

class StandardPriceCalculation : PriceCalculation {
	public: double calculateProductPrice(Product *product, int quantity) {
        return product->getPrice() * quantity;
    }
};

class BoxingDayPriceCalculation : PriceCalculation {
	public: static const double BOXING_DAY_DISCOUNT = 0.60;
    double calculateProductPrice(Product *product, int quantity) {
        return ((product->getPrice() * quantity) * BOXING_DAY_DISCOUNT);
    }
};
}
