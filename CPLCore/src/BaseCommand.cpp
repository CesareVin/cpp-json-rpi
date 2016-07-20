/*
 * BaseCommand.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: cesare
 */

#include "BaseCommand.h"

BaseCommand::BaseCommand(string name,string device,map<string,string> schema):m_name(name),
																			  m_device(device),
																			  m_requestSchema(schema)
{

}

BaseCommand::~BaseCommand() {
}

string BaseCommand::getName()
{
	return m_name;
}
void BaseCommand::setName(string name)
{
	m_name = name;
}

string BaseCommand::getDevice()
{
	return m_device;
}
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

web::json::value BaseCommand::AsJSON()
{
	web::json::value res = web::json::value::object();
	res[U("name")] = web::json::value::string(m_name);

	web::json::value jSchema = web::json::value::array(m_requestSchema.size());

	int idx = 0;
	for (auto iter = m_requestSchema.begin(); iter != m_requestSchema.end(); ++iter)
	{
		web::json::value jSchemaEntity = web::json::value::object();
		jSchemaEntity[U(iter->first)] = web::json::value::string(iter->second);
		jSchema[idx++] = jSchemaEntity;
	}
	res["RequestSchema"] = jSchema;
	return res;
}

