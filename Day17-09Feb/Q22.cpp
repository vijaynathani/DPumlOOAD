#include <string>
#include <cstdlib>
using namespace std;
//Improve the code
class Account {
    //...
    //check if the password is complex enough, i.e.,
    //contains letter and digit/symbol.
    bool isComplexPassword(string &password){
        //found a digit or symbol?
        bool dg_sym_found=false;
        //found a letter?
        bool letter_found=false;
        for(unsigned int i=0; i<password.size(); i++){
            char c=password.at(i);
            if(islower(c)||isupper(c))
                letter_found=true;
            else dg_sym_found=true;
        }
        return (letter_found) && (dg_sym_found);
    }
};
