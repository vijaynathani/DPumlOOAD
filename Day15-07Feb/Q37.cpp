#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
//Improve the code
static const string FOC = "FOC"; //free of charge.
static const string TT = "TT"; //paid by telegraphic transfer.
static const string CHEQUE = "Cheque"; //paid by cheque.
static const string CREDIT_CARD = "CreditCard"; //paid by credit card.
static const string CASH = "Cash"; //paid by cash.
class Date {
	//...
};
class Payment {
    //type of payment. Must be one of the above constant.
    string paymentType;

    Date paymentDate; //if FOC, the date the fee is waived.
    int actualPayment; //if FOC, it is 0.
    int discount; //if FOC, the amount that is waived.
    string bankName; //if it is by TT, cheque or credit card.
    string chequeNumber; //if it is by cheque.

    //if it is by credit card.
    string creditCardType;
    string creditCardHolderName;
    string creditCardNumber;
    Date creditCardExpiryDate;

    int getNominalPayment() {
        return actualPayment+discount;
    }

    string getBankName() {
        if (paymentType.compare(TT) || paymentType.compare(CHEQUE) ||
            paymentType.compare(CREDIT_CARD)) {
            return bankName;
        }
        else
            throw runtime_error(
                "bank name is undefined for this payment type");
    }
};
