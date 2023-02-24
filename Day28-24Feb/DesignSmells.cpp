//Design smells

class Point {
	int x,y;
	public:
		//... Getters and setters
}
class Abc {
	public:
		virtual void process() = 0;
//...
};
class Xyz : public Abc {

};
class Pqr : public Abc {
public:
	void process() override { 
		throw runtime_error("shouldn't have come here");
	}
};
void function1(int x, int y, string currency, double value, vector<int>all ) {
	if (currency == "usd")
		//...
	else if (currency == "inr")
		//...
	else if (currency == "cad")
		//...
	else
		throw runtime_error("invalid");
}