#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <random>
#include <cassert>
using namespace std;
namespace feb07 {
	void myAssert(bool condition) {
		if (condition) return;
		cerr << "Failed" << endl;
		exit(1);
	}
	string generateRandomString(int size) {
		myAssert(size > 0);
		random_device rnd;
		assert(rnd.min() == 0 && rnd.max() > 1000);
		string r;
		for (int i = 0; i < size; i++)
			r += 'a' + rnd() % 26;
		assert(r.length() == size);
		return r;
	}
	double computeAreaOfCircle(double radius) {
		if (radius < 0)
			throw runtime_error("radius -ve");
		const double PI = 22 / 7.0;
		assert(PI > 3 && PI < 4);
		auto area = PI * radius * radius;
		assert(area > 0); //Post-condition
		return area;
	}

}
using namespace feb07;
void feb07Main() {
	//cout << computeAreaOfCircle(2) << endl;
	cout << generateRandomString(10) << endl;
}