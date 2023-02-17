
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
class CopyMonitor {
	public: virtual void updateProgress(int noBytesCopied, 
					int sizeOfSource) =0;
};
class FileCopier {
    CopyMonitor *c;
	public: FileCopier(CopyMonitor *c) {
		this->c=c;
	};
	void copyFile(File *source, File *target) {
		int sizeOfSource = (int)source->length();
		for (int i = 0; i < sizeOfSource; ) {
			int n=0;
			//read n (<= 512) bytes from source.
			//write n bytes to target.
			i += n;
			c->updateProgress(i, sizeOfSource);
		}
	}
};
class MainApp : public JFrame,CopyMonitor {
    ProgressBar *progressBar;
	public: void run() {
		FileCopier *fileCopier = new FileCopier(this);
		fileCopier->copyFile(new File("f1.doc"), new File("f2.doc"));
	}
	void updateProgress(int noBytesCopied, int sizeOfSource) {
        progressBar->setPercentage(noBytesCopied*100.0/sizeOfSource);
    }
};
int main() {
	MainApp m;
	m.run();
}
class TextApp : public CopyMonitor {
    ProgressBar *progressBar;
	public: void updateProgress(int noBytesCopied, int sizeOfSource) {
        cout << (noBytesCopied*100.0/sizeOfSource) << endl;
    }
	public: void run() {
		FileCopier *fileCopier = new FileCopier(this);
		fileCopier->copyFile(new File("f1.doc"), new File("f2.doc"));
	}
};
/*In the above case, suppose that you need to develop another text mode
 * file copying application that will display a "*" for each 10% of
 * progress in its text console. What should you do?*/
