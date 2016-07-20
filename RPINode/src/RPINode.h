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

class RPINode : public NodeBase {
public:
	RPINode();
	virtual ~RPINode();

private:
	MotorDevice* m_leftMotor;
	MotorDevice* m_rightMotor;
};

#endif /* RPINODE_H_ */
