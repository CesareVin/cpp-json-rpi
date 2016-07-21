/*
 * RPINode.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#include "RPINode.h"

RPINode::RPINode():NodeBase() {
    this->setName("RpiNode");
    m_leftMotor = new MotorDevice("LeftMotor");
    m_rightMotor = new MotorDevice("RIghtMotor");
    this->addDevice(m_leftMotor);
    this->addDevice(m_rightMotor);
}

RPINode::~RPINode() {

}

