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
#include "http.h"
#include "router.h"

using namespace Net;
using namespace std;

class DeviceBase
{
public:
	/**
    * DeviceBase
    * Default cnostructor*/
	explicit DeviceBase(){};
	explicit DeviceBase(string name,vector<BaseCommand*> commands):m_name(name),m_Commands(commands)
	{
	}
	/**
    * DeviceBase
    * Default destructor*/
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
    * @param -name    : string that represent the command name.
    */
	void setName(string name)
	{
		this->m_name = name;
	}

	/**
    * getCommands
    * get all commands
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

	/**
    * dispatchCommand
    * Execute a command
    * @param -command    : BaseCommand the command.
    * @param -response   : ResponseWriter to build responce.
    * @return bool determines if command is correctly executed
    */
	virtual bool dispatchCommand(BaseCommand command,Net::Http::ResponseWriter response)=0;




protected:
	string m_name;
	vector<BaseCommand*> m_Commands;
};



#endif /* IDEVICE_H_ */
