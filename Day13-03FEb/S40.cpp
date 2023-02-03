#include <iostream>
#include <string>
using namespace std;
class Date {
	//...
};
class Schedule {
public:
    virtual int getDurationInDays() = 0;
    virutal void print() = 0;
};
class WeeklySchedule : public Schedule {
    int noWeeks; 
    Date fromDate; 
public:
    int getDurationInDays() { return noWeeks; }
    void print() { }
};
class RangeSchedule : public Schedule {
    Date fromDate; 
    Date toDate; 
public:
    int getDurationInDays() { 
        int msInOneDay = 24*60*60*1000;
        return (int)((toDate.getTime()-fromDate.getTime()) / msInOneDay);
    }
    void print() { }
};
class ListSchedule : public Schedule {
    vector<Date> dateList;
public:
    int getDurationInDays() { return dateList.size(); }
    void print() { }
};
class Course {
	public:
    string courseTitle;
    Schedule *sch;

    public:
    int getDurationInDays() { return sch->getDurationInDays(); }
    void printSchedule() { sch->print(); }
};
