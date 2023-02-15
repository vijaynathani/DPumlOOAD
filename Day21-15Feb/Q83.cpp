class HeatSensor;
const static int HIGH_FREQUENCY=5000;
class Speaker { //...
	public: void setFrequency(int);
	void turnOn();
};
/* Point out the problem in the code below. Further suppose that 
 * you need to reuse the heat sensor code in another application. 
 * What should you do?
 */
class Cooker {
    HeatSensor *heatSensor;
    Speaker *speaker;
	public: void alarm() {
        speaker->setFrequency(HIGH_FREQUENCY);
        speaker->turnOn();
    }
};
class HeatSensor {
    Cooker *cooker;
	public: HeatSensor(Cooker *cooker) {
        this->cooker = cooker;
    }
    bool isOverHeated() { //...
    }
    void checkOverHeated() {
        if (isOverHeated()) {
            cooker->alarm();
        }
    } 
};
