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

#define MOTOR_L_A_PIN	"53"
#define MOTOR_L_A_NAME	"pioB21"
#define MOTOR_L_B_PIN	"55"
#define MOTOR_L_B_NAME	"pioB23"
#define MOTOR_R_A_PIN	"59"
#define MOTOR_R_A_NAME	"pioB27"
#define MOTOR_R_B_PIN	"47"
#define MOTOR_R_B_NAME	"pioB15"


class MotorDevice: public DeviceBase {
public:
	MotorDevice(string name);
	virtual ~MotorDevice();

	bool GoOn();
	bool GoBack();
	bool TurnLeft();
	bool TurnRight();


private:
	bool OpenGpio();
	bool CloseGpio();
	BaseCommand* motorOn;
};

#endif /* MOTORDEVICE_H_ */
