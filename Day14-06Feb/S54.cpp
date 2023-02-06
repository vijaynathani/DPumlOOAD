
#include <iostream>
using namespace std;
class Date { //...
	public: bool before(Date *other) { //...
		return false;
	}
};
class Account {
	public: virtual bool canLogin() = 0;
};
class UserAccount : public Account {
	Date *expiredDate;
	public:
	bool canLogin() {
		return isAccountExpired();
	} 
	bool isAccountExpired() {
		Date *now = new Date();
		return !expiredDate->before(now);
	}
};
class AdminAccount : public Account {
	bool hasLogin;
	public:
	bool canLogin() {
		return !isTryingMultiLogin();
	} 
	bool isTryingMultiLogin() {
		return hasLogin;
	}
};
class ERPApp {
	public: bool checkLoginIssue(Account *account) {
		return account->canLogin();
	}
};

