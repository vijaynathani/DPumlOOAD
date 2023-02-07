#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class Date {
	//...
};
class Payment {
    Date paymentDate; //for FOC, the date the fee is waived.
    public:
        virtual int getNominalPayment() { return 0;}
        virtual ~Payment() {}
};
class FreeOfCharge : public Payment {
};
class RealPayment : public Payment {
    int actualPayment; 
    int discount; 
    public: 
    int getNominalPayment() override {
        return actualPayment+discount;
    }
};
class CashCardPayment : public RealPayment {
};
class BankPayment : public RealPayment {
    string bankName; 
    public:  string getBankName() { return bankName; }
}
class TelegraphicTransfer : public BankPayment {
};
class ChequePayment : public BankPayment {
    string chequeNumber; //if it is by cheque.
};
class CreditCardPayment : public BankPayment {    
    string creditCardType;
    string creditCardHolderName;
    string creditCardNumber;
    Date creditCardExpiryDate;
};
