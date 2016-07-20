#include <cpprest/http_client.h>
#include "cpprest/http_listener.h"

#include "Server.h"
#include "RPINode.h"

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

std::unique_ptr<Server> g_http;
std::unique_ptr<RPINode> g_node;

void on_initialize(const string_t& address)
{
    // Build our listener's URI from the configured address and the hard-coded path "blackjack/dealer"

    uri_builder uri(address);
    uri.append_path(U("api/node"));

    auto addr = uri.to_uri().to_string();
    g_http = std::unique_ptr<Server>(new Server(addr,g_node.get()));
    g_http->open().wait();

    ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;

    return;
}

void on_shutdown()
{
    g_http->close().wait();
    return;
}
#ifdef _WIN32
int wmain(int argc, wchar_t *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    g_node = std::unique_ptr<RPINode>(new RPINode());
    utility::string_t port = U("34569");
    if(argc == 2)
    {
        port = argv[1];
    }

    utility::string_t address = U("http://localhost:");
	//utility::string_t address = U("http://192.168.1.114:");
    address.append(port);

    on_initialize(address);
    std::cout << "Press ENTER to exit." << std::endl;

    std::string line;
    std::getline(std::cin, line);

    on_shutdown();
    return 0;
}