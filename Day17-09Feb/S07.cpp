#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Account { //...
};
class Date { 
	public: Date(int year, int month, int day, int hour, int min, int sec);
	//...
};
const static string RestaurantIDText = "Rest";
class Restaurant : public Account {
    class TimeRange {
        int fromHour, toHour, fromMinutes, toMinutes;
		public: TimeRange(int fromHour, int toHour,
            int fromMinutes, int toMinutes) {
            //...
        }
    };
    string website;
    string chineseAddress;
    string englishAddress;
    string newFaxNumberToBeConfirmed;
    bool has_NewFax;
    vector<Date *> listOfHolidays;
    string catId;
    vector<TimeRange *> BusinessHours;
    //...
    static const int BASE_YEAR=1900,
        HOURS_IN_A_DAY=24, MINUTES_IN_AN_HOUR=60;
	public: Restaurant() { 
		has_NewFax = false;
	}
    void addHoliday(int year,int month,int day){
        if(year<BASE_YEAR) year+=BASE_YEAR;
        Date *aHoliday = new Date(year,month,day,0,0,0);
        listOfHolidays.push_back(aHoliday);
    }
    int getMinutesFromMidnight(int hours, int minutes) {
        return hours * MINUTES_IN_AN_HOUR + minutes;
    }
    bool isMinutesWithinOneDay(int minutes) {
        return (minutes >= 0) &&
            (minutes <= HOURS_IN_A_DAY * MINUTES_IN_AN_HOUR );
    }
    bool addBsHour(int fromHour, int fromMinute,
            int toHour, int toMinute){
        int fromInMinutes = getMinutesFromMidnight(fromHour, fromMinute);
        int toInMinutes = getMinutesFromMidnight(toHour,toMinute);
        bool timesValid = isMinutesWithinOneDay(fromInMinutes) &&
                            isMinutesWithinOneDay(toInMinutes) &&
                            fromInMinutes < toInMinutes;
        if (timesValid)
            BusinessHours.push_back(new TimeRange(fromHour,fromMinute,toHour,toMinute));
        return timesValid;
    }
};
