#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
class RentalNotFoundException : public runtime_error {
	public: RentalNotFoundException(char *s1) : runtime_error(s1) {}
    //...
};
class BookRental {
    string *id;
    string *customerName;
    //...
	public: string *getId() { return id; }
	string *getCustomerName() { return customerName; }
};
class BookRentals {
    vector<BookRental *> rentals;
	public:
	string *getCustomerName(string &rentalId) {
        for (unsigned int i = 0; i < rentals.size(); i++) {
            BookRental *rental = rentals.at(i);
            if (rental->getId()->compare(rentalId) == 0) {
                return rental->getCustomerName();
            }
        }
        throw new RentalNotFoundException("");
    }
    void deleteRental(string &rentalId) {
		for (vector<BookRental *>::iterator p = rentals.begin();
				p != rentals.end(); ++p) {
            BookRental *rental = *p;
            if (rental->getId()->compare(rentalId)) {
                rentals.erase(p);
                return;
            }
        }
        throw new RentalNotFoundException("");
    }
};
