#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
/* This application is about students. Originally we had a 
 * simple Student class:
 * class Student { string studentId; string name; Date dateOfBirth; }
 *
 * Later, in order to record what courses the student has 
 * enrolled in, on which dates he enrolled and how he paid for them, 
 * we modified the code as shown below.
 * Your task is to implement this requirement without modifying 
 * the Student class.
 */
class Student;
class StudentManagementSystem {
    vector<Student> students;
};
class Payment {
	//...
};
class Date {
	// has day, month & year
};
class Student {
    string studentId;
    string name;
    Date dateOfBirth;
    vector<string> courseCodes; //the student has enrolled in these courses.
    vector<Date> enrollDates; //for each enrolled course, the date he enrolled.
    vector<Payment> payments; //for each enrolled course, how he paid.
    void enroll(string &courseCode, 
			Date &enrollDate, Payment &payment) {
        //add courseCode to courseCodes
        //add enrollDate to enrollDates
        //add payment to Payments
    }
    void unenroll(string &courseCode) {
        //...
    }
	//...
};
