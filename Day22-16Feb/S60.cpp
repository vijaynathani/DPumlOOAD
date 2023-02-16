#include <set>
#include <math.h>
#include <iostream>
#include <stdexcept>
using namespace std;
class NumberClassifier {
    static bool isFactor(int number, int potential_factor) {
        return (number % potential_factor) == 0;
    }
    static void add_factors(set<int> *factors, int number) {
		factors->insert(1);
        for (int i = 2; i <= sqrt(number); i++)
            if (isFactor(number,i)) {
                factors->insert(i);
                factors->insert(number/i);
			}
    }
    static int sum_of_factors(int number) {
		set<int> factors;
		add_factors(&factors, number);
        int sum = 0;
		for (set<int>::const_iterator p = factors.begin();
						p != factors.end();
						++p )
			sum += *p;
        return sum;
    }
	public: 
    static bool isPerfect(int number) {
        return sum_of_factors(number) == number;
    }
    static bool isAbundant(int number) {
        return sum_of_factors(number) > number;
    }
    static bool isDeficient(int number) {
        return sum_of_factors(number) < number;
    }
};
