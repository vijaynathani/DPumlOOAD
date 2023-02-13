#include <string>
#include <stdexcept>
#include <vector>
namespace artist1 {
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
class Q28Artists {
    const vector<Artist *> &artists;
public:
    Q28Artists(vector<Artist *> &artists1) : artists(artists1) {}

    Artist *get_artist(int index) {
        if ((index < 0) || (index >= artists.size()))
        	return nullptr;
        return artists[index];
    }

    string *get_artist_name(int index) {
        try {
            return get_artist(index)->get_name();
        } catch (exception &e) {
            return nullptr;
        }
    }
    //Improve the design of this class
};
}
