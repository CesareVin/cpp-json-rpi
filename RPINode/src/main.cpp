

//#include "Server.h"
#include "RPINode.h"

#include "http.h"
#include "router.h"

using namespace Net;

std::unique_ptr<RPINode> g_node;

int main(int argc, char *argv[])
{
    Net::Address addr(Net::Ipv4::any(), Net::Port(9081));
    g_node = std::unique_ptr<RPINode>(new RPINode());
    g_node.get()->init(addr);
    g_node.get()->open();
    
    return 0;
}