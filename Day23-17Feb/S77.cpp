#include <string>
namespace higher_order_soln {
using namespace std;
class Employee {
	typedef int (*leaves_permitted)(int);
    string name, address;
    long id, mobile;
    leaves_permitted number_of_holidays;
    //Assume getters,setters, toString and other common functions.
    Employee(leaves_permitted holidays) : number_of_holidays(holidays) {}
    	//Other initializations in private constructor not shown here.
public:
    static Employee *create_permanent_employee() {
    	return new Employee([](int month){return (month == 12)?4:3;});
    }
    static Employee *create_temporary_employee() {
    	return new Employee([](int month){return 2;});
    }
    int calculate_holidays_permitted(int month) { return leaves_permitted(); }
};
}
