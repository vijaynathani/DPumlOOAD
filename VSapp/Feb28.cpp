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