/*
 * BaseCommand.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: cesare
 */

#include "BaseCommand.h"

BaseCommand::BaseCommand(string name,string device,map<string,string> schema){
	m_name = name;
	m_device = device;
	m_requestSchema = schema;

}
BaseCommand::BaseCommand()
{
	m_name = "";
	m_device = "";
}

BaseCommand::~BaseCommand() {
	// TODO Auto-generated destructor stub
}

