/*
 * BaseCommand.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: cesare
 */

#include "BaseCommand.h"

/**
    * BaseCommand
    * Default costructor*/
BaseCommand::BaseCommand()
{

}
/**
    * BaseCommand
    * Parametrized costructor
    * @param -name    : string ,the command name.
    *        -device  : string , the device build this command.
    *        -schema  :  map<string,string> , dictionary that represent the request schema */
BaseCommand::BaseCommand(string name,string device,map<string,string> schema):m_name(name),
																			  m_device(device),
																			  m_requestSchema(schema),
																			  m_parameters()
{

}

/**
    * BaseCommand
    * destructor    */
BaseCommand::~BaseCommand() {
}

/**
    * getName
    * get the name of this command
    * @return string the name
    */
string BaseCommand::getName()
{
	return m_name;
}
/**
    * setName
    * set the name of the command
    * @param -name    : string that rappresent the command name.
    */
void BaseCommand::setName(string name)
{
	m_name = name;
}

/**
    * getDevice
    * get the device associated with this command
    * @return string the device name
    */
string BaseCommand::getDevice()
{
	return m_device;
}

/**
    * setDevice
    * set the device associated with this command
    * @param -name    : string that represent device name.
    */
void BaseCommand::setDevice(string device)
{
	m_device = device;
}

/**
    * setRequestSchema
    * set the schema for this command
    * @param -schema    : TCommandSchema the command request schema.
    */
void BaseCommand::setRequestSchema(TCommandSchema schema)
{
	m_requestSchema = schema;
}

/**
    * getRequestSchema
    * get the schema for this command
    * @return map<string,string> the command request schema.
    */
map<string,string> BaseCommand::getRequestSchema()
{
	return m_requestSchema;
}

/**
    * addParameter
    * add a parameter on the command
    * @param -value string the parameter to add.
    */
void BaseCommand::addParameter(string value)
{
	m_parameters.push_back(value);
}

/**
    * operator==
    * the equality compare command
    * @param -rhs the BaseCommand* to compare
    */
bool BaseCommand::operator==(const BaseCommand *rhs)
{
	if(this->m_name == rhs->m_name)
		return true;
	return false;
}

