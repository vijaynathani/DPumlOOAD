#include <iostream>
#include <string>
using namespace std;
//Remove the problem in code below without using Collections
//like vector, map, list
class Node {
    Node *nextNode;
	public: 
	Node *getNextNode() { return nextNode; }
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
class Employee : public Node {
    string employeeId;
    string name;
    //...
};
class EmployeeList : public LinkList {
	public: void addEmployee(Employee *employee) {
        addNode(employee);
    }
    Employee *getFirstEmployee() {
        return (Employee *)getFirstNode();
    }
    //...
};
