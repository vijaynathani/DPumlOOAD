#include <iostream>
#include <string>
using namespace std;
/* This application is concerned with the training courses.
 * The schedule of a course can be expressed in three ways (as of now):
 *	weekly, range or list.
 * A weekly schedule is like "every Tuesday for 5 weeks starting
 *   from Oct. 22".
 * A range schedule is like "Every day from Oct. 22 to Nov. 3".
 * A list schedule is like "Oct. 22, Oct. 25, Nov. 3, Nov. 10".
 * In this exercise we will ignore the time and just assume that it is
 * always 7:00pm-10:00pm. It is expected that new ways to express the
 * schedule may be added in the future.
 * Point out and remove the code smells in the code
 */
class Date {
	//...
};
class Course {
	public:
    static const int WEEKLY=0;
    static const int RANGE=1;
    static const int LIST=2;
	private:
    int scheduleType; // WEEKLY, RANGE, or LIST
    string courseTitle;

    int noWeeks; // For WEEKLY.
    Date fromDate; // for WEEKLY and RANGE.
    Date toDate; // for RANGE.
    Date dateList[]; // for LIST.

    public:
    int getDurationInDays() {
		int r =0; //invalid duration
        switch (scheduleType) {
        case WEEKLY:
            r=noWeeks;
			break;
        case RANGE:
            int msInOneDay = 24*60*60*1000;
            r = (int)((toDate.getTime()-fromDate.getTime()) /
                            msInOneDay);
			break;
        case LIST:
            r=dateList.length;
			break;
        }
		return r;
    }
    void printSchedule() {
        switch (scheduleType) {
        case WEEKLY:
            //...
			break;
        case RANGE:
            //...
			break;
        case LIST:
            //...
			break;
        }
    }
};
