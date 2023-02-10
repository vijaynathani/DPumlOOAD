#include <iostream>
#include <string>
using namespace std;
class JDialog { //...
};
class JComboBox { //...
	public: void addItem(char *);
	string getSelectedItem();
};
class Form1 : public JDialog {
    JComboBox *comboBoxReportType;
	public:
    Form1() {
        comboBoxReportType = new JComboBox();
        comboBoxReportType->addItem("r1");
        comboBoxReportType->addItem("r2");
        //...
        comboBoxReportType->addItem("r31c");
    }
    void processReport1() {
        //print some fancy report...
    }
    void processReport2() {
        //print another totally different fancy report...
    }
    //...
    void processReport31c() {
        //print yet another totally different fancy report...
    }
    void printReport(string repNo) {
        if (repNo.compare("r1") == 0)
            processReport1();
        else if (repNo.compare("r2") == 0)
            processReport2();
            //...
        else if (repNo.compare("r31c") == 0)
            processReport31c();
    }
    void onPrintClick() {
        printReport(comboBoxReportType->getSelectedItem());
    }
};
