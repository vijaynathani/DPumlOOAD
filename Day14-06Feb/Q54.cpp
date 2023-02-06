#include <iostream>
using namespace std;
static const int LEVEL_USER = 1;
static const int LEVEL_ADMIN = 2;
class Date { //...
	public: bool before(Date *other) { //...
		return false;
	}
};
//Improve the code
class Account {
    int accountLevel;
    Date *expiredDate; // for user account only
    public: bool hasLogin; // for admin account only
	int getLevel() { return accountLevel; }
	Date *getExpiredDate() { return expiredDate; }
	//...
};
class ERPApp {
	public: bool checkLoginIssue(Account *account) {
        if (account->getLevel() == LEVEL_USER) {
            // Check the account expired date
            Date *now = new Date();
            if (account->getExpiredDate()->before(now))
                return false;
            return true;
        } else if (account->getLevel() == LEVEL_ADMIN) {
            // No expired date for admin account
            // Check multilogin
            if (account->hasLogin)
                return false;
            return true;
        }
        return false;
    }
};
