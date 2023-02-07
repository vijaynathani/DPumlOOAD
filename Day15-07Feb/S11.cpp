#include <iostream>
#include <string>
using namespace std;

//There are two kinds of rentals i.e. Books and Movies. Improve the code
class Date { //...
	public: bool before(Date &d) { 
		bool r=false;
		//compare current date with the one passed. Update r.
		return r;
	}
};
class BookRental {
    string bookTitle;
    string author;
    Date rentDate;
    Date dueDate;
    double rentalFee;
	public: bool isOverdue() {
        Date now;
        return dueDate.before(now);
    }
    double getTotalFee() {
        return isOverdue() ? 1.2*rentalFee : rentalFee;
    }
};
class MovieRental {
    string movieTitle;
    int classification;
    Date rentDate;
    Date dueDate;
    double rentalFee;
	public: bool isOverdue() {
        Date now;
        return dueDate.before(now);
    }
    double getTotalFee() {
        return isOverdue() ? 1.3*rentalFee : rentalFee;
    }
};
