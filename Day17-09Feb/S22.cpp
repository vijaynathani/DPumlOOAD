#include <string>
#include <cstdlib>
using namespace std;
class Account {
	//...
	bool isComplexPassword(string &password){
		return containsLetter(password) &&
			(containsDigit(password) || containsSymbol(password));
	} 
	bool containsLetter(string &password) {
		//...
	} 
	bool containsDigit(string &password) {
		//...
	} 
	bool containsSymbol(string &password) {
		//...	
	}
};
