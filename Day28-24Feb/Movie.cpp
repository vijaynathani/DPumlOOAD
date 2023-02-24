#include <string>
#include <vector>
#include <sstream>

namespace d1Refactoring {

  class Movie {
    std::string *title_;
    int priceCode_;
    public: 
	static const int CHILDRENS = 2, REGULAR = 0, NEW_RELEASE = 1;
	Movie(std::string *title, int priceCode) {
        title_ = title;
        priceCode_ = priceCode;
    }
    int GetPriceCode() { return priceCode_; }
    void SetPriceCode(int arg) { priceCode_ = arg; }
	std::string *GetTitle() { return title_; }
  };

  class Rental {
    Movie *movie_;
    int daysRented_;
   public: 
	Rental(Movie *movie, int daysRented) {
        movie_ = movie;
        daysRented_ = daysRented;
    }
    int GetDaysRented() { return daysRented_; }
    Movie *GetMovie() { return movie_; }
  };

  class Customer {
	std::string *name_;
	std::vector<Rental *> rentals_; 

   public: 
	Customer(std::string *name) : name_ (name) {}
    void AddRental(Rental *arg) { rentals_.push_back(arg); }
	std::string *GetName() { return name_; }

	std::string *Statement() {
      double totalAmount = 0;
      int frequentRenterPoints = 0;
	  std::stringstream result;
	  result << "Rental Record for " << GetName() << "\n";

      for (std::vector<Rental *>::iterator each = rentals_.begin();
					  each != rentals_.end(); ++each) {
        double thisAmount = 0;

        // determine amounts for each line
        switch ( (*each)->GetMovie()->GetPriceCode()) {
		case Movie::REGULAR:
          thisAmount += 2;
          if ( (*each)->GetDaysRented() > 2) 
            thisAmount += ((*each)->GetDaysRented() - 2) * 1.5;
          break;
		case Movie::NEW_RELEASE:
          thisAmount += (*each)->GetDaysRented() * 3;
          break;
		case Movie::CHILDRENS:
          thisAmount += 1.5;
          if ((*each)->GetDaysRented() > 3) 
            thisAmount += ((*each)->GetDaysRented() - 3) * 1.5;
         }

         // add frequent renter points
         frequentRenterPoints++;

         // add bonus for a two day new release rental
         if (((*each)->GetMovie()->GetPriceCode() == Movie::NEW_RELEASE)
                    && (*each)->GetDaysRented() > 1)
                frequentRenterPoints++;

         // show figures for this rental
         result << "\t" << (*each)->GetMovie()->GetTitle()->c_str() << "\t"
                    << thisAmount << "\n";
         totalAmount += thisAmount;
        }

        // add footer lines
        result << "Amount owed is " << totalAmount << "\n"
        	<< "You earned " << frequentRenterPoints
            << " frequent renter points";
        return new std::string(result.str());
    }
  };
}
