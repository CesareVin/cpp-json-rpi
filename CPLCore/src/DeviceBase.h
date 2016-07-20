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
#include "BaseCommand.h"

using namespace std;

class DeviceBase
{
public:
	explicit DeviceBase(){};
	explicit DeviceBase(string name,vector<BaseCommand*> commands)
	{
		m_name = name;
		m_Commands = commands;
	}
	virtual ~DeviceBase(){

		while (!this->m_Commands.empty()){
			BaseCommand* command =m_Commands.back();
			m_Commands.pop_back();
			delete(command);
		}
	};

	string getName()
	{
		return this->m_name;
	}
	void setName(string name)
	{
		this->m_name = name;
	}
	vector<BaseCommand*> getCommands()
	{
		return m_Commands;
	}
	void addCommand(BaseCommand* command)
	{
		m_Commands.push_back(command);
	}

protected:
	string m_name;
	vector<BaseCommand*> m_Commands;
};



#endif /* IDEVICE_H_ */
