/*
 * Server.h
 *
 *  Created on: Jul 15, 2016
 *      Author: cesare
 */

#ifndef SERVER_H_
#define SERVER_H_


#include <string>
#include <vector>

#include "NodeBase.h"
#include "http.h"
#include "router.h"
#include "endpoint.h"
#include <algorithm>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>

using namespace std;
using namespace Net;
using namespace Net::Rest;


class Server {
public:
	Server(Net::Address addr,std::string url,NodeBase*node);
	virtual ~Server();

	void open();
	void close();

private:
	void handle_get(const Rest::Request& request, Net::Http::ResponseWriter response);
	//void handle_put(http_request message);
	//void handle_post(http_request message);
	//void handle_delete(http_request message);

	//http_listener m_listener;
	NodeBase* m_Node;
	std::shared_ptr<Net::Http::Endpoint> httpEndpoint;
    Rest::Router router;
};

#endif /* SERVER_H_ */
