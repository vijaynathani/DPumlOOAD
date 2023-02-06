#include <iostream>
#include <map>
#include <string>
using namespace std;
class Course { //...
	public: string *getTitle() { return 0; }
};

//Use delegation instead of inheritance
class CourseCatalog {
	map<string *, Course *> allCourses;
	//..
	public: void addCourse(Course *c) {
        allCourses.insert(make_pair(c->getTitle(), c));
    }
    Course *findCourse(string *title) {
        return allCourses.find(title)->second;
    }
    int countCourses() {
        return allCourses.size();
    }
};
