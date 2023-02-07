#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BookRental { //...
	public: bool isOverdue();
	string toString();
};

class BookRentals {
	class RentalProcessor {
		public: virtual void process(BookRental *rental) = 0;
	};
	class PrintingRentals : public RentalProcessor {
		public: void process(BookRental *rental) {
				cout << rental->toString();
		}
	};
	class CountRentals : public RentalProcessor {
		public: int count;
		CountRentals() { count= 0; };
		void process(BookRental *rental) {
			count++;
		}
	};
	vector<BookRental *> rentals;
	//...
	int countRentals() {
		return rentals.size();
	}
	BookRental *getRentalAt(int i) {
		return rentals.at(i);
	}
	void processOverdueRentals(RentalProcessor *processor) {
		for (int i=0; i<countRentals(); i++) {
			BookRental *rental = getRentalAt(i);
			if (rental->isOverdue()  &&
				  ... //A complex condition
			   )
				processor->process(rental);
		}
	}
	public:
	void printOverdueRentals() {
		PrintingRentals p;
		processOverdueRentals(&p);
	}
	int countOverdueRentals() {
		CountRentals cr;
		processOverdueRentals(&cr);
		return cr.count;
	}
};
