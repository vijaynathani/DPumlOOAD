#include <iostream>
#include <string>
using namespace std;
class Currency {
    public:
        virtual string *format() = 0;
};
class USD : public Currency {
    public:
        string *format() {
            //Return something like $1,200 
        }
};
class RMB : public Currency {
    public:
        string *format() {
            //Return something like RMB1,200
        }
};
class ESCUDO : public Currency {
    public:
        string *format() {
            //Return something like $1.200
        }
};
