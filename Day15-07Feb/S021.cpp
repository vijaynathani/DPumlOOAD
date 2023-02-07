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
    int getRentalId(string &rentalId) {
        for (unsigned int i = 0; i < rentals.size(); i++) {
            BookRental *rental = rentals.at(i);
            if (rental->getId()->compare(rentalId) == 0) 
                return i;
        }
        throw new RentalNotFoundException("");
    }
	public:
	string *getCustomerName(string &rentalId) {
        return rentals.at(getRentalId(rentalId))->getCustomerName();
    }
    void deleteRental(string &rentalId) {
        rentals.erase(rentals.begin() + getRentalId(rentalId));
    }
};
