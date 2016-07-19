/*
 * ICommand.h
 *
 *  Created on: Jun 14, 2016
 *      Author: cesare
 */

#ifndef ICOMMAND_H_
#define ICOMMAND_H_

#include<string>
#include<vector>
#include<map>

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <random>

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

class ICommand
{
public:

	virtual ~ICommand(){};

	virtual string getName()
	{
		return m_name;
	}
	virtual void setName(string name)
	{
		m_name = name;
	}

	virtual string getDevice()
	{
		return m_device;
	}
	virtual void setDevice(string device)
	{
		m_device = device;
	}

	virtual void setRequestSchema(TCommandSchema schema)
	{
		m_requestSchema = schema;
	}
	virtual map<string,string> getRequestSchema()
	{
		return m_requestSchema;
	}

	virtual web::json::value AsJSON()
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
			//jCards[idx++] = iter->AsJSON();
		}
		res["RequestSchema"] = jSchema;
		return res;
	}

	//res[CARDS] = jCards

protected:

	string m_name;
	string m_device;
	TCommandSchema m_requestSchema;
	TCommandSchema m_responseSchema;
	TCommandParameter m_parameters;

};



#endif /* ICOMMAND_H_ */
