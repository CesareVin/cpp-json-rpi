/*
 * MotorDevice.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#include "MotorDevice.h"
#include "BaseCommand.h"
#include "ICommand.h"

BaseCommand* motorOn;

MotorDevice::MotorDevice(string name):IDevice() {
	// TODO Auto-generated constructor stub
	this->m_name = name;
	TCommandSchema schema;// = {{"command1","int"},{"command2","string"}};
	schema.insert(TCommandSchemaPair("direction","string"));
	motorOn = new BaseCommand("motorOn",this->m_name,schema);
	this->addCommand(motorOn);
}

MotorDevice::~MotorDevice() {
	// TODO Auto-generated destructor stub
}

