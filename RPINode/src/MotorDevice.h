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
	MotorDevice(string name,string pinA,string nameA,string pinB,string nameB);
	virtual ~MotorDevice();

	bool GoOn();
	bool GoBack();
	bool TurnLeft();
	bool TurnRight();


private:
	bool OpenGpio();
	bool CloseGpio();
	BaseCommand* motorOn;

	string m_motorPinA;
	string m_motorNameA;

	string m_motorPinB;
	string m_motorNameB;
};

#endif /* MOTORDEVICE_H_ */
