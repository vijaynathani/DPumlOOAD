#include <iostream>
#include <string>
using namespace std;
class ResultSet {
	//...
};
class PreparedStatement { //SQL statement
	public: void close();
	ResultSet *executeQuery();
	ResultSet *executeUpdate();
	void setString(int parameterNumber, string parameter);
	//...
};
class Connection { //Database connection
	public: PreparedStatement *prepareStatement(char *sqlStatment); 
	//...
};
class Customer { 
	public: string *getIDNumber();
			string *getName();
	//...
};
class String1 : public string {
	public: String1 &replace(char orignal, char newChar);
	String1(string &s);
	string toString();
};
//Improve the code
class CustomersInDB {
    Connection conn;
	public:
    Customer *getCustomer(string &IDNumber) {
		Customer *r = 0;
        PreparedStatement *st = conn.prepareStatement(
            "select * from customer where ID=?");
		String1 s(IDNumber);
		s.replace('-',' ').replace('(',' ').replace(')',' ').
					replace('/',' ');
		st->setString(1,s.toString());
		ResultSet *rs = st->executeQuery();
		//...
		st->close();
		delete st;
		return r;
    }
    void addCustomer(Customer &customer) {
        PreparedStatement *st = conn.prepareStatement(
            "insert into customer values(?,?,?,?)");
		String1 s(*customer.getIDNumber());
		s.replace('-',' ').replace('(',' ').replace(')',' ').
					replace('/',' ');
		st->setString(1,s.toString());
		st->setString(2, *customer.getName());
        //    ...
		st->executeUpdate();
        // ...
		st->close();
		delete st;
	}
};
