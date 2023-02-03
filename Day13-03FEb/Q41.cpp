#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;
/* This application is concerned with training courses.
 * A course has a title, a fee and a list of sessions. However,
 * sometimes a course can consist of several modules, each of which is a
 * course. For example, there may be a compound course "Fast track to
 * becoming a web developer" which consists of three modules: a course
 * named "HTML", a course named "FrontPage" and a course named "Flash".
 * It is possible for a module to consist of some other modules.
 * If a course consists of modules, its fee and schedule are totally
 * determined by that of its modules and thus it will not maintain
 * its list of sessions.
 * Point out and remove the code smells in the code */
class Date {
	//...
};
class Session {
    Date date;
    int startHour;
    int endHour;
	public:
    int getDuration() {
        return endHour-startHour;
    }
};
class Course {
    string courseTitle;
    vector<Session> *sessions;
    double fee;
    vector<Course> *modules;
    Course(string &courseTitle, double fee, vector<Session> &sessions) {
        //...
    }
    Course(string &courseTitle, vector<Course> &modules) {
        //...
    }
    string *getTitle() {
        return &courseTitle;
    }
    double getDuration() {
        double duration=0;
        if (modules==0)
            for (unsigned int i=0; i<sessions->size(); i++)
                duration += sessions->at(i).getDuration();
        else
            for (unsigned int i=0; i<modules->size(); i++)
                duration += modules->at(i).getDuration();
        return duration;
    }
    double getFee() {
        if (modules==0)
            return fee;
        else {
            double totalFee = 0;
            for (unsigned int i=0; i<modules->size(); i++)
                totalFee += modules->at(i).getFee();
            return totalFee;
        }
    }
    void setFee(int fee) {
		if (modules==0)
			this->fee = fee;
		else
			throw new Exception(
					"Please set the fee of each module one by one");
    }
};
