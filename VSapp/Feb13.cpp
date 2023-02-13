#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <optional>

using namespace std;
namespace feb13 { //C++17, Java 8
	static std::optional<int> divide(int numerator, int denominator)
	{
		if (denominator == 0) return {}; //Same is "return std::nullopt"
		return numerator / denominator; //Auto wrap with optional
	}
	void OptionalDemo()
	{
		auto o{ divide(4, 0) };
		if (o.has_value())
			std::cout << o.value() << std::endl;
		else
			std::cout << "Division by zero" << std::endl;
	}
}
using namespace feb13;
void feb13Main() {
	OptionalDemo();
}