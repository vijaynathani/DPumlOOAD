#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Board {
    //...
    class Piece {
       string representation; 
		public : 
		string get_first_char() {
			return representation.substr(0, 1);
		}	
    };
	class Location {
		Piece *current;
		public : 
		string get_first_char_of_piece() {
			return current->get_first_char();
		}
	};
	string boardRepresentation() {
		vector<Location *> squares;
		//... initialize squares
		string buf;
		for(unsigned int i=0; i<squares.size(); ++i) 
			buf+=squares.at(i)->get_first_char_of_piece();
		return buf;
	}
};
