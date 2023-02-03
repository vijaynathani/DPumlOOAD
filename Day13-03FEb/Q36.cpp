#include <iostream>
#include <string>
using namespace std;
//Improve the code
class Currency {
	int currencyCode;
	public:
    const static int USD=0;
    const static int RMB=1; //Chinese currency
    const static int ESCUDO=2; //Portuguese currency
    Currency(int currencyCode) {
        this->currencyCode=currencyCode;
    }
    string *format(int amount) {
		string *r = 0;
        switch (currencyCode) {
        case USD:
            //Assign something like $1,200 to r
			break;
        case RMB:
            //Assign something like RMB1,200 to r
			break;
        case ESCUDO:
            //Assign something like $1.200 to r
			break;
        }
		return r;
    }
};
