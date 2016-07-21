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
	explicit DeviceBase(string name,vector<BaseCommand*> commands):m_name(name),m_Commands(commands)
	{
	}
	virtual ~DeviceBase(){

		while (!this->m_Commands.empty()){
			BaseCommand* command =m_Commands.back();
			m_Commands.pop_back();
			delete(command);
		}
	};
	/**
    * getName
    * get the name of this command
    * @return string the name
    */
	string getName()
	{
		return this->m_name;
	}

	/**
    * setName
    * set the name of the command
    * @param -name    : string that rappresent the command name.
    */
	void setName(string name)
	{
		this->m_name = name;
	}

	/**
    * getName
    * get the name of this command
    * @return vector<BaseCommand*> the commands vector
    */
	vector<BaseCommand*> getCommands()
	{
		return m_Commands;
	}

	/**
    * addCommand
    * add a command.
    * @param -command    : BaseCommand* the command to add.
    */
	void addCommand(BaseCommand* command)
	{
		m_Commands.push_back(command);
	}

protected:
	string m_name;
	vector<BaseCommand*> m_Commands;
};



#endif /* IDEVICE_H_ */
