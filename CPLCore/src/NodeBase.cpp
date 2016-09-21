
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
	Routes::Get(router, "api/v1/commands", Routes::bind(&NodeBase::onCommands, this));
    Routes::Get(router, "", Routes::bind(&NodeBase::onIndex, this));
    Routes::Put(router, "api/v1/commands",Routes::bind(&NodeBase::onCommands, this));
}

void NodeBase::open()
{

    httpEndpoint->setHandler(router.handler());
	//httpEndpoint->setHandler(Http::make_handler<NodeBase>());
	httpEndpoint->serve();
}

void NodeBase::close()
{
	httpEndpoint->shutdown();
}

void NodeBase::onCommands(const Net::Http::Request& req,Net::Http::ResponseWriter response)
{
    if(req.method() ==  Net::Http::Method::Get) {
        cout<<"[INFO] GET Commands Handler "<<endl;
        StringBuffer s;
        Writer<StringBuffer> writer(s);
        writer.StartObject();
        writer.Key("devices");
        writer.StartArray();
        for (int i = 0; i < m_Devices.size(); i++) {
            auto commands = m_Devices[i]->getCommands();
            //writer.Key("name");
            //writer.String(m_Devices[i]->getName().c_str());
            //writer.Key("commands");
            writer.Key(m_Devices[i]->getName().c_str());
            writer.StartArray();
            for (int j = 0; j < commands.size(); j++) {
                writer.StartObject();
                writer.Key("command");
                writer.String(commands[j]->getName().c_str());
                writer.Key("device");
                writer.String(commands[j]->getDevice().c_str());
                writer.Key("RequestSchema");
                writer.StartArray();
                for (auto iter = commands[j]->getRequestSchema().begin();
                     iter != commands[j]->getRequestSchema().end(); ++iter) {
                    writer.StartObject();
                    writer.Key(iter->first.c_str(), static_cast<SizeType>(iter->first.length()));
                    writer.String(iter->second.c_str());
                    writer.EndObject();
                }
                writer.EndArray();


                /*auto out = commands[j]->AsJSON();
                out.erase (std::remove(out.begin(), out.end(), '\\'), out.end());
                writer.String(out.c_str());*/
                writer.EndObject();
            }
            writer.EndArray();

        }
        writer.EndArray();
        writer.EndObject();

        response.send(Net::Http::Code::Ok, s.GetString());
        cout<<"[INFO] Response sent "<<endl;
    }
    else if(req.method() == Net::Http::Method::Put)
    {
        cout<<"[INFO] PUT Commands Handler "<<endl;
        Document d;
        //parse the request body
        d.Parse(req.body().c_str());
        //check if command exist
        if(!d.HasMember("command"))
        {
            cout<<"[ERR] command is missing"<<endl;
            response.send(Net::Http::Code::Forbidden, "command not present");
            return;
        }
        //get the command from the JSON
        Value& cmd = d["command"];
        //check if command is a string
        if(!cmd.IsString())
        {
            cout<<"[ERR] command type can't match"<<endl;
            response.send(Net::Http::Code::Forbidden, "command type can't match");
            return;
        }

        cout<<"[INFO] Command :"<<cmd.GetString()<<endl;
        //check if parameters exist
        if(!d.HasMember("parameters"))
        {
            cout<<"[ERR] parameters is missing"<<endl;
            response.send(Net::Http::Code::Forbidden, "parameters not present");
            return;
        }

        const Value& par = d["parameters"];
        //check if parameters is an array
        if(!par.IsArray())
        {
            cout<<"[ERR] parameters type can't match"<<endl;
            response.send(Net::Http::Code::Forbidden, "parameters type can't match");
            return;
        }

        //build the command
        BaseCommand comm;
        comm.setName(cmd.GetString());

        //add parameters
        for (SizeType i = 0; i < par.Size(); i++) {
            comm.addParameter(par[i].GetString());
        }

        if(d.HasMember("device"))
        {
            Value& devValue = d["command"];
            if(devValue.IsString())
                comm.setDevice(devValue.GetString());
            else
                cout<<"[ERR] device type can't match"<<endl;
        }

        bool isFound = false;
        for (int i = 0; i < m_Devices.size(); i++) {
            auto commands = m_Devices[i]->getCommands();
            for (int j = 0; j < commands.size(); j++) {
                string command = cmd.GetString();
                if(commands[j]->getName() == command)
                {
                    isFound = true;
                    cout<<"[INFO] Device :"<<m_Devices[i]->getName()<<endl;
                    m_Devices[i]->dispatchCommand(comm,response.clone());
                }
            }

        }
        if(!isFound)
        {
            cout<<"[INFO] command is not supported "<<endl;
            response.send(Net::Http::Code::Forbidden, "command not supported");
        }

    }
}

void NodeBase::onIndex(const Net::Http::Request& req,Net::Http::ResponseWriter response)
{
    Net::Http::serveFile(response, "index.html").then([](ssize_t bytes) {
        //std::cout << "Sent " << bytes << " bytes" << std::endl;
    }, Async::NoExcept);
}
