#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Board {
    //...
    class Piece {
        //...
		public : string representation;
    };
	class Location {
		//...
		public : Piece *current;
	};
	string boardRepresentation() {
		vector<Location *> squares;
		//... initialize squares
		string buf;
		for(unsigned int i=0; i<squares.size(); ++i) 
			buf+=squares.at(i)->current->representation.substr(0, 1);
		return buf;
	}
};
