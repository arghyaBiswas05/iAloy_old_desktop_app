#ifndef IALOY_DATA_H
#define IALOY_DATA_H

#include <iostream>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QLabel>
#include <QLinkedList>

#include "hardware.h"

using namespace std;

enum email_connected_pi_status
{
	INVALID_USER_REGISTERED_PI = 0,
	PERMANENT_USER_REGISTERED_PI,
	SUPER_USER_REGISTERED_PI,
	PERMANENT_USER_UNREGISTERED_PI,
	INVALID_USER_UNREGISTERED_PI
};

enum setUpLineEditStat
{
	GET_INPUT_EMAIL_MODE = 0,
	GET_INPUT_PROD_KEY_MODE,
	GET_INPUT_PASSWORD_MODE,
	GET_INPUT_OTP_MODE,
	GET_INPUT_PI_NAME_MODE
};

enum product_Key_status
{
	PRODUCT_KEY_AVAILABLE = 0,
	PRODUCT_KEY_NOT_AVAILABLE,
	PRODUCT_KEY_INVALID = -1
};

enum pi_reg_status
{
	PI_NOT_REGISTERED = 0,
	PI_REGISTERED
};

enum reg_user_type
{
	EXISTING_USER = 0,
	NEW_USER
};

enum user_login_status
{
	LOGIN_FAIL = 0,
	LOGIN_SUCCESS,
	LOGIN_TOKEN_ERROR
};

enum otp_send_status
{
	OTP_SEND_UNEXPECTED = -1,
	OTP_SEND_FAIL = 0,
	OTP_SEND_SUCCESS
};

enum otp_verification_status
{
	OTP_NOT_VERIFIED = 0,
	OTP_VERIFIED
};

enum requested_url
{
	LOGIN_MANAGER_API = 1,
	DEVICE_MANAGER_API
};

enum api_request_type
{
	CHECK_PI_STATUS = 0,
	GET_PI_NAME,
	CHECK_EMAIL_STATUS,
	CHECK_EMAIL_CONNECTED_PI,
	GET_USER_DETAILS,
	CHECK_PRODUCT_KEY_STATUS,
	SEND_OTP,
	VERIFY_OTP,
	REGISTER_NEW_PI,
	LOGIN,
	LOGIN_USING_TOKEN
};

enum device_controller_api_request_type
{
	GET_DEVICE_DETAIL_STATUS = 1,
	GET_ROOM_DEVICE_LIST,
	GET_ROOM_DEVICE_STATUS,
	UPDATE_STATUS,
	UPDATE_RANGE,
	UPDATE_STATUS_FOR_PI,
	UPDATE_RANGE_FOR_PI,
	GET_I2C_DATA,
	ADD_NEW_MODULE,
	VERIFY_PASSWORD,
	UPDATE_PASSWORD,
	GET_OTHER_USERS_INFO,
	DEVICE_CONTROLLER_LOGIN_USING_TOKEN = 20,
};

enum module_linking_stage
{
	MODULE_NEED_TO_BE_LINKED = 0,
	MODULE_LINKING_PROGRESS,
	MODULE_LINKING_DONE,
	MODULE_LINKING_FAILED
};

enum module_type
{
	ATTINY88 = 0,
	ATMEGA328P
};

enum module_manager_window_tabs
{
	LINK_MODULE_TAB = 0,
	BURN_MODULE_TAB,
	BURN_TAB,
};

enum api_response_status
{
	RESPONSE_FAILED = 0,
	RESPONSE_SUCCESS,
	RESPONSE_UNEXPECTED = 9,
};

class ialoy_main_data{

private:
	// for login manager
	string pi_add, pi_name, product_id, password, first_name, last_name, phone, otp, api_error_msg, \
		device_controller_api_error_msg, email, token;

	// response varibles for device controller
	string device_controller_login_using_token_response,get_device_detail_status_response, \
		get_room_device_list_response, get_room_device_status_response, update_status_response, \
		update_range_response, get_connected_pi_list_response, update_status_for_pi_response, \
		update_range_for_pi_response, get_i2c_data_response, add_new_module_response, verify_password_response, \
		update_password_response, get_other_users_info_response;

	// response varibles for login manager
	string check_pi_status_response, check_email_status_response, check_email_connected_pi_response, \
		get_user_details_response, check_product_key_status_response, send_otp_response, verify_otp_response, \
		register_new_pi_response, login_response, login_using_token_response, get_pi_name_response;


	// resource variables
	string user = "/usr/";
	string share = "share/";
	string iAloy_folder = "iAloy/";

	string conf_folder = ".conf/";
	string photos_folder = "photos/";
	string scripts_folder = "scripts/";

	string ucp_file = "credential.json";
	string mainwindow_bg_file = "mainwindow.jpg";
	string dashboard_bg_file = "dashboard.jpg";
	string keyboad_icon = "keyboard.png";
	string settings_icon = "setting.png";
	string wifi_icon = "wifi.png";
	string update_icon = "update.png";
	string update_brown_icon = "update_brown.png";
	string power_icon = "power.png";
	string ic_normal_icon = "ic_normal.png";
	string ic_plus_brown_icon = "ic_plus_brown.png";
	string ic_plus_white_icon = "ic_plus_white.png";
	string ic_warning_icon = "ic_warning.png";
	string refresh_icon = "refresh.png";
	string interface_up_script = "iAloy-interface-up.sh";

	string user_credential_path = user + share + iAloy_folder + conf_folder + ucp_file;
	string mainwindow_bg_file_path = user + share + iAloy_folder + photos_folder + mainwindow_bg_file;
	string dashboard_bg_file_path = user + share + iAloy_folder + photos_folder + dashboard_bg_file;
	string keyboad_icon_path = user + share + iAloy_folder + photos_folder + keyboad_icon;
	string settings_icon_path = user + share + iAloy_folder + photos_folder + settings_icon;
	string wifi_icon_path = user + share + iAloy_folder + photos_folder + wifi_icon;
	string update_icon_path = user + share + iAloy_folder + photos_folder + update_icon;
	string update_brown_icon_path = user + share + iAloy_folder + photos_folder + update_brown_icon;
	string power_icon_path = user + share + iAloy_folder + photos_folder + power_icon;
	string ic_narmal_icon_path = user + share + iAloy_folder + photos_folder + ic_normal_icon;
	string ic_plus_brown_icon_path = user + share + iAloy_folder + photos_folder + ic_plus_brown_icon;
	string ic_plus_white_icon_path = user + share + iAloy_folder + photos_folder + ic_plus_white_icon;
	string ic_warning_icon_path = user + share + iAloy_folder + photos_folder + ic_warning_icon;
	string refresh_icon_path = user + share + iAloy_folder + photos_folder + refresh_icon;
	string interface_up_script_path = user + share + iAloy_folder + scripts_folder + interface_up_script;

	// for dev_controller class
	string d_id, status, range, mod_add, pin;

public:
	pi_reg_status pi_reg_status_flag;
	api_request_type api_request;
	email_connected_pi_status email_connected_pi_status_flag;
	user_login_status user_login_status_flag;
	reg_user_type reg_user_type_flag;
	product_Key_status product_Key_status_flag;
	otp_send_status otp_send_status_flag;
	otp_verification_status otp_verification_status_flag;
	device_controller_api_request_type device_controller_api_request_type_flag;
	module_type module_type_flag;

	string api_i2c_data;

	// global network_manager variable
	QNetworkAccessManager *NetworkManager, *DBNetworkManager;
	QNetworkRequest NetworkRequest;

	struct btn_node
	{
		QPushButton *btn;
		QSlider *slider;
		QLabel *label;
		QString device_id;
		QString device_name;
		QString room_name;
		int btn_state;
		int slider_val;
		int pin_num;
		int mod_add;
		bool is_var;
	};

	struct mod_data_node
	{
		int mod_add;
		int current_web;
		int prev_web;
		int current_mod;
		int prev_mod;
	};

	struct version_details_node
	{
		QString version;
		QString date;
		QString details;
		int size;
		QString url;
	};

	struct other_user_info_node
	{
		int u_id;
		QString first_name;
		QString last_name;
		QString email;
	};

	QLinkedList<struct btn_node*> btn_list;
	QLinkedList<struct mod_data_node*> mod_data_list;
	QLinkedList<struct version_details_node*> version_details_list;
	QLinkedList<struct other_user_info_node*> other_user_info_list;

	// saved credential manager
	bool saved_credential_manager();

	// setter methods for setup class private variables.
	void set_email(string email_id);
	void set_password(string pass);
	void set_first_name(string f_name);
	void set_last_name(string l_name);
	void set_phone(string phone);
	void set_pi_add();
	void set_pi_name(string pi_name);
	void set_product_id(string prod_id);
	void set_token(string token);
	void set_otp(string otp);
	void set_api_error_msg(string msg);
	void set_login_manager_api_response(int response_type, string response);

	// setter methods for dev_controller class private variables.
	void set_d_id(string d_id);
	void set_status(string status);
	void set_range(string range);
	void set_mod_add(string mod_add);
	void set_pin(string pin);
	void set_device_controller_api_response(int response_type, string resp);
	void set_device_controller_api_error_msg(string msg);

	// getter methods for setup class private variables.
	string get_email();
	string get_password();
	string get_first_name();
	string get_last_name();
	string get_phone();
	string get_pi_add();
	string get_pi_name();
	string get_product_id();
	string get_token();
	string get_otp();
	string get_api_error_msg();
	string get_login_manager_api_response(int response_type);

	string get_user_credential_path();
	string get_mainwindow_bg_file_path();
	string get_dashboard_bg_file_path();
	string get_keyboad_icon_path();
	string get_update_icon_path();
	string get_update_brown_icon_path();
	string get_settings_icon_path();
	string get_wifi_icon_path();
	string get_power_icon_path();
	string get_ic_normal_icon_path();
	string get_ic_plus_white_icon_path();
	string get_ic_plus_brown_icon_path();
	string get_ic_warning_icon_path();
	string get_refresh_icon_path();

	string get_interface_up_script_path();

	// getter methods for dev_controller class private variables.
	string get_d_id();
	string get_status();
	string get_range();
	string get_mod_add();
	string get_pin();
	string get_device_controller_api_response(int response_type);
	string get_device_controller_api_error_msg();

	int hex_to_int(string);
	string int_to_hex(int);
};

#endif // IALOY_DATA_H
