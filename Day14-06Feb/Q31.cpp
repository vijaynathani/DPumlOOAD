#include <iostream>
#include <string>
#include <exception>
using namespace std;
//Improve the code
class Date {
	//...
};
class UserAccount { public:
    const static int USERTYPE_NORMAL = 0;
    const static int USERTYPE_ADMIN  = 1;
    const static int USERTYPE_GUEST  = 2;
	private: int userType;

    string id;
    string name;
    string password;
    Date dateOfLastPasswdChange;
	public: bool checkPassword(string &password) {
		bool r = false;
        //...
		return r;
    }
	int getType() { return userType; }
};
class InventoryApp {
    void login(UserAccount &userLoggingIn, string &password) {
        if (userLoggingIn.checkPassword(password)) {
            Date *today = new Date();
            Date *expiryDate = getAccountExpiryDate(userLoggingIn);
            //if (today.after(expiryDate)) {
				//prompt the user to change password
				//...
            //}
        }
    }

    Date *getAccountExpiryDate(UserAccount &account) {
        int passwordMaxAgeInDays = getPasswordMaxAgeInDays(account);
        Date *expiryDate = new Date();
        //expiryDate->setTime(account.dateOfLastPasswdChange);
        //expiryDate->add(Calendar.DAY_OF_MONTH, passwordMaxAgeInDays);
        return expiryDate;
    }

    int getPasswordMaxAgeInDays(UserAccount &account) {
        switch (account.getType()) {
		case UserAccount::USERTYPE_NORMAL:
            return 90;
		case UserAccount::USERTYPE_ADMIN:
            return 30;
		case UserAccount::USERTYPE_GUEST:
            return 999999; // Integer.MAX_VALUE;
        }
    }

    void printReport(UserAccount &currentUser) {
        bool canPrint;
        switch (currentUser.getType()) {
		case UserAccount::USERTYPE_NORMAL:
            canPrint = true;
            break;
		case UserAccount::USERTYPE_ADMIN:
            canPrint = true;
            break;
		case UserAccount::USERTYPE_GUEST:
            canPrint = false;
        }
        if (!canPrint) {
            throw new Exception("You have no right");
        } 
		//print the report.
    }
};

