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
//Improve the code
class Order {
    string orderId; //order ID.
    Restaurant r1; //the order is placed for this restaurant.
    Customer c1; //the order is created by this customer.
    string address; //Shipping address

    map<Product *, OrderItem *> orderItems; //order items.

    //get the total amount of this order.
	public: double getTotalAmt() {
        //total amount.
        BigDecimal *amt= new BigDecimal("0.00");
        //for each order item do...
        map<Product *, OrderItem *>::iterator iter=orderItems.begin();
        while(iter != orderItems.end()){
            //add the amount of the next order item.
            OrderItem *oi=iter->second;
            amt->add(oi->getAmount());
			++iter;
        }
		double d = amt->doubleValue;
		delete amt;
        return d;
    }
};
