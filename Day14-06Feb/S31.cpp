#include <iostream>
#include <string>
#include <exception>
using namespace std;
class Date {
	//...
};
class UserType;
class UserAccount {
	UserType *userType;
	string id;
	string name;
	string password;
	Date dateOfLastPasswdChange;
	public: UserType *getType() {
		return userType;
	}
	bool checkPassword(string &password) {
		bool r = false;
        //...
		return r;
    }
};
class UserType {
	int passwordMaxAgeInDays;
	bool allowedToPrintReport;
	public:
	UserType(int passwordMaxAgeInDays, bool allowedToPrintReport) {
		this->passwordMaxAgeInDays = passwordMaxAgeInDays;
		this->allowedToPrintReport = allowedToPrintReport;
	} 
	int getPasswordMaxAgeInDays() {
		return passwordMaxAgeInDays;
	} 
	bool canPrintReport() {
		return allowedToPrintReport;
	} 
	static const int PASSWORD_AGE_NORMAL = 90;
    static const int PASSWORD_AGE_ADMIN = 30;
};
UserType normalUserType(UserType::PASSWORD_AGE_NORMAL, true);
UserType adminUserType(UserType::PASSWORD_AGE_ADMIN, true);
UserType guestUserType(99999, false);

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
		//expiryDate.setTime(account.dateOfLastPasswdChange);
		//expiryDate.add(Calendar.DAY_OF_MONTH, passwordMaxAgeInDays);
		return expiryDate;
	}
	int getPasswordMaxAgeInDays(UserAccount &account) {
		return account.getType()->getPasswordMaxAgeInDays();
	}
	void printReport(UserAccount &currentUser) {
		bool canPrint;
		canPrint = currentUser.getType()->canPrintReport();
		if (!canPrint) {
			//throw new SecurityException("You have no right");
		}
		//print the report.
	}
};
