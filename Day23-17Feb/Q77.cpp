#include <string>
namespace higher_order {
using namespace std;
class Employee {
    string name, address;
    long id, mobile;
    //Assume public constructor, getters,setters, toString and other common functions.
public:
    virtual int calculate_holidays_permitted(int month) = 0;
};

class Permanent_employee : public Employee {
public:
    int calculate_holidays_permitted(int month) override {
        return (month == 12)?4:3;
    }
};

class Temporary_employee : public  Employee {
public:
    int calculate_holidays_permitted(int month) override {
        return 2;
    }
};
}
//Replace simple hierarchy with Higher-order functions
