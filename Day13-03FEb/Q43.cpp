#include <iostream>
#include <string>
using namespace std;
// Point out and remove the code smells in the code
class Customer {
    string *homeAddress;
    string *workAddress;
	public: string *getHomeAddress() {
		return homeAddress;
	}
	string *getWorkAddress() {
		return workAddress;
	}
};
class Restaurant {
	//...
};
class Order {
    string orderId;
    Restaurant restaurantReceivingOrder;
    Customer customerPlacingOrder;

    //"H": deliver to home address of the customer.
    //"W": deliver to work address of the customer.
    //"O": deliver to the address specified here.
    string addressType;

    string *otherAddress; //address if addressType is "O".
    //map orderItems;

	public:
	string *getDeliveryAddress() {
        if (addressType.compare("H") == 0) {
            return customerPlacingOrder.getHomeAddress();
        } else if (addressType.compare("W") == 0) {
            return customerPlacingOrder.getWorkAddress();
        } else if (addressType.compare("O") == 0) {
            return otherAddress;
        } else {
            return 0;
        }
    }
};
