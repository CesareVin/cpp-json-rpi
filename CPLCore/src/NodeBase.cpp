
#include "NodeBase.h"

NodeBase::NodeBase()
{

}

NodeBase::NodeBase(vector<DeviceBase*> devices)
{
	this->m_Devices = devices;
}

NodeBase::~NodeBase()
{
	/*for (auto &dev : this->m_Devices)	{ }*/
	while (!this->m_Devices.empty()){
	    DeviceBase* dev =this->m_Devices.back();
	    delete(dev);
	    m_Devices.pop_back();
	}
}

string NodeBase::getName()
{
	return this->m_name;
}
void NodeBase::setName(string name)
{
	this->m_name = name;
}
vector<DeviceBase*> NodeBase::getDevices()
{
	return this->m_Devices;
}
void NodeBase::addDevice(DeviceBase* device)
{
	this->m_Devices.push_back(device);
}
DeviceBase* NodeBase::removeDevice(int id)
{
	DeviceBase* dev =this->m_Devices.back();
	this->m_Devices.pop_back();
	return dev;
}


