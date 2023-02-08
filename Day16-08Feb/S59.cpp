#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Date { //...
};
class OrderLine {
    string *productName;
    int quantity;
};
class Order {
    string orderId;
    string customerId;
    string supplierId;
    Date orderDate;
    vector<OrderLine *> orderLines;
};
class Orders {
    vector<Order *> orders;
    void placeOrder(string &customerId, string &supplierId, //...
			) {
        //...
    }
    void printOrdersByCustomer(string &customerId) {
        //...
    }
    void printOrdersForSupplier(string &supplierId) {
        //...
    }
};
class Discount {
    string *supplierId;
    string *customerId;
    string *productName;
    double discountRate;
};
class Discounts {
    vector<Discount> discounts;
    void addDiscount(string supplierId, string customerId,
        string productName, double discountRate) {
        //...
    }
    double findDiscount(string supplierId,string customerId,
        string productName){
        //...
    }
};
class SalesSystem {
    vector<Customer *> customers;
    vector<Supplier *> suppliers;
    Orders orders;
    Discounts discounts;
};
