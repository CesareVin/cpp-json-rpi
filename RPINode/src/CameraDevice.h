/*
 * MotorDevice.h
 *
 *  Created on: Jul 14, 2016
 *      Author: cesare
 */

#ifndef CAMERADEVICE_H_
#define CAMERADEVICE_H_

#include <DeviceBase.h>
#include <string>
#include "BaseCommand.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "net.h"
#include "http.h"
#include "peer.h"
#include "http_headers.h"
#include "cookie.h"
#include "endpoint.h"

using namespace std;
using namespace Net;


class CameraDevice: public DeviceBase {
public:
	CameraDevice(string name,string imgPath);
	virtual ~CameraDevice();

	bool dispatchCommand(BaseCommand command,Net::Http::ResponseWriter response);


private:
	string m_imgPath;
	BaseCommand* m_getFrame;

};

#endif /* CAMERADEVICE_H_ */
