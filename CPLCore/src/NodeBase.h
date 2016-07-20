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
#include "DeviceBase.h"

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

private:
	string m_name;
	vector<DeviceBase*> m_Devices;
};



#endif /* NODE_H_ */
