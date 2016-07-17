/*
 * MotorDevice.h
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#ifndef MOTORDEVICE_H_
#define MOTORDEVICE_H_

#include <IDevice.h>

class MotorDevice: public IDevice {
public:
	MotorDevice();
	virtual ~MotorDevice();
};

#endif /* MOTORDEVICE_H_ */
