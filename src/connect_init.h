#ifndef CONNECT_INIT_H
#define CONNECT_INIT_H

// #include <Poco/Net/HTTPClientSession.h>
// #include <Poco/Net/HTTPRequest.h>
// #include <Poco/Net/HTTPResponse.h>
// #include <Poco/StreamCopier.h>
// #include <Poco/Path.h>
// #include <Poco/URI.h>
// #include <Poco/Exception.h>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <iostream>
#include <string>
#include <fstream>
#include <QObject>

#include "ialoy_data.h"

// using namespace Poco::Net;
// using namespace Poco;
using namespace std;

class ialoy_web_api : public ialoy_main_data
{

private:
	//QNetworkAccessManager *manager;

	string protocol = "http://";
	string sub_domain = "ialoy";
	string domain = "arghyabiswas.com";
	string api = "desktop_api";
	string req_manager = "req_mngr.php";
	string url = protocol+sub_domain+"."+domain+"/"+api+"/"+req_manager;
	string req_url;

public:
	QNetworkRequest NetworkRequest;
	// main operational functions.
	void genarate_url(api_request_type genarate_url_flag);
	void fetch_pi_name();
	void check_email_pi_connection();
	void check_product_id();
	void login();
	void pi_reg_status();
	void email_reg_status();
	void fetch_user_details();
	void send_otp();
	void reg_new_pi();
	string get_req_url();

};

#endif //CONNECT_INIT_H
