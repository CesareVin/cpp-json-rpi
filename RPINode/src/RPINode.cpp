/*
 * RPINode.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#include "RPINode.h"
#include "MotorDevice.h"

MotorDevice* leftMotor;
MotorDevice* rightMotor;

RPINode::RPINode() {
    this->setName("RpiNode");
    leftMotor = new MotorDevice("LeftMotor");
    rightMotor = new MotorDevice("RIghtMotor");
    this->addDevice(leftMotor);
    this->addDevice(rightMotor);
}

RPINode::~RPINode() {

}

