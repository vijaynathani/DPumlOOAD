#include <string>
#include <vector>
using namespace std;
class Reader { //...
};
class BufferedReader : public Reader { //..
	public: BufferedReader(Reader &r);
};
//Improve the code
class TokenStream {
    vector<string *> *v; //a list of tokens parsed from br.
    int index; //index of the current token in v.
    BufferedReader *br; //read the chars from here to parse the tokens.
    int currentChar; //previous char read from br.
    //read the chars from the reader and parse the tokens.
	public:
    //read the chars from br, parse the tokens and store them into an List
    vector<string *> *parseFile() {
        vector<string *> *v; //accumulate the tokens that have been parsed.
        //...
        return v;
    }
	void takeChar() { //...
	}
    TokenStream(Reader &read) {
        br = new BufferedReader(read);
        takeChar();
        v = parseFile();
        index=0;
    }
    //...
};
