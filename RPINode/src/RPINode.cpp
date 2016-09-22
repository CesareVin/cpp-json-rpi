/*
 * RPINode.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#include "RPINode.h"

/**
    * DeviceBase
    * Default constructor*/
RPINode::RPINode():NodeBase() {
    this->setName("RpiNode");

    m_Motor = new MotorDevice("Motors",
                              MOTOR_L_A_PIN,
                              MOTOR_L_A_NAME,
                              MOTOR_L_B_PIN,
                              MOTOR_L_B_NAME,
                              MOTOR_R_A_PIN,
                              MOTOR_R_A_NAME,
                              MOTOR_R_B_PIN,
                              MOTOR_R_B_NAME);
    m_Camera = new CameraDevice("Camera","/home/cesare/Desktop/cam.jpg");

    this->addDevice(m_Motor);
    this->addDevice(m_Camera);

}

RPINode::~RPINode() {

}




