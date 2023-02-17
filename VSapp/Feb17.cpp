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
namespace feb17 {
	class B1 { //...
		char* mesg;
		B1(const char* message) : mesg{ message } { }
	public:
		virtual void process() { cout << mesg; }
		static B1* CreateD1() { return new B1("hello"); }
		static B1* CreateD2() { return new B1("world"); }
	};
	/*
	class D1 : public B1 {
	public:
		void process() override { cout << "hello"; }
	};
	class D2 : public B1 {
	public:
		void process() override { cout << "world"; }
	};*/

}
using namespace feb17;
void feb17Main() {
	B1* d1 = B1::CreateD1();
}