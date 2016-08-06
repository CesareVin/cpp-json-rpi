/*
 * RPINode.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#include "RPINode.h"

RPINode::RPINode():NodeBase() {
    this->setName("RpiNode");
    //MotorDevice(string name,string pinA,string nameA,string pinB,string nameB);
    m_leftMotor = new MotorDevice("LeftMotor",MOTOR_L_A_PIN,MOTOR_L_A_NAME,MOTOR_L_B_PIN,MOTOR_L_B_NAME);
    m_rightMotor = new MotorDevice("RIghtMotor",MOTOR_L_A_PIN,MOTOR_L_A_NAME,MOTOR_L_B_PIN,MOTOR_L_B_NAME);
    this->addDevice(m_leftMotor);
    this->addDevice(m_rightMotor);
}

RPINode::~RPINode() {

}

