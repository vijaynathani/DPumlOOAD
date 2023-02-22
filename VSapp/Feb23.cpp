#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <random>
#include <cassert>
#include <unordered_set>
#include <algorithm>

using namespace std;
namespace feb23 {
	class Number {
		int number;
	public:
		Number(int n) { number = n; }
		bool isOdd() { return number % 2 == 1; }
	};
}
using namespace feb23;
#include <gtest/gtest.h>
#include <gmock/gmock.h>
TEST(NumberType, OddNumberPositive) { //The first parameter is test group, second the test name.
	Number n(5);
	EXPECT_TRUE(n.isOdd());
}
void feb23Main(int argc, char** argv) {
	testing::InitGoogleMock(&argc, argv);
	RUN_ALL_TESTS();
}
