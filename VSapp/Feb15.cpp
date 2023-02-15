#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <random>
#include <cassert>
using namespace std;
namespace feb15 {
	class Rectangle {
		double width, height;
	public: 
		double getArea() {
			return width * height;
		}
	};
	class ShapeManager {
		Rectangle r;
		void func1() {
			auto area = r.getArea();
			
		}
	};
}
using namespace feb15;
void feb15Main() {
}