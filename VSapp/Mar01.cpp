#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
namespace mar01 {
	class State;
	class NoQuaterState;
	struct GumBallMachine {
		int gumballsRemaining;
		State* current = nullptr;
		GumBallMachine(int gumballs);
		void coinInserted();
		void ejectPressed();
		void leverTurned();
	private:
		void update_state(State* newState);
	};
	class State {
	public:
		virtual State* coinInserted() {
			cout << "Refund of coin" << endl;
			return this;
		}
		virtual State* leverTurned(GumBallMachine* gm) {
			return this;
		}
		virtual State* ejectPressed() {
			return this;
		}
		virtual ~State() {}
	};
	class NoQuaterState : public State {
		State* coinInserted () override;
	};
	class HasQuaterState : public State {
		State* leverTurned(GumBallMachine* gm) override;
		State* ejectPressed() override;
	};
	class SoldoutQuaterState : public State {
	};
	State* HasQuaterState::ejectPressed() {
		cout << "Refund coin" << endl;
		return new NoQuaterState();
	}

	State* HasQuaterState::leverTurned(GumBallMachine* gm) {
		cout << "Gumball dispensed" << endl;
		if (--gm->gumballsRemaining > 0)
			return new NoQuaterState();
		else
			return new SoldoutQuaterState();
	}
	State* NoQuaterState::coinInserted() {
		return  new HasQuaterState();
	}

	GumBallMachine::GumBallMachine (int gumballs) {
		current = new NoQuaterState();
		gumballsRemaining = gumballs;
	}
	void GumBallMachine::coinInserted() {
		update_state(current->coinInserted());
	}
	void GumBallMachine::leverTurned() {
		update_state(current->leverTurned(this));
	}
	void GumBallMachine::ejectPressed() {
		update_state(current->ejectPressed());
	}
	void GumBallMachine::update_state(State* newState) {
		if (newState == current) return;
		delete current;
		current = newState;
	}

}
using namespace mar01;
void mar01Main() {
	GumBallMachine gm(2);
	gm.leverTurned();
	gm.coinInserted();
	gm.leverTurned();
	gm.coinInserted();
	gm.leverTurned();
	gm.leverTurned();
}