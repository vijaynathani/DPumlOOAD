#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "OrderWarehouse.h"

using namespace std;
namespace feb28 {
	struct MockWarehouse: public IWarehouse
	{
		bool returnFromHasInventory = true;
		int removeCalled = 0;
		string removeProduct;
		int removeQuantity;
		bool hasInventory(const std::string& product, int quantity) override { 
			return returnFromHasInventory; 
		}
		void remove(const std::string& product, int quantity) override {
			removeCalled++;
			removeProduct = product;
			removeQuantity = quantity;
		}
	};

	TEST(Warehouse, InStockTest) {
		MockWarehouse mwh;
		const string ipod{ "ipod" };
		const int quantity{ 50 };
		Order order{ ipod, quantity };
		order.fill(&mwh);
		EXPECT_EQ(1, mwh.removeCalled);
		EXPECT_EQ(ipod, mwh.removeProduct);
		EXPECT_EQ(quantity, mwh.removeQuantity);
	}
	TEST(Warehouse, OutOfStockTest) {
		MockWarehouse mwh;
		const string ipod{ "ipod" };
		const int quantity{ 50 };
		Order order{ ipod, quantity };
		mwh.returnFromHasInventory = false;
		order.fill(&mwh);
		EXPECT_EQ(0, mwh.removeCalled);
	}
	struct MockEventBus: public IEventBus
	{
		bool asyncCalled = false, syncCalled = false;
		string product;
		int quantity;
		void PostAsync(const std::string& product, int quantity) override { 
			asyncCalled = true; 
			this->product = product;
			this->quantity = quantity;
		}
		void PostSync(const std::string& product, int quantity)  override { 
			syncCalled = true; 
			this->product = product;
			this->quantity = quantity;
		}
	};

	TEST(Warehouse, Events) {
		const string ipod{ "ipod" };
		const int quantity{ 50 };
		Order order{ ipod, quantity };
		MockEventBus meb;
		RealWarehouse realWarehouse(&meb);
		realWarehouse.addProduct(ipod, quantity + 1);
		order.fill(&realWarehouse);
		EXPECT_TRUE(meb.asyncCalled);
		EXPECT_FALSE(meb.syncCalled);
		EXPECT_EQ(ipod, meb.product);
		EXPECT_EQ(quantity, meb.quantity);
	}
	/*
	Write the following tests for class Order by mocking out Warehouse
	1) Testing In Stock:
	- Create an order for "ipod", 50 pieces
	- Pass warehouse to ensure that order can be fulfilled
	- Ensure that remove function was called of warehouse with right parameters ONCE only.
	2) Testing out of stock:
	- create an order for "ipod", 50 pieces
	- Pass warehouse to ensure that order cannot be fulfilled.
	- Ensure that remove function was NEVER called of warehouse
	3) Testing Events passed successfully
	- Create an order for "ipod", 50 pieces
	- Pass RealWarehouse object to ensure that order can be fulfilled
	- Mock out the Eventbus
	- Ensure that either async or sync function of Eventbus is called with right parameters.
	Write the above test by first creating mocks by hand and then using some framework to create the same.
	*/
}