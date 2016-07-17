/*
 * IDevice.h
 *
 *  Created on: Jun 16, 2016
 *      Author: cesare
 */

#ifndef IDEVICE_H_
#define IDEVICE_H_

#include <string>
#include <vector>
#include "ICommand.h"

using namespace std;

class IDevice
{
public:
	IDevice(){};
	IDevice(string name,vector<ICommand*> commands)
	{
		m_name = name;
		m_Commands = commands;
	}
	virtual ~IDevice(){};

	string getName()
	{
		return this->m_name;
	}
	void setName(string name)
	{
		this->m_name = name;
	}
	vector<ICommand*> getCommands()
	{
		return m_Commands;
	}
	void addCommand(ICommand* command)
	{
		m_Commands.push_back(command);
	}

protected:
	string m_name;
	vector<ICommand*> m_Commands;
};



#endif /* IDEVICE_H_ */
