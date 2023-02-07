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
	string *replaceSymbolsInID(string *idNumber) {
		string symbolsToReplace = "-()/";
		//Replace the characters by spaces in IdNumber
		return idNumber;
	}
	public:
    Customer *getCustomer(string &IDNumber) {
		Customer *r = 0;
        PreparedStatement *st = conn.prepareStatement(
            "select * from customer where ID=?");
		st->setString(1,*replaceSymbolsInID(&IDNumber));
		ResultSet *rs = st->executeQuery();
		//...
		st->close();
		delete st;
		return r;
    }
    void addCustomer(Customer &customer) {
        PreparedStatement *st = conn.prepareStatement(
            "insert into customer values(?,?,?,?)");
		string cust(*customer.getIDNumber());
		st->setString(1,*replaceSymbolsInID(&cust));
		st->setString(2, *customer.getName());
        //    ...
		st->executeUpdate();
        // ...
		st->close();
		delete st;
	}
};
