#include <iostream>
#include <string>
using namespace std;
class Part { //...
};
class Participant { //...
	public: string getEFullName();
			string getCFullName();
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
	string *findOrganizationEmploying(string participantId);
	Organization *locateOrganization(string oid);
};
class ParticipantInfoOnBadge {
    string participantId;
    string participantEngFullName;
    string participantChiFullName;
    string engOrgName;
    string chiOrgName;
    string engOrgCountry;
    string chiOrgCountry;

    void getParticipantFullNames() {
        ParticipantsInDB *partsInDB = ParticipantsInDB::getInstance();
        Participant *part = partsInDB->locateParticipant(participantId);
        if (part != 0) {
            participantEngFullName = part->getEFullName();
            participantChiFullName = part->getCFullName();
        }
    }
    void getOrgNameAndCountry() {
        OrganizationsInDB *orgsInDB = OrganizationsInDB::getInstance();
        string *oid = orgsInDB->findOrganizationEmploying(participantId);
        if (oid != 0) {
            Organization *org = orgsInDB->locateOrganization(*oid);
            engOrgName = org->getEName();
            chiOrgName = org->getCName();
            engOrgCountry = org->getEAddress()->getCountry();
            chiOrgCountry = org->getCAddress()->getCountry();
        }
    }
    void loadInfoFromDB(string &participantId) {
        this->participantId = participantId;
        getParticipantFullNames();
        getOrgNameAndCountry();
    }
	public: 
	ParticipantInfoOnBadge(string &participantId) {
        loadInfoFromDB(participantId);
    }
};
