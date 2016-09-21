/*
 * MotorDevice.h
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#ifndef MOTORDEVICE_H_
#define MOTORDEVICE_H_

#include <DeviceBase.h>
#include <string>
#include "BaseCommand.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class MotorDevice: public DeviceBase {
public:
	MotorDevice(string name);
	MotorDevice(string name,string LpinA,string LnameA,string LpinB,string LnameB,
				 string RpinA,string RnameA,string RpinB,string RnameB);
	virtual ~MotorDevice();

	bool GoOn();
	bool GoBack();
	bool TurnLeft();
	bool TurnRight();

	bool dispatchCommand(BaseCommand command,Net::Http::ResponseWriter response);


private:
	bool OpenGpio();
	bool CloseGpio();
	BaseCommand* motorOn;
	BaseCommand* motorLeft;
	BaseCommand* motorRight;
	BaseCommand* motorBack;

	string m_motorLPinA;
	string m_motorLNameA;
	string m_motorLPinB;
	string m_motorLNameB;

	string m_motorRPinA;
	string m_motorRNameA;
	string m_motorRPinB;
	string m_motorRNameB;
};

#endif /* MOTORDEVICE_H_ */
