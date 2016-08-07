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
#include <sys/time.h>

#include "cpprest/json.h"
#include "cpprest/http_listener.h"
#include "cpprest/uri.h"
#include "cpprest/asyncrt_utils.h"
#include "NodeBase.h"
#include "DeviceBase.h"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

using namespace std;

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
	virtual http_response dispatchRequest(http_request request)=0;

private:
	string m_name;
	vector<DeviceBase*> m_Devices;
};



#endif /* NODE_H_ */
