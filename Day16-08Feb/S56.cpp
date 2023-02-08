#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Date { //...
};
class Calendar { //...
};
class Restaurant {
    string name;
    string password;
    string telNo;
    string faxNo;
    string address;
	public: string getName();
	void setFaxNo(string &faxNo);
};
class RestaurantTaskActivator {
    string verificationCode;
    Restaurant *restaurant;
	public:
    bool tryToActivate(string &restName, string &verificationCode) {
        if (restName.compare(restaurant->getName()) &&
            this->verificationCode.compare(verificationCode)) {
            doSomethingToRestaurant();
            return true;
        }
        return false;
    }
    virtual void doSomethingToRestaurant() = 0;
	virtual ~RestaurantTaskActivator(){}
	Restaurant *getRestaurant() { return restaurant; };
};
class RestaurantActivator : public RestaurantTaskActivator {
    void doSomethingToRestaurant() {
        //add restaurant to the system;
    }
};
class FaxNoActivator : public RestaurantTaskActivator {
    string newFaxNo;
    void doSomethingToRestaurant() {
        getRestaurant()->setFaxNo(newFaxNo);
    }
};
class RestaurantTaskActivators {
    vector<RestaurantTaskActivator *> activators;
    void activate(string restName, string verificationCode) {
        for (unsigned int i = 0; i < activators.size(); i++) {
            if (activators[i]->tryToActivate(restName, verificationCode)) {
                //remove activator[i] from activators;
                return;
            }
        }
    }
};
class Category {
    string catId;
	//..
};
class Holidays {
    vector<Date *> holidays;
    void addHoliday(int year, int month, int day) {
        //...
    }
    void removeHoliday(int year, int month, int day) {
        //...
    }
    vector<Date *> *getAllHolidays() {
        return &holidays;
    }
};
class BusinessSessions {
    vector<Calendar *> businessSessions;
    bool addBusinessSession(int fromHour, int fromMin,
        int toHour, int toMin) {
        //...
    }
    bool isInBusinessHour(Calendar time) {
        //...
    }
    vector<Calendar *> *getAllBusinessSessions() {
        return &businessSessions;
    }
};
class RestaurantSystem {
    vector<Restaurant *> restaurants;
    RestaurantTaskActivators restaurantTaskActivators;
    map<Restaurant *,vector<Category *> *> mapRestIdToCatagories;
    map<Restaurant *,Holidays *> mapRestIdToHolidays;
    map<Restaurant *,BusinessSessions *> mapRestIdToBusinessSessions;
};

