/*
 * BaseCommand.h
 *
 *  Created on: Jul 15, 2016
 *      Author: cesare
 */

#ifndef BASECOMMAND_H_
#define BASECOMMAND_H_

#include<string>
#include<vector>
#include<map>

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>


using namespace rapidjson;
using namespace std;

typedef std::map<std::string, std::string> TCommandSchema;
typedef std::pair<std::string, std::string> TCommandSchemaPair;
typedef std::pair<string,string> TCommandParameter;


class BaseCommand
{
public:
	explicit BaseCommand();
	explicit BaseCommand(string name,string device,map<string,string> schema);
	virtual ~BaseCommand();

	string getName();
	void setName(string name);

	string getDevice();
	void setDevice(string device);

	void setRequestSchema(TCommandSchema schema);
	map<string,string> getRequestSchema();

	virtual string AsJSON();

protected:

	string m_name;
	string m_device;
	TCommandSchema m_requestSchema;
	TCommandSchema m_responseSchema;
	TCommandParameter m_parameters;
};

#endif /* BASECOMMAND_H_ */
