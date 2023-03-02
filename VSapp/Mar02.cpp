#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
namespace mar02 {
	class HasCoins;
	class StampDispensor {
		HasCoins* state = nullptr;
	public:
		StampDispensor();
		void addCoins(int coins);
		~StampDispensor() { delete state; }
	};
	class HasCoins {
	public:
		int coins = 0;
		HasCoins(int coinsPresent) : coins{coinsPresent} {}
		HasCoins* addCoins(int newCoinsAdded);
	};
	StampDispensor::StampDispensor() {
		state = new HasCoins(0);
	}
	void StampDispensor::addCoins(int coins) {
		state = state->addCoins(coins);
	}
	HasCoins* HasCoins::addCoins(int newCoinsAdded) {
		const int STAMP_VALUE = 20;
		coins += newCoinsAdded;
		if (coins < STAMP_VALUE) return this;
		cout << "Stamp dispensed" << endl;
		coins -= STAMP_VALUE;
		if (coins == 0) return this;
		cout << "Refund for " << coins << " cents." <<endl;
		coins = 0;
		return this;
	}
}
using namespace mar02;
void mar02Main() {
	StampDispensor sd;
	sd.addCoins(5);
	sd.addCoins(5);
	sd.addCoins(20);
}