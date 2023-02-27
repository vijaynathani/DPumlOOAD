
#include <iostream>
#include <fstream>
using namespace std;

namespace feb27 {
	struct View {
		void main();
	};
	struct IDataStore {
		virtual void write(int number) = 0;
		virtual ~IDataStore() {}
	};
	class DataStore : public IDataStore {
		ofstream outFile;
	public:
		DataStore() : outFile{"prime.txt"} {}
		void write(int number) { outFile << number << endl; }
		~DataStore() { outFile.close(); }
	};
	class Domain {
		IDataStore *ds;
	public:
		Domain(IDataStore *dsObj) : ds{dsObj} {}
		void process(int n);
		~Domain() {
			delete ds;
		}
	};
	void Domain::process(int n) {
		if (n < 1) return;
		for (int i = 2; n>3 && i <= n / 2; i++)
			if (n % i == 0) return;
		ds->write(n);
	}
	void View::main() {
		int n;
		Domain d{ new DataStore() };
		cout << "Enter numbers (-1 to end):" << endl;
		while (true) {
			cin >> n;
			if (n == -1) break;
			d.process(n);
		}
	}
}

using namespace feb27;
void feb27Main(int argc, char** argv) {
	View ui;
	ui.main();
}

#include <gtest/gtest.h>
namespace feb27Tests {
	struct DataStoreMock : public IDataStore {
		int numberReceived = 0;
		void write(int number) { numberReceived = number; }
	};
	TEST(Domain, PrimeNumber) {
		auto proxy = new DataStoreMock();
		Domain sut{ proxy };
		sut.process(5);
		EXPECT_EQ(5, proxy->numberReceived);
	}
	TEST(Domain, NotPrimeNumber) {
		auto proxy = new DataStoreMock();
		Domain sut{ proxy };
		sut.process(15);
		EXPECT_EQ(0, proxy->numberReceived);
	}
}
