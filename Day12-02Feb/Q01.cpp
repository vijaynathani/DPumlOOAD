#include <iostream>
#include <cstring>
using namespace std;
//Improve the code
class Order {
    //...
    bool IsSameString(string *s1, string *s2){
        if(s1==s2) return true;
        if(s1==0) return false;
        return s1->compare(*s2) == 0;
    }
};
class Mail {
    //...
    static bool IsSameString(string *s1, string *s2) {
        if (s1 == s2)
            return true;
        if (s1 == 0)
            return false;
        return s1->compare(*s2) == 0;
    }
};
