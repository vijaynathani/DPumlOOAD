#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
namespace jan27_1 {
	class Product {
	public:
		double getPricingDetails() { return 0; }
	};
	class Customer {
	public:
		double getDiscountInfo() { return 0; }
	};
	class OrderLine {
	public:
		int getQuantity() { return 0;  }
		Product* getProduct() { return nullptr; }
	};
	class Order {
		vector<OrderLine> lineItems;
		Customer* c;
		double calculateBasePrice() { return 0; }
		double calculateDiscounts() {
			//..
			auto r = c->getDiscountInfo();
			//..
			return r;
		}
	public:
		double calculatePrice() {
			double r = 0;
			for (auto &li : lineItems) {
				auto q = li.getQuantity();
				auto p = li.getProduct();
				r += p->getPricingDetails() * q;
			}
			return r + calculateBasePrice() - calculateDiscounts();
		}
	};
}
namespace jan27_2 {
	class Order;
	class Product {
	public:
		double getPrice(int quantity) { return 0; }
	};
	class Customer {
	public:
		double getDiscountedValue(Order* o);
	};
	class OrderLine {
		Product* p;
		int quantity;
	public:
		double calculatePrice() {
			return p->getPrice(quantity);
		}
	};
	class Order {
		vector<OrderLine> lineItems;
		Customer* c;
	public:
		double getBaseValue() { return 0; }
		double calculatePrice() {
			double r = 0;
			for (auto& li : lineItems)
				r += li.calculatePrice();
			return r - c->getDiscountedValue(this);
		}
	};
	double Customer::getDiscountedValue(Order* o) {
		//...
		auto r = o->getBaseValue();
		//...
		return r;
	}
}