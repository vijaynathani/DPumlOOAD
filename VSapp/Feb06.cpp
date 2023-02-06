#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
namespace feb06 {
	class MySet : public set<int> {
	public:	
		virtual void addNumber(int n) { 
			insert(n); 
		}
		virtual void addAllNumbers(vector<int>& numbers) {
			for (auto it = numbers.begin(); it != numbers.end(); it++)
				addNumber(*it);
		}
	};
	class ci1 : public MySet {
	public:	
		int addCount = 0;
		virtual void addNumber(int n) override {
			addCount++; MySet::addNumber(n);
		}
		virtual void addAllNumbers(vector<int>& numbers) override {
			addCount += numbers.size();
			MySet::addAllNumbers(numbers);
		 }
	};
}
using namespace feb06;
void MySetMain() {
	vector<int> numbers = { 1, 2, 3 };  ci1 s;
	s.addAllNumbers(numbers);
	cout << s.addCount << endl;
}

