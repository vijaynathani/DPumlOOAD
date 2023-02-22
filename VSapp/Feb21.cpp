#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <random>
#include <cassert>
#include <unordered_set>
#include <algorithm>

using namespace std;
namespace feb21_Simple {
	//Simple Database Access
	class Company {
		int id;
		string name, addressLine1, addressLine2, city, zipcode, mobile;
	public:
		/* code commented to eliminate syntax errors
		void addRecord(dbConnection& db) {
			SACommand insert(&db, "Insert into Company(name, city) values (:1, :2");
			insert << "Kpit" << "Pune";
			insert.Execute();
		}
		static Company* readRecord(dbConnection&db, int id) {
			SACommand select(&db, "select id, name from Company where id = :1");
			select << id;
			select.Execute();
			if (!select.FetchNext()) return nullptr;
			auto r = new Company();
			r->id = select[1].asInt;
			r->name = select[2].asString();
			return r;
		}*/
	};
}
namespace feb21_ORM{ //ODB library
//#pragma db object
	class Address {
	public:
		string addressLine1, addressLine2, city, zipcode;
	};
	class Company {
	public:
		int id;
		string name;
		Address addr;
		string mobile;
	};
}
using namespace feb21_ORM;
void feb21Main() {
	//auto db = new odb::oracle::database("dbName", "user", "password");
	Company c1;
	c1.name = "vijay";
	c1.addr.city = "Mumbai";
	/* db->persist(&c1);

	odb::result<Company> r(db->query<Company>::id < 5);
	for (auto& row : r)
		cout << row->name();

	delete db; */
}