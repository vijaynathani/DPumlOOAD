/* Point out the problem in the code below. Further suppose that you 
 * need to reuse the fax machine code in another application. What should 
 * you do?
 */
#include <iostream>
using namespace std;
class FaxMachineHardware {
	public: void setStationId(string faxno);
	void setRecipientFaxNo(string &tofax);
	void start();
	void done();
};
class MainApp;
class FaxMachine {
    MainApp *app;
	public: FaxMachine(MainApp *app);
    void sendFax(string toFaxNo, string msg);
};
class MainApp {
    string faxNo;
	public: void main() {
        FaxMachine *faxMachine = new FaxMachine(this);
        faxMachine->sendFax("783675", "hello");
    }
	string getFaxNo();
};
void FaxMachine::sendFax(string toFaxNo, string msg) {
	FaxMachineHardware hardware;
	//...
	hardware.setStationId(app->getFaxNo());
	hardware.setRecipientFaxNo(toFaxNo);
	hardware.start();
	//do {
		//Graphics *graphics = hardware.newPage();
		//draw the msg into the graphics.
	//} while (more page is needed);
	hardware.done();
}
