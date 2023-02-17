/* Point out the problem in the code below. Further suppose that you
 * need to reuse the file copier in a text mode file copying application
 * that will display the progress in its text console as an integer.
 * What should you do?
 */
#include <iostream>
#include <vector>
using namespace std;
class JFrame {
	//Draw a window on screen
};
class ProgressBar {
	public: void setPercentage(double d);
	//...
};
class File {
	public: 
		File(char *filename);
		int length();
};
class MainApp;
class FileCopier {
    MainApp *app;
	public: FileCopier(MainApp *app);
    void copyFile(File *source, File *target);
};
class MainApp : public JFrame {
    ProgressBar *progressBar;
	public: void run() {
		FileCopier *fileCopier = new FileCopier(this);
		fileCopier->copyFile(new File("f1.doc"), new File("f2.doc"));
	}
	void updateProgressBar(int noBytesCopied, int sizeOfSource) {
        progressBar->setPercentage(noBytesCopied*100.0/sizeOfSource);
    }
};
FileCopier::FileCopier(MainApp *app) {
	this->app = app;
}
void FileCopier::copyFile(File *source, File *target) {
	int sizeOfSource = (int)source->length();
	for (int i = 0; i < sizeOfSource; ) {
		int n=0;
		//read n (<= 512) bytes from source.
		//write n bytes to target.
		i += n;
		app->updateProgressBar(i, sizeOfSource);
	}
}
int main() {
	MainApp m;
	m.run();
}
