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

protected:

	string m_name;
	string m_device;
	TCommandSchema m_requestSchema;
	TCommandSchema m_responseSchema;
	TCommandParameter m_parameters;

};



#endif /* ICOMMAND_H_ */
