#include <string>
#include <vector>
using namespace std;
namespace deepInheritanceHierarchy {
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

class PricingService {
	public: 
	double calculatePrice(ShoppingBasket *shoppingBasket,
            User *user, string *voucher) {
        double discount = calculateDiscount(user);
		vector<Item *> *items = shoppingBasket->items();
        double total = 0;
		for (unsigned int i=0; i< items->size(); i++) 
            total += calculateProductPrice(items->at(i)->getProduct(),
                    items->at(i)->getQuantity());
        total += applyAdditionalDiscounts(total, user, voucher);
        return total * ((100 - discount) / 100);
    }
	protected: 
	virtual double calculateDiscount(User *user) = 0;
    virtual double calculateProductPrice(Product *product,
            int quantity) = 0;
    virtual double applyAdditionalDiscounts(double total,
            User *user, string *voucher) = 0;
	virtual ~PricingService() {}
};
class UserDiscountPricingService : public PricingService {
	protected: double calculateDiscount(User *user) {
        int discount = 0;
        if (user->isPrime()) {
            discount = 10;
        }
        return discount;
    }
};
class VoucherPricingService : public UserDiscountPricingService {
    VoucherService *voucherService;
	protected: double applyAdditionalDiscounts(double total,
            User *user, string *voucher) {
        double voucherValue = voucherService->getVoucherValue(voucher);
        double totalAfterValue = total - voucherValue;
        return (totalAfterValue > 0) ? totalAfterValue : 0;
    }
	public: void setVoucherService(VoucherService *voucherService) {
        this->voucherService = voucherService;
    }
};
class StandardPricingService : public VoucherPricingService {
	protected: double calculateProductPrice(Product *product,
            int quantity) {
        return product->getPrice() * quantity;
    }
};
class BoxingDayPricingService : public VoucherPricingService {
	public: static const double BOXING_DAY_DISCOUNT = 0.60;
	protected: double calculateProductPrice(Product *product,
            int quantity) {
        return ((product->getPrice() * quantity) * BOXING_DAY_DISCOUNT);
    }
};
}
