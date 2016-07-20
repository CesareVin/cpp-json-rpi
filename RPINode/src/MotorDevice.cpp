/*
 * MotorDevice.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#include "MotorDevice.h"




MotorDevice::MotorDevice(string name):DeviceBase() {

	this->m_name = name;
	TCommandSchema schema;
	schema.insert(TCommandSchemaPair("direction","string"));
	motorOn = new BaseCommand("motorOn",this->m_name,schema);
	this->addCommand(motorOn);
}

MotorDevice::~MotorDevice() {

}

