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
#include <sys/time.h>

#include "cpprest/json.h"
#include "cpprest/http_listener.h"
#include "cpprest/uri.h"
#include "cpprest/asyncrt_utils.h"
#include "NodeBase.h"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

class Server {
public:
	Server(utility::string_t url,NodeBase*node);
	virtual ~Server();

	pplx::task<void> open();
	pplx::task<void> close();

private:
	void handle_get(http_request message);
	void handle_put(http_request message);
	void handle_post(http_request message);
	void handle_delete(http_request message);

	http_listener m_listener;
	NodeBase* m_Node;

};

#endif /* SERVER_H_ */
