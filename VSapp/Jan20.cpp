#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;


class Employee {};
class Customer {
	string name, address;
public:
	virtual string getCreditRating() { return ""; }
};
class CorporateCustomer : public Customer {
	string contactName, creditRating;
	double creditLimit;
	Employee* salesRep;
public:
	string billForMonth(int month) { return ""; }
	void remind() {}
};
class PersonalCustomer : public Customer {
	string creditCardNumber;
public:
	string getCreditRating() override { return "poor"; }

};

class Person;
class Car {
	Person* owner;
};
class Person {
	vector<Car*> cars;
};


class Boolean {};
class Date {};
class Money {};
class Product {};
class OrderLine {
	int quantity;
	Money price;
	Product* p;
};
class Order {
	Boolean isPrePaid; 
	Date* dateReceived;
	string number;
	Money price;
	vector<OrderLine*> lineItems;
	Customer *c;
public:
	void dispatch() {}
	void close() {}
};
