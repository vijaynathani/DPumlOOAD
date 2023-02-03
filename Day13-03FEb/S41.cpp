#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;
class Date { //...
};
class Session {
    Date date;
    int startHour;
    int endHour;
	public: int getDuration() {
        return endHour-startHour;
    }
};
class Course {
    string *courseTitle;
	public: Course(string &courseTitle) {
        //...
    }
    string *getTitle() {
        return courseTitle;
    }
    virtual double getFee() = 0;
    virtual double getDuration() = 0;
};
class SimpleCourse : public Course {
    vector<Session *> *sessions;
    double fee;
	public:
    SimpleCourse(string &courseTitle, 
			double fee, vector<Session> &sessions) 
		: Course(courseTitle) {
        //...
    }
    double getFee() {
        return fee;
    }
    double getDuration() {
        double duration=0;
        for (unsigned int i=0; i<sessions->size(); i++) {
            duration += sessions->at(i)->getDuration();
        }
        return duration;
    }
    void setFee(double fee) {
        this->fee = fee;
    }
};
class CompoundCourse : public Course { 
	vector<Course *> *modules;
	public:
    CompoundCourse(string &courseTitle, vector<Course> &modules) 
		: Course(courseTitle) {
        //...
    }
    double getFee() {
        double totalFee = 0;
        for (unsigned int i=0; i<modules->size(); i++) {
            totalFee += modules->at(i)->getFee();
        }
        return totalFee;
    }
    double getDuration() {
        double duration=0;
        for (unsigned int i=0; i<modules->size(); i++) {
            duration += modules->at(i)->getDuration();
        }
        return duration;
    }
};
