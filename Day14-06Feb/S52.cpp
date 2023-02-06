const static double TAX_RATE = 0.1;
class Payment {
    int units;
    double rate;
	public: virtual double getPreTaxedAmount() = 0;
    virtual double getTaxRate() = 0;
    double getBillableAmount() {
        return getPreTaxedAmount() * (1 + getTaxRate());
    }
    double getNormalAmount() {
        return units * rate;
    }
};
class NormalPayment : public Payment {
	public: double getPreTaxedAmount() {
        return getNormalAmount();
    }
    double getTaxRate() {
        return TAX_RATE;
    }
};
class PaymentForSeniorCitizen : public Payment {
	public: double getPreTaxedAmount() {
        return getNormalAmount()*0.8;
    }
    double getTaxRate() {
        return TAX_RATE - 0.05;
    }
};
