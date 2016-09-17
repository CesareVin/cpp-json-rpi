
#include "NodeBase.h"

NodeBase::NodeBase()
{

}

NodeBase::NodeBase(vector<DeviceBase*> devices)
{
	this->m_Devices = devices;
}

NodeBase::~NodeBase()
{
	/*for (auto &dev : this->m_Devices)	{ }*/
	while (!this->m_Devices.empty()){
	    DeviceBase* dev =this->m_Devices.back();
		m_Devices.pop_back();
		delete(dev);
	}
}

string NodeBase::getName()
{
	return this->m_name;
}
void NodeBase::setName(string name)
{
	this->m_name = name;
}
vector<DeviceBase*> NodeBase::getDevices()
{
	return this->m_Devices;
}
void NodeBase::addDevice(DeviceBase* device)
{
	this->m_Devices.push_back(device);
}
DeviceBase* NodeBase::removeDevice(int id)
{
	DeviceBase* dev =this->m_Devices.back();
	this->m_Devices.pop_back();
	return dev;
}

void NodeBase::init(Net::Address addr)
{
	httpEndpoint = std::make_shared<Net::Http::Endpoint>(addr);
	int treadNum = 1;
	auto opts = Net::Http::Endpoint::options()
			.threads(treadNum)
			.flags(Net::Tcp::Options::InstallSignalHandler);
	httpEndpoint->init(opts);

	// Routes::Post(router, "/record/:name/:value?", Routes::bind(&Server::doRecordMetric, this));
	//Routes::Get(router, url, Routes::bind(&NodeBase::dispatchRequest, this));

}

void NodeBase::open()
{
	httpEndpoint->setHandler(Http::make_handler<NodeBase>());
	httpEndpoint->serve();
}

void NodeBase::close()
{
	httpEndpoint->shutdown();
}

void NodeBase::onRequest(const Net::Http::Request& req,Net::Http::ResponseWriter response) {

	if (req.resource() == "/ping") {
		if (req.method() == Net::Http::Method::Get) {
			response.send(Net::Http::Code::Ok, "PONG");
		}

	}
	else if (req.resource() == "/static") {
		if (req.method() == Net::Http::Method::Get) {
			Net::Http::serveFile(response, "prova.txt").then([](ssize_t bytes) {;
				std::cout << "Sent " << bytes << " bytes" << std::endl;
			}, Async::NoExcept);
		}
	}

	if(req.resource()=="/")
	{
		if(req.method()== Net::Http::Method::Get)
		{
			response.send(Net::Http::Code::Ok, "RPINode");
		}
	}
	else if(req.resource()=="/commands")
	{
		if(req.method()==Net::Http::Method::Get)
		{
			for (int i = 0; i < m_Devices.size(); i++) {
				auto commands = m_Devices[i]->getCommands();
				for (int j = 0; j < commands.size(); j++) {

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
			message.reply(status_codes::OK, res);*/
		}
	}

}

