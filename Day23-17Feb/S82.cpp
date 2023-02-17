#include <iostream>
using namespace std;
class FaxMachineHardware {
	public: void setStationId(string faxno);
	void setRecipientFaxNo(string &tofax);
	void start();
	void done();
};
class FaxMachine {
    string faxNo;
	public: FaxMachine(string faxNo);
    void sendFax(string toFaxNo, string msg);
};
void FaxMachine::sendFax(string toFaxNo, string msg) {
	FaxMachineHardware hardware;
	//...
	hardware.setStationId(faxNo);
	hardware.setRecipientFaxNo(toFaxNo);
	hardware.start();
	//do {
		//Graphics *graphics = hardware.newPage();
		//draw the msg into the graphics.
	//} while (more page is needed);
	hardware.done();
}
class MainApp {
    string faxNo;
	public: void main() {
        FaxMachine *faxMachine = new FaxMachine(faxNo);
        faxMachine->sendFax("783675", "hello");
    }
};
