#include <iostream>
#include <string>
using namespace std;
class FileWriter {
	public: FileWriter(string file);
	void write(string line);
	void close();
};

//Remove the problem in code below.
//Assume that PropertyFileWriter is not used anywhere else
//other than class App.
class PropertyFileWriter : public FileWriter {
	public: PropertyFileWriter(string path) : FileWriter(path) {
		//...
    }
    void writeEntry(string key, string value) {
        write(key+"="+ value);
    }
	//Many more functions here
};
class App {
    void makePropertyFile() {
        PropertyFileWriter *fw = new PropertyFileWriter("f1.properties");
		fw->writeEntry("conference.abc", "10");
		fw->writeEntry("xyz", "hello");
		fw->close();
    }
};
