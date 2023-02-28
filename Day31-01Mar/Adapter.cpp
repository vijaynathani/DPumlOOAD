/* class NameReadOnly {
	public:
	virtual string getFirstName() = 0;
	virtual string getLastName() = 0;
	virtual string print();
};*/
class Name  {
	public:
	string first, last;
	//
	public:
	virtual string getFirstName();
	virtual string getLastName();
	virtual void setFirstName(string &first);
	virtual void setLastName(string &first);
	virtual string print() { return first + " " + last; }
};
class NameReadOnly : public Name {
	public:
	void setFirstName(string &first) {throw runtime_error("..."); }
	virtual void setLastName(string &first) {throw runtime_error("..."); }
}
class NameAdapter : public Name {
	public:
	string print() override { return last + " " + first; }
}
class NameAdapter2  {
	Name nm;
	public:
	string print() override { return nm.last + " " + nm.first; }
}