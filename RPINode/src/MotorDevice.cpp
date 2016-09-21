/*
 * MotorDevice.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#include "MotorDevice.h"



MotorDevice::MotorDevice(string name):DeviceBase() {


	m_name = name;
	/*TCommandSchema schema;
	schema.insert(TCommandSchemaPair("power","string,0->100"));
	motorOn = new BaseCommand("motorGo",this->m_name,schema);
	this->addCommand(motorOn);
	this->OpenGpio();*/
}

MotorDevice::MotorDevice(string name,string LpinA,string LnameA,string LpinB,string LnameB,
						 string RpinA,string RnameA,string RpinB,string RnameB):DeviceBase() {

	m_name = name;
	TCommandSchema schema;
	schema.insert(TCommandSchemaPair("power","string,0->100"));
	motorOn = new BaseCommand("motorOn",this->m_name,schema);
	motorLeft = new BaseCommand("motorLeft",this->m_name,schema);
	motorRight = new BaseCommand("motorRight",this->m_name,schema);
	motorBack = new BaseCommand("motorBack",this->m_name,schema);

	m_motorLPinA = LpinA;
	m_motorLNameA = LnameA;
	m_motorLPinB = LpinB;
	m_motorLNameB = LnameB;

	m_motorRPinA = LpinA;
	m_motorRNameA = LnameA;
	m_motorRPinB = LpinB;
	m_motorRNameB = LnameB;

	this->addCommand(motorOn);
	this->addCommand(motorLeft);
	this->addCommand(motorRight);
	this->addCommand(motorBack);

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
		//export motor L pins
		exportFile<<m_motorLPinA;
		exportFile<<m_motorLPinB;
		//export motor R pins
		exportFile<<m_motorRPinA;
		exportFile<<m_motorRPinB;
		//setup direction
		directionPath <<"/sys/class/gpio/"<<m_motorLNameA<<"/direction";
		directionFile.open(directionPath.str());
		if(!directionFile.is_open())
			return false;
		directionFile << "out";
		directionFile.close();

		directionPath <<"/sys/class/gpio/"<<m_motorRNameA<<"/direction";
		directionFile.open(directionPath.str());
		if(!directionFile.is_open())
			return false;
		directionFile << "out";
		directionFile.close();

		directionPath <<"/sys/class/gpio/"<<m_motorLNameB<<"/direction";
		directionFile.open(directionPath.str());
		if(!directionFile.is_open())
			return false;
		directionFile << "out";
		directionFile.close();

		directionPath <<"/sys/class/gpio/"<<m_motorRNameB<<"/direction";
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
		unExportFile<<m_motorLPinA;
		unExportFile<<m_motorLPinB;
		unExportFile<<m_motorRPinA;
		unExportFile<<m_motorRPinB;
		return true;
	}
	return false;
}

bool MotorDevice::GoOn()
{
	ofstream valueFile;
	ofstream valueFile1;
	std::ostringstream valueFilePath;
	std::ostringstream valueFilePath1;
	valueFilePath<<"sys/class/gpio/"<< m_motorLNameA<< "/value";
	valueFilePath1<<"sys/class/gpio/"<< m_motorRNameA<< "/value";
	valueFile.open(valueFilePath.str());
	valueFile1.open(valueFilePath1.str());
	if(valueFile.is_open())
	{
		valueFile<<"1";
		valueFile<<"1";
		return true;
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
bool MotorDevice::dispatchCommand(BaseCommand command,Net::Http::ResponseWriter response)
{
	if(command == motorOn)
	{
		printf("[INFO] motorOn \n");
		GoOn();
	}
	else if(command == motorBack)
	{
		printf("[INFO] motorBack \n");
		GoBack();
	}
	else if(command == motorLeft)
	{
		printf("[INFO] motorLeft \n");
		TurnLeft();
	}
	else if(command == motorRight)
	{
		printf("[INFO] motorLeft \n");
		TurnRight();
	}
	response.send(Net::Http::Code::Ok, "Command Executed");

	return true;
}

