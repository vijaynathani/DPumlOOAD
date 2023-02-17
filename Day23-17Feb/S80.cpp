/* Problems	in the code
 * - circular references. DIP violated.
 *	 Code not reusable in a different enviroment
 * - SRP violated
 */

#include <iostream>
#include <vector>
using namespace std;
class Frame { //Displays a window on screen
	//...
};
class StatusBar {
	public: void setText(string &message);
	//...
};
class MessageDisplay {
	public: virtual void showMessage(string msg) = 0;
};
class ZipEngine {
	public: 
	void ZipEngine::makeZip(string *zipFilePath, 
			vector<string *> &srcFilePaths, MessageDisplay *msg) {
		//create zip file at the path.
		//...
		for (unsigned int i = 0; i < srcFilePaths.size(); i++) {
			msg->showMessage("Zipping "+ (*srcFilePaths[i]));
			//add the file srcFilePaths[i] into the zip file.
			//...
		}
	}
};
class ZipMainFrame : public Frame, MessageDisplay {
    StatusBar *sb;
    void setStatusBarText(string &statusText) {
        sb->setText(statusText);
    }
	public:
    void makeZip() {
        string *zipFilePath;
        vector<string *> srcFilePaths;
        //setup zipFilePath and srcFilePaths according to the UI.
        //...
        ZipEngine *ze = new ZipEngine();
        ze->makeZip(zipFilePath, srcFilePaths, this);
    }
	virtual void showMessage(string msg) {
		setStatusBarText(msg);
	}
	//...
};
class TextModeApp  : public MessageDisplay {
	public: void makeZip() {
		string *zipFilePath;
		vector<string *>srcFilePaths;
		//...
		ZipEngine *ze = new ZipEngine();
		ze->makeZip(zipFilePath, srcFilePaths,this);
		//...
	}
	virtual void showMessage(string msg) {
		cout << msg;
	}
};
