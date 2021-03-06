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
#include<algorithm>

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <iostream>


using namespace rapidjson;
using namespace std;

typedef std::map<std::string, std::string> TCommandSchema;
typedef std::pair<std::string, std::string> TCommandSchemaPair;
typedef std::map<string,string> TCommandParameter;


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

	void addParameter(string value);

	bool operator==(const BaseCommand *rhs);

protected:

	string m_name;
	string m_device;
	TCommandSchema m_requestSchema;
	TCommandSchema m_responseSchema;
	vector<string> m_parameters;
};

#endif /* BASECOMMAND_H_ */
