

#include "Server.h"
#include "RPINode.h"

#include "http.h"
#include "router.h"

using namespace Net;

std::unique_ptr<Server> g_http;
std::unique_ptr<RPINode> g_node;

int main(int argc, char *argv[])
{
    g_node = std::unique_ptr<RPINode>(new RPINode());
    Net::Address addr(Net::Ipv4::any(), Net::Port(9081));
    g_http = std::unique_ptr<Server>(new Server(addr,"rpinode",g_node.get()));

    g_http.get()->open();
    
    return 0;
}