#include <iostream>
#include <string>
using namespace std;
class Part { //...
};
class Participant { //...
	public: string getELastName();
			string getEFirstName();
            string getCLastName();
			string getCFirstName();
};
class ParticipantsInDB { //...
	public: static ParticipantsInDB *getInstance();
	Participant *locateParticipant(string &pid);
};
class Address {
	public: string getCountry();
	//...
};
class Organization {
	public: string getEName();
			string getCName();
			Address *getEAddress();
			Address *getCAddress();
};
class OrganizationsInDB { //...
	public: static OrganizationsInDB *getInstance();
	string *getOrganization(string &pid);
	Organization *locateOrganization(string oid);
};
//Improve the code
class Badge {
    string pid; //participant ID
    string engName; //participant's full name in English
    string chiName; //participant's full name in Chinese
    string engOrgName; //name of the participant's organization in English
    string chiOrgName; //name of the participant's organization in Chinese
    string engCountry; //the organization's country in English
    string chiCountry; //the organization's country in Chinese
    //***********************
    //constructor.
    //The participant ID is provided. It then loads all the info from the DB.
    //***********************
	public: Badge(string &pid) {
        this->pid = pid;
        //***********************
        //get the participant's full names.
        //***********************
        ParticipantsInDB *partsInDB = ParticipantsInDB::getInstance();
        Participant *part = partsInDB->locateParticipant(pid);
        if (part != 0) {
            //get the participant's full name in English.
            engName = part->getELastName() + ", " + part->getEFirstName();
            //get the participant's full name in Chinese.
            chiName = part->getCLastName()+part->getCFirstName();
            //***********************
            //get the organization's name and country.
            //***********************
            OrganizationsInDB *orgsInDB = OrganizationsInDB::getInstance();
            //find the ID of the organization employing this participant.
            string *oid = orgsInDB->getOrganization(pid);
            if (oid != 0) {
                Organization *org = orgsInDB->locateOrganization(*oid);
                engOrgName = org->getEName();
                chiOrgName = org->getCName();
                engCountry = org->getEAddress()->getCountry();
                chiCountry = org->getCAddress()->getCountry();
            }
        }
    }
    //...
};
