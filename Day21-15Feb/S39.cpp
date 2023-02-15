#include <vector>
using namespace std;
class Alarm { //...
	public: bool turnOn();
};
class HeatSensor { //...
	public: bool isOverHeated();
};
class PowerSupply { //...
	public: bool turnOff();
};
class MoistureSensor { //...
	public: int getMoisture();
};
class Heater { //...
	public: void setTemperature(int);
};
class Thread { //...
	public: void sleep (int milliSeconds);
};



class Runnable {
	public: virtual void run() = 0;
};
class Scheduler :public Thread {
    vector<Runnable *> tasks;
	public: void registerTask(Runnable *task) {
        //add task to tasks;
    }
    void run() {
        for (;;) {
			Thread::sleep(1000);
            for (unsigned int i = 0; i < tasks.size(); i++) {
                tasks[i]->run();
            }
        }
    }
};
class OverHeatCheckTask : public Runnable {
    Alarm *alarm;
    PowerSupply *powerSupply;
    HeatSensor *heatSensor;
	public: void run() {
        if (heatSensor->isOverHeated()) {
            powerSupply->turnOff();
            alarm->turnOn();
        }
    }
};
class RiceCookedCheckTask : public Runnable {
    Heater *heater;
    MoistureSensor *moistureSensor;
	public: void run() {
        if (moistureSensor->getMoisture()<60) {
            heater->setTemperature(50);
        }
    }
};
int main(){
	Scheduler *scheduler = new Scheduler();
	scheduler->registerTask(new OverHeatCheckTask());
	scheduler->registerTask(new RiceCookedCheckTask());
	//...
}
