/*
 * Node.h
 *
 *  Created on: Jun 16, 2016
 *      Author: cesare
 */

#ifndef NODE_BASE_H_
#define NODE_BASE_H_

#include<string>
#include<vector>

#include "http.h"
#include "router.h"
#include "endpoint.h"
#include <algorithm>

#include "NodeBase.h"
#include "DeviceBase.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
using namespace Net;
using namespace Net::Rest;

using namespace rapidjson;

class NodeBase
{

public:
	explicit NodeBase();
	explicit NodeBase(vector<DeviceBase*> devices);
	~NodeBase();
	string getName();
	void setName(string name);
	vector<DeviceBase*> getDevices();
	void addDevice(DeviceBase* device);
	DeviceBase* removeDevice(int id);

	void init(Net::Address addr);
	void open();
	void close();

protected:
	Rest::Router router;

	void onCommands(const Net::Http::Request& req,Net::Http::ResponseWriter response);
	void onIndex(const Net::Http::Request& req,Net::Http::ResponseWriter response);
private:
	string m_name;
	vector<DeviceBase*> m_Devices;
	std::shared_ptr<Net::Http::Endpoint> httpEndpoint;
};



#endif /* NODE_H_ */
