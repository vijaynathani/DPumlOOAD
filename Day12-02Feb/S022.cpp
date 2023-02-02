#include <iostream>
using namespace std;
class TelNo {
    string countryCode, areaCode, localNumber;
};
class Name {
    string firstName, lastName;
};
class Organization {
    string id;
    string englishName, chineseName; 
    TelNo contactNo, faxNo;
    Name englishName, chineseName;
    TelNo contactPrsonTel,contactPersonFax, contactPersonMobile;
    //...
};
