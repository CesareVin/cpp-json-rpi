
#include "NodeBase.h"

NodeBase::NodeBase()
{

}

NodeBase::NodeBase(vector<IDevice*> devices)
{
	this->m_Devices = devices;
}

NodeBase::~NodeBase()
{
	/*for (auto &dev : this->m_Devices) //foreach
	{

	}*/
	while (!this->m_Devices.empty()){
	    IDevice* dev =this->m_Devices.back();
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
vector<IDevice*> NodeBase::getDevices()
{
	return this->m_Devices;
}
void NodeBase::addDevice(IDevice* device)
{
	this->m_Devices.push_back(device);
}
IDevice* NodeBase::removeDevice(int id)
{
	IDevice* dev =this->m_Devices.back();
	this->m_Devices.pop_back();
	return dev;
}


