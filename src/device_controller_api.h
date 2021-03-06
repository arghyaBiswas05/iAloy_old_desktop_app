#ifndef DEVICE_CONTROLLER_API_H
#define DEVICE_CONTROLLER_API_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <iostream>
#include <string>
#include <fstream>
#include <QObject>

#include "connect_init.h"

using namespace std;

class device_controller_api : public ialoy_web_api
{

private:
	string protocol = "https://";
	string sub_domain = "ialoy";
	string domain = "arghyabiswas.com/";
	string dco_req_manager = "device_controller";

public:
	string url = protocol+sub_domain+"."+domain+dco_req_manager;
	string req_url;

public:
	void set_device_controller_api_request(device_controller_api_request_type device_controller_api_request);
	string get_device_controller_req_url();
};

#endif // DEVICE_CONTROLLER_API_H