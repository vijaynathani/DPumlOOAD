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
class  DeliveryAddress {
    public:
        virtual string toString() = 0;
};
class HomeAddress : public DeliveryAddress {
    Customer *c;
    public:
        string toString() { return c->getHomeAddress(); }
};
class WorkAddress : public DeliveryAddress {
    Customer *c;
    public:
        string toString() { return c->getWorkAddress(); }
};
class SpecificAddress : public DeliveryAddress {
    string *addr;
    public:
        string toString() { return addr; }
};
class Order {
    string orderId;
    Restaurant restaurantReceivingOrder;
    Customer customerPlacingOrder;
    DeliveryAddress *address;
    //map orderItems;
	public:
	string *getDeliveryAddress() {
        return address->toString();
    }
};
