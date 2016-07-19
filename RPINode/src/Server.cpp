/*
 * Server.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: cesare
 */

#include "Server.h"



Server::Server() {
	// TODO Auto-generated constructor stub

}

Server::Server(utility::string_t url,NodeBase* node):m_listener(url)
{
	m_listener.support(methods::GET, std::bind(&Server::handle_get, this, std::placeholders::_1));
	m_listener.support(methods::PUT, std::bind(&Server::handle_put, this, std::placeholders::_1));
	m_listener.support(methods::POST, std::bind(&Server::handle_post, this, std::placeholders::_1));
	m_listener.support(methods::DEL, std::bind(&Server::handle_delete, this, std::placeholders::_1));
	m_Node = node;
}

Server::~Server() {
	// TODO Auto-generated destructor stub
}
pplx::task<void> Server::open()
{
	return m_listener.open();
}

pplx::task<void> Server::close()
{
	return m_listener.close();
}

void Server::handle_get(http_request message)
{
	 web::json::value res = web::json::value::object();
	 ucout <<  message.to_string() << endl;
	 ucout <<  message.body() << endl;
     auto paths = http::uri::split_path(http::uri::decode(message.relative_uri().path()));
     if (paths.empty())
	 {
		 res[U("node")] = web::json::value::string(m_Node->getName());
		 auto devices = this->m_Node->getDevices();
		 web::json::value jDevices = web::json::value::array(devices.size());
		 for(int i = 0 ; i < devices.size();i++)
		 {
			 web::json::value jDeviceEntity = web::json::value::object();
			 jDeviceEntity[U("name")] = web::json::value::string(devices[i]->getName());
			 ucout<<devices[i]->getName()<<endl;
			 auto commands = devices[i]->getCommands();
			 web::json::value jCommands = web::json::value::array(commands.size());
			 for(int j=0;j< commands.size();j++)
			 {
				 ucout<<commands[j]->getName()<<endl;
				 jCommands[j]= commands[j]->AsJSON();  //web::json::value::string(commands[j]->getName());
			 }
			 jDeviceEntity[U("commands")] = jCommands;
			 //jDevices["name"] = web::json::value::string(m_Node->getName());
			 jDevices[i] = jDeviceEntity;// web::json::value::string(devices[i]->getName());
		 }
		 /*for (auto iter = devices.begin(); iter != devices.end(); ++iter)
		 {

		 }*/

		 res[U("devices")] = jDevices;
		 //return res;

	 }
     /*CommandData cmd;
     cmd.command = "motorOn";
     cmd.value = "number"; cmd.AsJSON()*/
     message.reply(status_codes::OK, res);
     return;
}
void Server::handle_post(http_request message)
{
	ucout <<  message.to_string() << endl;
	ucout <<  message.body() << endl;
	auto paths = http::uri::split_path(http::uri::decode(message.relative_uri().path()));
	message.reply(status_codes::OK,"ok");

	if (paths.empty())
	{
	    	//message.reply(status_codes::OK, TablesAsJSON(U("Available Tables"), s_tables));
		return;
	}
	return;
}
void Server::handle_put(http_request message)
{
	ucout <<  message.to_string() << endl;

	auto paths = http::uri::split_path(http::uri::decode(message.relative_uri().path()));
	if (paths.empty())
	{
	    	//message.reply(status_codes::OK, TablesAsJSON(U("Available Tables"), s_tables));
		return;
	}
}
void Server::handle_delete(http_request message)
{
	ucout <<  message.to_string() << endl;

	auto paths = http::uri::split_path(http::uri::decode(message.relative_uri().path()));
	if (paths.empty())
	{
	    	//message.reply(status_codes::OK, TablesAsJSON(U("Available Tables"), s_tables));
		return;
	}
}
