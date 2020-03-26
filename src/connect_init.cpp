#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <QObject>

#include "connect_init.h"
#include "main.h"
#include "hardware.h"

using namespace std;

string ialoy_web_api::get_req_url()
{
	return this->req_url;
}

void ialoy_web_api::set_api_request(api_request_type genarate_url_flag)
{
	api_request = genarate_url_flag;
	string aco = to_string(genarate_url_flag);
	this->set_api_error_msg("");

	switch(genarate_url_flag)
	{
		case CHECK_PI_STATUS:
			if(this->get_pi_add() == "")
				this->set_pi_add();
			this->req_url = this->url+"?aco="+aco+"&pi_add="+this->get_pi_add();
			break;

		case GET_PI_NAME:
			if(this->get_pi_add() == "")
				this->set_pi_add();
			this->req_url = this->url+"?aco="+aco+"&pi_add="+this->get_pi_add();
			break;

		case CHECK_EMAIL_STATUS:
			if(this->get_email() != "")
				this->req_url = this->url+"?aco="+aco+"&email="+this->get_email();
			else
				this->set_api_error_msg("Email can't be blank...");
			break;

		case CHECK_EMAIL_CONNECTED_PI:
			if(this->get_pi_add() == "")
				this->set_pi_add();
			if(this->get_email() != "")
				this->req_url = this->url+"?aco="+aco+"&email="+this->get_email()+"&pi_add="+this->get_pi_add();
			else
				this->set_api_error_msg("Email can't be blank...");
			break;

		case GET_USER_DETAILS:
			if(this->get_email() != "")
				this->req_url = this->url+"?aco="+aco+"&email="+this->get_email();
			else
				this->set_api_error_msg("Email can't be blank...");
			break;

		case CHECK_PRODUCT_KEY_STATUS:
			if(this->get_product_id() != "")
				this->req_url = this->url+"?aco="+aco+"&prod_id="+this->get_product_id();
			else
				this->set_api_error_msg("Product Id can't be blank.");
			break;

		case SEND_OTP:
			if(this->get_email() != "")
				this->req_url = this->url+"?aco="+aco+"&su_mail="+this->get_email();
			else
				this->set_api_error_msg("Email can't be blank...");
			break;

		case VERIFY_OTP:
			if(this->get_email() != "" && this->get_otp() != "")
				this->req_url = this->url+"?aco="+aco+"&su_mail="+this->get_email()+"&otp="+this->get_otp();
			else
				this->set_api_error_msg("Email and OTP can't be blank...");
			break;

		case REGISTER_NEW_PI:
			if(reg_user_type_flag == NEW_USER)
			{
				if((this->get_email() != "") && (this->get_first_name() !="") && (this->get_last_name() != "") && (this->get_password() != "") && (this->get_pi_add() != "") && (this->get_pi_name() != "") && (this->get_product_id() != ""))
					this->req_url = this->url+"?aco="+aco+"&type="+to_string(reg_user_type_flag)+"&prod_key="+this->get_product_id()+"&pi_add="+this->get_pi_add()+"&su_mail="+this->get_email()+ \
							"&pi_name="+this->get_pi_name()+"&f_name="+this->get_first_name()+"&l_name="+this->get_last_name()+"&password="+this->get_password();
				else
					this->set_api_error_msg("One or more data(s) are missing...");
			}
			else
			{
				if((this->get_email() != "") && (this->get_pi_add() != "") && (this->get_pi_name() != "") && (this->get_product_id() != "") )
					this->req_url = this->url+"?aco="+aco+"&type="+to_string(reg_user_type_flag)+"&prod_key="+this->get_product_id()+"&pi_add="+this->get_pi_add()+"&su_mail="+this->get_email()+"&pi_name="+this->get_pi_name();
				else
					this->set_api_error_msg("One or more data(s) are missing...");
			}
			break;

		case LOGIN:
			if((this->get_email() != "") && (this->get_password() != ""))
				this->req_url = this->url+"?aco="+aco+"&email="+this->get_email()+"&pi_add="+this->get_pi_add()+"&password="+this->get_password();
			else
				this->set_api_error_msg("Email and password can't be blank.");
			break;

		case VERIFY_TOKEN:
			break;
		default:
			break;
	}

	cout << this->req_url << endl;
	NetworkRequest.setUrl(QString::fromStdString(this->req_url));
}

void ialoy_web_api::fetch_pi_name()
{
	this->set_api_error_msg("");
	if(this->get_pi_add() == "")
		this->set_pi_add();

	api_request = GET_PI_NAME;
	this->req_url = this->url+"?aco="+to_string(api_request)+"&pi_add="+this->get_pi_add();
}

void ialoy_web_api::check_email_pi_connection()
{
	this->set_api_error_msg("");
	if(this->get_pi_add() == "")
		this->set_pi_add();

	if(this->get_email() != "")
	{
		api_request = CHECK_EMAIL_CONNECTED_PI;
		this->req_url = this->url+"?aco="+to_string(api_request)+"&email="+this->get_email()+"&pi_add="+this->get_pi_add();
	}
	else
	{
		this->set_api_error_msg("Email can't be blank...");
	}
}

void ialoy_web_api::pi_reg_status()
{
	this->set_api_error_msg("");
	if(this->get_pi_add() == "")
		this->set_pi_add();

	api_request = CHECK_PI_STATUS;
	this->req_url = this->url+"?aco="+to_string(api_request)+"&pi_add="+this->get_pi_add();
}

void ialoy_web_api::email_reg_status()
{
	this->set_api_error_msg("");

	if(this->get_email() != "")
	{
		api_request = CHECK_EMAIL_STATUS;
		this->req_url = this->url+"?aco="+to_string(api_request)+"&email="+this->get_email();
	}
	else
	{
		this->set_api_error_msg("Email can't be blank...");
	}

}

void ialoy_web_api::fetch_user_details()
{
	this->set_api_error_msg("");

	if(this->get_email() != "")
	{
		api_request = GET_USER_DETAILS;
		this->req_url = this->url+"?aco="+to_string(api_request)+"&email="+this->get_email();
	}
	else
	{
		this->set_api_error_msg("Email can't be blank...");
	}
}

void ialoy_web_api::check_product_id()
{
	this->set_api_error_msg("");

	if(this->get_product_id() != "")
	{
		api_request = CHECK_PRODUCT_KEY_STATUS;
		this->req_url = this->url+"?aco="+to_string(api_request)+"&prod_id="+this->get_product_id();
	}
	else
	{
		this->set_api_error_msg("Product Id can't be blank.");
	}
}

void ialoy_web_api::login()
{
	this->set_api_error_msg("");

	if((this->get_email() != "") && (this->get_password() != ""))
	{
		api_request = LOGIN;
		this->req_url = this->url+"?aco="+to_string(api_request)+"&email="+this->get_email()+"&pi_add="+this->get_pi_add()+"&password="+this->get_password();
	}
	else
		this->set_api_error_msg("Email and password can't be blank.");
}

void ialoy_web_api::send_otp()
{
	this->set_api_error_msg("");

	if(this->get_email() != "")
	{
		api_request = SEND_OTP;
		this->req_url = this->url+"?aco="+to_string(api_request)+"&su_mail="+this->get_email();
	}
	else
		this->set_api_error_msg("Email can't be blank...");
}

void ialoy_web_api::reg_new_pi()
{
	this->set_api_error_msg("");

	if(reg_user_type_flag ==  NEW_USER)
	{
		if((this->get_email() != "") && (this->get_first_name() !="") && (this->get_last_name() != "") && (this->get_password() != "") && (this->get_pi_add() != "") && (this->get_pi_name() != "") && (this->get_product_id() != "") )
		{
			api_request = REGISTER_NEW_PI;
			this->req_url = this->url+"?aco="+to_string(api_request)+"&type="+to_string(reg_user_type_flag)+"&prod_key="+this->get_product_id()+"&pi_add="+this->get_pi_add()+"&su_mail="+this->get_email()+ \
					"&pi_name="+this->get_pi_name()+"&f_name="+this->get_first_name()+"&l_name="+this->get_last_name()+"&password="+this->get_password();
		}
		else
			this->set_api_error_msg("One or more data(s) are missing...");
	}
	else
	{
		if((this->get_email() != "") && (this->get_pi_add() != "") && (this->get_pi_name() != "") && (this->get_product_id() != "") )
		{
			api_request = REGISTER_NEW_PI;
			this->req_url = this->url+"?aco="+to_string(api_request)+"&type="+to_string(reg_user_type_flag)+"&prod_key="+this->get_product_id()+"&pi_add="+this->get_pi_add()+"&su_mail="+this->get_email()+"&pi_name="+this->get_pi_name();
		}
		else
            this->set_api_error_msg("One or more data(s) are missing...");
	}
}
