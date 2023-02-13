#include <string>
#include <stdexcept>
#include <vector>
namespace artist2 {
using namespace std;
class Artist {
    string *name;
public:
    Artist(string *name1) {
    	if (name1 == nullptr) throw logic_error("name needed");
        name = name1;
    }
    string *get_name() const { return name; }
};
class S28Artists {
    const vector<Artist *> &artists;
public:
    S28Artists(vector<Artist *> &artists1) : artists(artists1) {}

    Artist *get_artist(int index) {
        if ((index < 0) || (index >= artists.size()))
        	throw logic_error("invalid index");
        return artists[index];
    }
    string *get_artist_name(int index) {
        return get_artist(index)->get_name();
    }
    //Throw exception, instead of returning null.
};
}
//=========================================================
//The other option is to return Optional in C++17
//Example of Optional is below

#include <optional>
#include <iostream>

static std::optional<int> divide (int numerator, int denominator)
{
	if (denominator == 0) return {}; //Same is "return std::nullopt"
	return numerator / denominator; 
}
void OptionalDemo()
{
	auto o{ divide(1,0) };
	if (o.has_value())
		std::cout << o.value() << std::endl;
	else
		std::cout << "Division by zero" << std::endl;
}