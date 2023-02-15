#include <iostream>

class PersonalLoanValidator {
	public: 
	bool isValid() {
        //Validation logic
		return false;
    }
	//...
};
class VehicleLoanValidator {
	public: 
	bool isValid() {
        //Validation logic
		return false;
    }
	//...
};
//Suppose you are writing a module to approve personal loans and 
//before doing that you want to validate the personal information.
//Later on, its required to approve vehicle loans, consumer goods loans 
//and what not. 
class LoanApprovalHandler {
    public:
	void approvePersonalLoan(PersonalLoanValidator *validator) {
        if (validator->isValid()) {
            //Process the loan.
        }
    }
    void approveVehicleLoan(VehicleLoanValidator *validator) {
        if (validator->isValid()) {
            //Process the loan.
        }
    }
    // Methods for approving other loans.
};
//Improve above code
