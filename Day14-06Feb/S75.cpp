//As there is no code that needs to use a PropertyFileWriter as a FileWriter, 
//we should use delegation instead of inheritance:

#include <iostream>
#include <string>
using namespace std;
class FileWriter {
	public: FileWriter(string file);
	void write(string line);
	void close();
};
class PropertyFileWriter {
	FileWriter *f;
	public: PropertyFileWriter(string path)  {
		f = new FileWriter(path);
		//...
    }
    void writeEntry(string key, string value) {
        f->write(key+"="+ value);
    }
	void close() { f->close(); }
};
class App {
    void makePropertyFile() {
        PropertyFileWriter *fw = new PropertyFileWriter("f1.properties");
		fw->writeEntry("conference.abc", "10");
		fw->writeEntry("xyz", "hello");
		fw->close();
    }
};
