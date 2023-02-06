#include <iostream>
#include <string>
using namespace std;
//EmployeeList does not want to inherit the addNode method.
//Employee is not a Node.
class Node {
	Node *nextNode;
	public: Node *getNextNode() {
		return nextNode;
	}
	void setNextNode(Node *nextNode) {
		this->nextNode = nextNode;
	}
};
class LinkList {
	Node *firstNode;
	public: void addNode(Node *newNode) {
		//...
	} 
	Node *getFirstNode() {
		return firstNode;
	}
};
class Employee {
	string employeeId;
	string name;
	//...
};
class EmployeeNode : public Node {
	Employee *employee;
	public: EmployeeNode(Employee *e) { employee = e; }
	Employee *getEmployee() { return employee; }
};
class EmployeeList {
	LinkList list;
	public: void addEmployee(Employee &employee) {
		list.addNode(new EmployeeNode(&employee));
	}
	Employee *getFirstEmployee() {
		return ((EmployeeNode *)list.getFirstNode())->getEmployee();
	}
	//...
};
