#include <set>
#include <math.h>
#include <iostream>
#include <stdexcept>
using namespace std;
/*
 * The goal is to classify numbers. A number is perfect, if the sum 
 * of its factors equals the number e.g. 6 is perfect. 
 * The factors are 1, 2, 3. 1 + 2 + 3 equals 6. 
 * A number is abundant, if the sum of its factors is greater than
 * the number e.g. 12 is abundant. The factors are 1, 2, 3, 4 and 6. 
 * 1+2+3+4+6 is greater than 12.
 * A number is deficient, if the sum of its factors is less
 * than the number e.g. 10 is deficient. The factors are 1, 2, 5. 
 * 1+2+5 is less than 10.
 */
class NumberClassifier {
    set<int> _factors;
    int _number;
    bool isFactor(int factor) {
        return (_number % factor) == 0;
    }
    void calculateFactors() {
        for (int i = 2; i <= sqrt(_number); i++)
            if (isFactor(i))
                addFactor(i);
    }
    void addFactor(int factor) {
        _factors.insert(factor);
        _factors.insert(_number / factor);
    }
    int sumOfFactors() {
        calculateFactors();
        int sum = 0;
		for (set<int>::const_iterator p = _factors.begin();
						p != _factors.end();
						++p )
			sum += *p;
        return sum;
    }
	public: 
	NumberClassifier(int number) {
        if (number < 1)
            throw new runtime_error(
                    "Can't classify negative numbers");
        _number = number;
        _factors.insert(1);
    }
    set<int> getFactors() {
        return _factors;
    }
    bool isPerfect() {
        return sumOfFactors() == _number;
    }
    bool isAbundant() {
        return sumOfFactors() > _number;
    }
    bool isDeficient() {
        return sumOfFactors() < _number;
    }
    static bool isPerfect(int number) {
        return NumberClassifier(number).isPerfect();
    }
};
