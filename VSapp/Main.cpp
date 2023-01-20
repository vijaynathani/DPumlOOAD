#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

#include "Jan20.cpp"
int main()
{
	Person1 Don, John;
	Don.location = "Champaign";
	John.location = "Champaign";
	Organization engineering, tools, apps;
	tools.location = "Chicago";
	tools.children.push_back(&Don);
	tools.children.push_back(&John);
	apps.location = "saba";
	engineering.location = "Boston";
	engineering.children.push_back(&tools);
	engineering.children.push_back(&apps);



	Author bob;
	bob.name = "Bob J";
	bob.age = 32;
	Computer bobPC;
	bobPC.name = "Dell 466";
	bobPC.memory = 64;
	bobPC.usedBy = &bob;
}

