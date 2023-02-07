#include <iostream>
#include <string>
using namespace std;
//Improve the code
class SurveyData {
    string path; //save the data to this file.
    bool hidden; //should the file be hidden?
    public:
    SurveyData(string& path1, bool hidden1) {
        path = "c:/application/data/" + path1 + ".dat";
        hidden = hidden1;
    }
};
const SurveyData rawData("raw", true), cleanedData("cleanedUp", true), processedData("processed", true),
                 publicationData("publication", false);
