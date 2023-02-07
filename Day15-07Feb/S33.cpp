#include <iostream>
#include <string>
using namespace std;
class SurveyDataType {
	string baseFileName;
	bool hideDataFile;
	public: SurveyDataType(string baseFileName, bool hideDataFile) {
		this->baseFileName = baseFileName;
		this->hideDataFile = hideDataFile;
	}
	string getSavePath() {
		return "c:/application/data/"+baseFileName+".dat";
	}
};
static const SurveyDataType rawDataType("raw", true);
static const SurveyDataType cleanedUpDataType("cleanedUp", true);
static const SurveyDataType processedDataType("processed", true);
static const SurveyDataType publicationDataType("publication", false);
