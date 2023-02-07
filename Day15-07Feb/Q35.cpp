#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BookRental { //...
	public: bool isOverdue();
	string toString();
};
//Improve the code
class BookRentals {
    vector<BookRental *> rentals;
	//...
    int countRentals() {
        return rentals.size();
    }
    BookRental *getRentalAt(int i) {
        return rentals.at(i);
    }
	public:
    void printOverdueRentals() {
        int i;
        for (i=0; i<countRentals(); i++) {
            BookRental *rental = getRentalAt(i);
            if (rental->isOverdue()  &&
                       ... //Complex condition
               )
             cout << rental->toString();
        }
    }
    int countOverdueRentals() {
        int i, count;
        count=0;
        for (i=0; i<countRentals(); i++)
            if (getRentalAt(i)->isOverdue()  &&
                       ... //Same complex condition
               )
				count++;
        return count;
    }
};
