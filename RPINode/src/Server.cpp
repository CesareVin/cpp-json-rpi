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

Server::Server(utility::string_t url):m_listener(url)
{
	m_listener.support(methods::GET, std::bind(&Server::handle_get, this, std::placeholders::_1));
	m_listener.support(methods::PUT, std::bind(&Server::handle_put, this, std::placeholders::_1));
	m_listener.support(methods::POST, std::bind(&Server::handle_post, this, std::placeholders::_1));
	m_listener.support(methods::DEL, std::bind(&Server::handle_delete, this, std::placeholders::_1));
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
	 ucout <<  message.to_string() << endl;
	 ucout <<  message.body() << endl;
     auto paths = http::uri::split_path(http::uri::decode(message.relative_uri().path()));
     /*if (paths.empty())
	 {

	  }*/
     CommandData cmd;
     cmd.command = "motorOn";
     cmd.value = "number";
     message.reply(status_codes::OK, cmd.AsJSON());
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
