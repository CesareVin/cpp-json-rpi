/*
 * BaseCommand.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: cesare
 */

#include "BaseCommand.h"


BaseCommand::BaseCommand()
{

}
/**
    * BaseCommand
    * Default costructor
    * @param -name    : string ,the command name.
    *        -device  : string , the device build this command.
    *        -schema  :  map<string,string> , dictionary that represent the request schema */
BaseCommand::BaseCommand(string name,string device,map<string,string> schema):m_name(name),
																			  m_device(device),
																			  m_requestSchema(schema)
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

void BaseCommand::setRequestSchema(TCommandSchema schema)
{
	m_requestSchema = schema;
}
map<string,string> BaseCommand::getRequestSchema()
{
	return m_requestSchema;
}

/**
    * AsJSON
    * get the JSON representation of this cmmand
    * @return web::json::value the json
    */
string BaseCommand::AsJSON()
{
    
             
    StringBuffer s;
    Writer<StringBuffer> writer(s);

        writer.StartObject();
        
        writer.Key("name");
        writer.String(m_name.c_str(), static_cast<SizeType>(m_name.length()));
        writer.Key("device");
        writer.String(m_device.c_str());
        //writer.String(m_name);

        writer.Key("RequestSchema");

        writer.StartArray();
        for (auto iter = m_requestSchema.begin(); iter != m_requestSchema.end(); ++iter)
        {
            writer.StartObject();
            writer.Key(iter->first.c_str(),static_cast<SizeType>(iter->first.length()));
            writer.String(iter->second.c_str());
            writer.EndObject();
        }
        writer.EndArray();

        return s.GetString();
  
}

