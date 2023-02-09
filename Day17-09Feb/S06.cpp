#include <string>
#include <stdexcept>
#include <map>
using namespace std;
static bool init=false;
class ReportCatalogueIndexCommandParser {
    static const int ORG_CATALOG = 0;
    static const int PART_CATALOG = 1;
    static map<string,int> catalogCodes;
	public: ReportCatalogueIndexCommandParser() {
		if (init) return;
        catalogCodes.insert(make_pair("orgNoGrouping", ORG_CATALOG));
        catalogCodes.insert(make_pair("orgGroupByCountry", ORG_CATALOG));
        catalogCodes.insert(make_pair("orgGroupByTypeOfOrgName", 
					ORG_CATALOG));
        catalogCodes.insert(make_pair("part", PART_CATALOG));
        //...
		init=true; //Not thread-safe
    }
    int getGroupingType(string &grouping) {
		map<string,int>::iterator p = catalogCodes.find(grouping);
		if (p == catalogCodes.end()) 
            throw runtime_error("Invalid grouping!");
        return p->second;
    }
};
