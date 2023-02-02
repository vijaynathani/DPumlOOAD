#include <iostream>
#include <vector>
using namespace std;
class Payment {
	//...
};
class Date {
	// has day, month & year
};
class Enrollment {
    Student *s;
    string couseCode;
    Date enrollDate;
    Payment payment;
};
class Student {
    string studentId;
    string name;
    Date dateOfBirth;
	//...
};
class Enrollments {
    vector<Enrollment *> enrollments;
public:
    void enroll(string &courseCode, 
			Date &enrollDate, Payment &payment) {
    }
    void unenroll(string &courseCode) {
        //...
    }
};
class StudentManagementSystem {
    Enrollments admissions;
    vector<Students *> students;
};
