#include <string>
#include <vector>
using namespace std;
class Reader { //...
};
class BufferedReader : public Reader { //..
	public: BufferedReader(Reader &r);
};
class TokenStream {
    vector<string *> *parsedTokenList;
    int currentTokenIdxInList;
    BufferedReader *charInputSourceForParsing;
    int previousCharReadFromSource;
    vector<string *> *parseTokensFromInputSource() {
        vector<string *> *tokensParsedSoFar;
        //...
        return tokensParsedSoFar;
    }
	void takeChar() { //...
	}
	public:
    TokenStream(Reader &reader) {
        charInputSourceForParsing = new BufferedReader(reader);
        takeChar();
        parsedTokenList = parseTokensFromInputSource();
        currentTokenIdxInList = 0;
    }
    //...
};
