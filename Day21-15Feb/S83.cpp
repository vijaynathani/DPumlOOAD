const static int HIGH_FREQUENCY=5000;
class Speaker { //...
	public: void setFrequency(int);
	void turnOn();
};
class HeatSensor;
class Alarm {
	public: virtual void turnOn() = 0;
};
class Cooker {
    HeatSensor *heatSensor;
    Speaker *speaker;
	class CookerAlarm : public Alarm {
		Speaker *speaker;
		public: CookerAlarm(Speaker *s) { speaker = s;}
		void turnOn() {
			speaker->setFrequency(HIGH_FREQUENCY);
			speaker->turnOn();
		}
	};
    Alarm *getAlarm() {
        return new CookerAlarm(speaker);
    }
};
class HeatSensor {
    Alarm *alarm;
	public: HeatSensor(Alarm *alarm) {
        this->alarm = alarm;
    }
	bool isOverHeated() { //...
	}
    void checkOverHeated() {
        if (isOverHeated()) {
            alarm->turnOn();
        }
    }
    //...
};
