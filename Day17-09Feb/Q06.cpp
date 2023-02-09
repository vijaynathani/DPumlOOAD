#include <string>
#include <stdexcept>
using namespace std;
//improve code
static string NO_GROUPING("orgNoGrouping");
class ReportCatalogueIndexCommandParser {
    static const int ORG_CATALOG = 0;
    static const int PART_CATALOG = 1;
    //.... other codes
    int getGroupingType(string &grouping) {
        if (grouping.compare(NO_GROUPING) == 0) {
            return ORG_CATALOG;
        } else if (grouping.compare("orgGroupByCountry") == 0) {
            return ORG_CATALOG;
        } else if (grouping.compare("orgGroupByTypeOfOrgName") == 0) {
            return ORG_CATALOG;
        } else if (grouping.compare("part") == 0) {
            return PART_CATALOG;
        } else if {.... // many other if statements
        } 
		else
            throw runtime_error("Invalid grouping!");
	}
};

