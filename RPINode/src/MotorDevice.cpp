/*
 * MotorDevice.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#include "MotorDevice.h"


MotorDevice::MotorDevice(string name):DeviceBase() {

	m_name = name;
	TCommandSchema schema;
	schema.insert(TCommandSchemaPair("direction","string"));
	motorOn = new BaseCommand("motorGo",this->m_name,schema);
	this->addCommand(motorOn);
	this->OpenGpio();
}

MotorDevice::~MotorDevice() {
	CloseGpio();
}

bool MotorDevice::OpenGpio()
{
	std::ostringstream directionPath;
	ofstream directionFile;
	ofstream exportFile;
	exportFile.open ("/sys/class/gpio/export");

	if(exportFile.is_open())
	{
		exportFile<<MOTOR_L_A_PIN;
		exportFile<<MOTOR_L_B_PIN;
		exportFile<<MOTOR_R_A_PIN;
		exportFile<<MOTOR_R_B_PIN;

		directionPath <<"/sys/class/gpio/"<<MOTOR_L_A_NAME<<"/direction";
		directionFile.open(directionPath.str());
		if(!directionFile.is_open())
			return false;
		directionFile << "out";
		directionFile.close();

		directionPath <<"/sys/class/gpio/"<<MOTOR_L_B_NAME<<"/direction";
		directionFile.open(directionPath.str());
		if(!directionFile.is_open())
			return false;
		directionFile << "out";
		directionFile.close();

		directionPath <<"/sys/class/gpio/"<<MOTOR_R_A_NAME<<"/direction";
		directionFile.open(directionPath.str());
		if(!directionFile.is_open())
			return false;
		directionFile << "out";
		directionFile.close();

		directionPath <<"/sys/class/gpio/"<<MOTOR_R_B_NAME<<"/direction";
		directionFile.open(directionPath.str());
		if(!directionFile.is_open())
			return false;
		directionFile << "out";
		directionFile.close();

		return true;
	}

	exportFile.close();

	return false;
}

bool MotorDevice::CloseGpio()
{
	ofstream unExportFile;
	unExportFile.open ("/sys/class/gpio/unexport");

	if(unExportFile.is_open())
	{
		unExportFile<<MOTOR_L_A_PIN;
		unExportFile<<MOTOR_L_B_PIN;
		unExportFile<<MOTOR_R_A_PIN;
		unExportFile<<MOTOR_R_B_PIN;
		return true;
	}
	return false;
}

bool MotorDevice::GoOn()
{
	ofstream valueFile;
	std::ostringstream valueFilePath;
	valueFilePath<<"sys/class/gpio/"<< MOTOR_R_B_NAME<< "/value";
	valueFile.open(valueFilePath.str());
	if(valueFile.is_open())
	{
		valueFile<<"1";

	}
	return false;
}
bool MotorDevice::GoBack()
{
	return false;
}
bool MotorDevice::TurnLeft()
{
	return false;
}
bool MotorDevice::TurnRight()
{
	return false;
}
