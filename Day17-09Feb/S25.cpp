#include <string>
#include <map>
using namespace std;
class Restaurant { //...
};
class Customer { //...
};
class Product { //..
};
class OrderItem { //..
	public: double getAmount();
};
class BigDecimal { //...
	public: BigDecimal(char *);
	void add(double value);
	double doubleValue();
};

enum DeliveryAddress { HOME_ADDRESS, WORK_ADDRESS, OTHER_ADDRESS };
class Order {
    string orderId;
    Restaurant restToReceiveOrder;
    Customer customerPlacingOrder;

    string shippingAddress;
    map<Product *, OrderItem *> orderItems; 

	public: double getTotalAmount() {
        BigDecimal totalAmt("0.00");
        for (map<Product *,OrderItem*>::iterator iter=orderItems.begin(); 
				iter != orderItems.end(); ++iter) {
            OrderItem *nextOrderItem=iter->second;
            totalAmt.add(nextOrderItem->getAmount());
        }
        return totalAmt.doubleValue();
    }
};
