/*
 * Server.h
 *
 *  Created on: Jul 15, 2016
 *      Author: cesare
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "common.h"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

class Server {
public:
	Server();
	Server(utility::string_t url);
	virtual ~Server();

	 pplx::task<void> open();// { /*return m_listener.open();*/ }
	 pplx::task<void> close();// { return m_listener.close(); }

private:
	void handle_get(http_request message);
	void handle_put(http_request message);
	void handle_post(http_request message);
	void handle_delete(http_request message);

	http_listener m_listener;

};

enum CardSuit { CS_Heart, CS_Diamond, CS_Club, CS_Spade };
enum CardValue { CV_None, CV_Ace, CV_Two, CV_Three, CV_Four, CV_Five, CV_Six, CV_Seven, CV_Eight, CV_Nine, CV_Ten, CV_Jack, CV_Queen, CV_King };

#define COMMAND U("command")
#define VALUE U("value")

struct CommandData
{
    //CardSuit suit;
    //CardValue value;
	string command;
	string value;

    static CommandData FromJSON(const web::json::object & object)
    {
    	CommandData result;
    	result.command = object.at(COMMAND).as_string();
    	result.value = object.at(VALUE).as_string();
        //result.suit = (CardSuit)object.at(SUIT).as_integer();
        //result.value = (CardValue)object.at(VALUE).as_integer();
        return result;
    }

    web::json::value AsJSON() const
    {
        web::json::value result = web::json::value::object();
        result[COMMAND] = web::json::value::string(command);
        result[VALUE] = web::json::value::string(value);
        return result;
    }
};

#endif /* SERVER_H_ */
