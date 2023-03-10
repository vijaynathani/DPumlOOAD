#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
namespace jan20 {
	class Party {
	public:
		string location;
	};
	class Person1 : public Party {};
	class Organization : public Party {
	public:
		vector<Party*> children;
	};

	class Author {
	public:
		string name;
		int age=0;
	};
	class Computer {
	public:
		string name;
		int memory = 0;
		Author* usedBy = nullptr;
	};


	class Collection {
	public:
		virtual bool equals(void* other) = 0;
		virtual void add(void* item) = 0;
	};
	class List : public Collection {
	public:
		virtual void* get() = 0;
	};
	class AbstractList : public List {
	public:
		bool equals(void* other) override { return false; }
		void add(void* item) override {}
	};
	class ArrayList : public AbstractList {
	public:
		void* get() override { return nullptr; }
		void add(void* item) override {}
	};



	class EmailSystem {
	public:
		virtual void send(string message) = 0;
	};
	class SMTPEmailSystem : public EmailSystem {
	public:
		void send(string message) override {}

	};


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
		Customer* c;
	public:
		void dispatch() {}
		void close() {}
	};

	class Order1 {
		//map <Product&, OrderLine*> lineItems;
		//Above line is commented because map comparison functions are absent.
	};

	class Meeting {};
	class Attendance {
		Person* p;
		Meeting* m;
		int attentiveness;
	};
	class Company {};
	class Employment {
		Date start, end;
		Person* employee;
		Company* c;
	};
}
using namespace jan20;
void jan20main() {
	Person1 Don, John;
	Don.location = "Champaign";
	John.location = "Champaign";
	Organization engineering, tools, apps;
	tools.location = "Chicago";
	tools.children.push_back(&Don);
	tools.children.push_back(&John);
	apps.location = "saba";
	engineering.location = "Boston";
	engineering.children.push_back(&tools);
	engineering.children.push_back(&apps);



	Author bob;
	bob.name = "Bob J";
	bob.age = 32;
	Computer bobPC;
	bobPC.name = "Dell 466";
	bobPC.memory = 64;
	bobPC.usedBy = &bob;

}

