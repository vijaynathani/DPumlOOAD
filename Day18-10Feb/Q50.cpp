const int SAVING=0;
const int CHEQUE=1;
const int FIXED=2;
class Account {
    int accountType;
    double balance;
	public: double getInterestRate(...) { // Some method;
        //...
		return 0;
    }
    Account(int accountType) {
        this->accountType=accountType;
    }
    double calcInterest() {
        switch (accountType) {
        case SAVING:
            return balance*getInterestRate();
        case CHEQUE:
            return 0;
        case FIXED:
            return balance*(getInterestRate()+0.02);
        }
    }
};
