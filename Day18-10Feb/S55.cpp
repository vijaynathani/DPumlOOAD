#include <iostream>
#include <string>
#include <vector>
using namespace std;
class JDialog { //...
};
class JComboBox { //...
	public: void addItem(void *);
	void *getSelectedItem();
};
class Report {
	public: virtual void print() = 0;
};
class Report1 : public Report {
	public: string toString() { return "r1"; }
    void print() {
        //print some fancy report...
    }
};
class Report2 : public Report {
    string toString() { return "r2"; }
    void print() {
        //print another totally different fancy report...
    }
};
//...
class Report31c : public Report {
    string toString() { return "r31c"; }
    void print() {
        //print yet another totally different fancy report...
    }
};
static bool init = false;
class Form1 : public JDialog {
    JComboBox *comboBoxReportType;
    static vector<Report *>reports; 
	void initialize() {
		init = true;
		reports.push_back(new  Report1());
		reports.push_back(new  Report2());
		//...
		reports.push_back(new  Report31c());
	}
	public: Form1() {
		if (!init) initialize();
        comboBoxReportType = new JComboBox();
        for (unsigned int i = 0; i < reports.size(); i++) 
            comboBoxReportType->addItem(reports[i]);
    }
    void onPrintClick() {
        Report *report = (Report *)comboBoxReportType->getSelectedItem();
        report->print();
    }
};
