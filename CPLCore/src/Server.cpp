/*
 * Server.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: cesare
 */

#include "Server.h"

Server::Server(Net::Address addr,std::string url,NodeBase* node):m_Node(node),httpEndpoint(std::make_shared<Net::Http::Endpoint>(addr))
{
	 int treadNum = 1;
	 auto opts = Net::Http::Endpoint::options()
            .threads(treadNum)
            .flags(Net::Tcp::Options::InstallSignalHandler);
        httpEndpoint->init(opts);
		    
       // Routes::Post(router, "/record/:name/:value?", Routes::bind(&Server::doRecordMetric, this));
        Routes::Get(router, url, Routes::bind(&Server::handle_get, this));
       // Routes::Get(router, "/ready", Routes::bind(&Server::handleReady));
       // Routes::Get(router, "/auth", Routes::bind(&Server::doAuth, this));

}

Server::~Server() {
	delete m_Node;
}
void Server::open()
{
	httpEndpoint->setHandler(router.handler());
	httpEndpoint->serve();
}

void Server::close()
{
	httpEndpoint->shutdown();
}

void Server::handle_get(const Rest::Request& req, Net::Http::ResponseWriter resp)
{

	  if (req.resource() == "/commands") {
            resp.timeoutAfter(std::chrono::seconds(2));
      }
      else if (req.resource() == "/static") {
            if (req.method() == Net::Http::Method::Get) {
                Net::Http::serveFile(resp, "README.md").then([](ssize_t bytes) {;
                    std::cout << "Sent " << bytes << " bytes" << std::endl;
                }, Async::NoExcept);
            }
        }
	/*
	 web::json::value res = web::json::value::object();
	 ucout <<  message.to_string() << endl;
	 ucout <<  message.body() << endl;
     auto paths = http::uri::split_path(http::uri::decode(message.relative_uri().path()));
     if (paths.empty()) {
		 res[U("node")] = web::json::value::string(m_Node->getName());
		 auto devices = this->m_Node->getDevices();
		 web::json::value jDevices = web::json::value::array(devices.size());
		 for (int i = 0; i < devices.size(); i++) {
			 web::json::value jDeviceEntity = web::json::value::object();
			 jDeviceEntity[U("name")] = web::json::value::string(devices[i]->getName());
			 ucout << devices[i]->getName() << endl;
			 auto commands = devices[i]->getCommands();
			 web::json::value jCommands = web::json::value::array(commands.size());
			 for (int j = 0; j < commands.size(); j++) {
				 ucout << commands[j]->getName() << endl;
				 jCommands[j] = commands[j]->AsJSON();
			 }
			 jDeviceEntity[U("commands")] = jCommands;
			 jDevices[i] = jDeviceEntity;
		 }
		 res[U("devices")] = jDevices;
	 }
     message.reply(status_codes::OK, res);
     return;
	 */
	resp.send(Http::Code::Ok, "No Account");
}
/*
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

*/