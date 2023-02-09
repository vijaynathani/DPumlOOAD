include <iostream>
#include <string>
#include <vector>
using namespace std;
class Account { //...
};
class Date { 
	public: Date(int year, int month, int day, int hour, int min, int sec);
	//...
};

//improve code

//the string "Rest" is concated with the restaurant ID to
//form the key.
const static string RestaurantIDText("Rest");
class Restaurant : public Account {
	
    string website;

    string addr_cn; //address in Chinese.
    string addr_en; //address in English.

    //the restaurant would like to update its fax # with this. After it is
    //confirmed, it will be stored in Account. Before that, it is stored
    //here.
    string numb_newfax;
    bool has_NewFax;

    //a list of holidays.
    vector<Date *> Holiday; 

    //id of the category this restaurant belongs to.
    string catId;

    //a list of business session. Each business session is an array
    //of two times. The first time is the start time. The second time
    //is the end time. The restaurant is open for business in each
    //session.
    vector<Date *> BsHour; //Business hour


	public: Restaurant() { 
		has_NewFax = false;
	}
    //...
    //y: year.
    //m: month.
    //d: date.
    void addHoliday(int y,int m,int d){
        if(y<1900) y+=1900;
        Date *aHoliday = new Date(y,m,d,0,0,0);
        Holiday.push_back(aHoliday);
    }

    bool addBsHour(int fromHr, int fromMin, int toHr, int toMin){
        int fMin = fromHr*60 + fromMin; //start time in minutes.
        int tMin = toHr*60 + toMin; //end time in minutes.
        //make sure both times are valid and the start time is earlier
        //than the end time.
        if(fMin >= 0 && fMin <= 1440 && tMin >= 0 && 
                tMin <=1440 && fMin < tMin){
            Date *bs[2];
			bs[0]=new Date(1900,1,1, fromHr, fromMin,0);
			bs[1]=new Date(1900,1,1, toHr, toMin,0);
            BsHour.push_back(bs[0]);
            BsHour.push_back(bs[1]);
            return true;
        } else {
            return false;
        }
    }
};
