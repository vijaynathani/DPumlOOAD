#include <iostream>
#include <map>
#include <string>
using namespace std;
class Course { //...
	public: string *getTitle() { return 0; }
};

//Point out and remove the problem in code below.
class CourseCatalog : public map<string *,Course *> {
	public: void addCourse(Course *c) {
        insert(make_pair(c->getTitle(), c));
    }
    Course *findCourse(string *title) {
        return find(title)->second;
    }
    int countCourses() {
        return size();
    }
};
