/*
 * RPINode.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#include "RPINode.h"

RPINode::RPINode():NodeBase() {
    this->setName("RpiNode");

    m_Motor = new MotorDevice("LeftMotor",
                              MOTOR_L_A_PIN,
                              MOTOR_L_A_NAME,
                              MOTOR_L_B_PIN,
                              MOTOR_L_B_NAME,
                              MOTOR_R_A_PIN,
                              MOTOR_R_A_NAME,
                              MOTOR_R_B_PIN,
                              MOTOR_R_B_NAME);

    this->addDevice(m_Motor);

}

RPINode::~RPINode() {

}




