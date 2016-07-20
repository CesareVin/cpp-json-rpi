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

class MotorDevice: public DeviceBase {
public:
	MotorDevice(string name);
	virtual ~MotorDevice();

private:
	BaseCommand* motorOn;
};

#endif /* MOTORDEVICE_H_ */
