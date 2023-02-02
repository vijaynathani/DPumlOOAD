#include <iostream>
#include <cstring>
using namespace std;
//Improve the code
class StringCompareUtils {
    bool IsSameString(string *s1, string *s2){
        if(s1==s2) return true;
        if(s1==0) return false;
        return s1->compare(*s2) == 0;
    }
};
class Order {
    //...
};
class Mail {
    //...
};
