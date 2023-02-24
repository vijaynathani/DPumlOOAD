#include <string>
#include <vector>
#include <sstream>
#include <numeric>

namespace d1RefactoringSoln {

	class Movie {
		std::string* const title_;
	public:
		explicit Movie(std::string *title) : title_ (title) { }
		std::string *GetTitle() const { return title_; }
		virtual double AmountCharged(int daysRented) = 0;
		virtual int FrequentRenterPoints(int daysRented) { return 1;  }
		virtual ~Movie() {}
	};
	class ChildrenMovie : public Movie
	{
	public:
		//explicit ChildrenMovie(std::string* title) : Movie(title){}
		using Movie::Movie; //Same as above since C+11
		double AmountCharged(int daysRented) override {
			return 1.5 + (daysRented > 3)? ((daysRented - 3) * 1.5 ) : 0;
		}
	};
	class RegularMovie : public Movie
	{
	public:
		using Movie::Movie;
		double AmountCharged(int daysRented) override {
			return 2.0 + (daysRented > 2) ? ((daysRented - 2) * 1.5) : 0;
		}
	};
	class NewReleaseMovie : public Movie
	{
	public:
		using Movie::Movie;
		int FrequentRenterPoints(int daysRented) override { 
			auto original = Movie::FrequentRenterPoints(daysRented);
			return (daysRented > 1) ? original + 1 : original;
		}
		double AmountCharged(int daysRented) override {
			return daysRented  * 3.0;
		}
	};

	class Rental {
		Movie * const movie_;
		const int daysRented_;
	public:
		Rental(Movie *movie, int daysRented) :
			movie_{ movie }, daysRented_{daysRented} {}
		int FrequentRenterPoints() const { return movie_->FrequentRenterPoints(daysRented_); }
		double AmountCharged() const { return movie_->FrequentRenterPoints(daysRented_); }
		Movie *GetMovie() const { return movie_; }
	};

	class Customer {
		std::string *name_;
		std::vector<Rental *> rentals_;

		double TotalAmount() const {
			//double r = 0;
			//for (auto each = rentals_.begin(); each != rentals_.end(); ++each)
			//	r += (*each)->AmountCharged();
			//return r;
			return std::accumulate(rentals_.cbegin(), rentals_.cend(), 0, 
				[](int acc, const Rental* each) { return acc + each->AmountCharged(); });

		}
		int FrequentRenterPoints() const {
			//auto r = 0;
			//for (auto each = rentals_.begin(); each != rentals_.end(); ++each)
			//	r += (*each)->FrequentRenterPoints();
			//return r;
			return std::accumulate(rentals_.cbegin(), rentals_.cend(), 0,
				[](int acc, const Rental* each) { return acc + each->FrequentRenterPoints(); });
		}
	public:
		explicit Customer(std::string *name) : name_(name) {}
		void AddRental(Rental *arg) { rentals_.push_back(arg); }
		std::string *GetName() const { return name_; }
		std::string Statement() const {
			std::ostringstream result("Rental Record for ");
			result <<  GetName() << "\n";
			for (const auto &each :rentals_) 
				result << "\t" << *each->GetMovie()->GetTitle()->c_str() << "\t" << each->AmountCharged() << "\n";
			result << "Amount owed is " << TotalAmount() << "\n"
				<< "You earned " << FrequentRenterPoints() << " frequent renter points";
			return result.str();
		}
	};
}
