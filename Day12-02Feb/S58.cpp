#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
class InetAddress {
	//...
};
class Server {
	string name;
	string CPUModel;
	int RAMSizeInMB;
	int diskSizeInMB;
	InetAddress ipAddress;
};
class Administrator {
	string adminId;
	vector<Server *> serversAdminedByHim;
};
class DHCPConfig {
	InetAddress startIP;
	InetAddress endIP;
};
class FileServerConfig {
	map<string *,int> userIdToQuota;
	int getQuotaForUser(string &userId) {
		int quota=0;
		//...
		return quota;
	}
	void setQuotaForUser(string &userId, int quota) {
		//...
	}
};
class ServerConfigSystem {
	vector<Server *> servers;
	vector<Administrator *> admins;
	map<Server *,DHCPConfig *> DHCPservers;
	map<Server *,FileServerConfig *> FileServers;
};
