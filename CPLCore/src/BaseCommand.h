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


#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#else
# include <sys/time.h>
#endif
#include "cpprest/json.h"
#include "cpprest/http_listener.h"
#include "cpprest/uri.h"
#include "cpprest/asyncrt_utils.h"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

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

	virtual web::json::value AsJSON();

protected:

	string m_name;
	string m_device;
	TCommandSchema m_requestSchema;
	TCommandSchema m_responseSchema;
	TCommandParameter m_parameters;
};

#endif /* BASECOMMAND_H_ */
