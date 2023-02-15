#include <iostream>

class IValidator {
	public:
	virtual bool isValid() = 0;
	virtual ~IValidator() {}
};

class PersonalLoanValidator : public IValidator {
	public: 
	bool isValid() {
        //Validation logic
		return false;
    }
	//...
};

class VehicleLoanValidator : public IValidator {
	public: 
	bool isValid() {
        //Validation logic
		return false;
    }
	//...
};

class LoanApprovalHandler {
    public:
	void approveLoan(IValidator *validator) {
        if (validator->isValid()) {
            //Process the loan.
        }
    }
    //...
};
