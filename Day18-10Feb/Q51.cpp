#include <string>
using namespace std;
const int Account =0;
const int Marketing = 1;
const int CustomerServices = 2;
class Department{
	protected: int departmentCode;
	public: Department(int departmentCode){
        this->departmentCode = departmentCode;
    }
    string getDepartmentName(){
        switch (departmentCode){
        case Account:
            return "Account";
        case Marketing:
            return "Marketing";
        case CustomerServices:
            return "Customer Services";
        }
    }
};
