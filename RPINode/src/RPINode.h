/*
 * RPINode.h
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#ifndef RPINODE_H_
#define RPINODE_H_

#include "NodeBase.h"
#include "MotorDevice.h"
#include "CameraDevice.h"

#include<string>
#include<vector>
#include <sys/time.h>
#include "router.h"

#include "NodeBase.h"
#include "DeviceBase.h"

using namespace std;


#define MOTOR_L_A_PIN	"53"
#define MOTOR_L_A_NAME	"pioB21"
#define MOTOR_L_B_PIN	"55"
#define MOTOR_L_B_NAME	"pioB23"
#define MOTOR_R_A_PIN	"59"
#define MOTOR_R_A_NAME	"pioB27"
#define MOTOR_R_B_PIN	"47"
#define MOTOR_R_B_NAME	"pioB15"

class RPINode : public NodeBase {
public:
	RPINode();
	virtual ~RPINode();

private:
	MotorDevice* m_Motor;
	CameraDevice* m_Camera;
};

#endif /* RPINODE_H_ */
