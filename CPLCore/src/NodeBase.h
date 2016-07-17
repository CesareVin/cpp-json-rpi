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
#include "IDevice.h"

using namespace std;

class NodeBase
{
public:
	NodeBase();
	NodeBase(vector<IDevice*> devices);
	~NodeBase();
	string getName();
	void setName(string name);
	vector<IDevice*> getDevices();
	void addDevice(IDevice* device);
	IDevice* removeDevice(int id);

private:
	string m_name;
	vector<IDevice*> m_Devices;
};



#endif /* NODE_H_ */
