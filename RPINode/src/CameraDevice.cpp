/*
 * MotorDevice.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#include "CameraDevice.h"


CameraDevice::CameraDevice(string name,string imgPath):DeviceBase()
{
	m_imgPath = imgPath;
	m_name = name;
	TCommandSchema schema;
	schema.insert(TCommandSchemaPair("",""));
	m_getFrame = new BaseCommand("getFrame",this->m_name,schema);

	this->addCommand(m_getFrame);

}

CameraDevice::~CameraDevice() {

}

bool CameraDevice::dispatchCommand(BaseCommand command,Net::Http::ResponseWriter response)
{
	if(command == m_getFrame)
	{
		response.headers()
				.add<Net::Http::Header::Server>("pistache/0.1")
				.add<Net::Http::Header::ContentType>(MIME(Image, Jpeg));
		Net::Http::serveFile(response, m_imgPath.c_str()).then([](ssize_t bytes) {
			std::cout << "[INFO] Frame Sent " << bytes << " bytes" << std::endl;
		}, Async::NoExcept);
		return true;
	}
	return false;
}

