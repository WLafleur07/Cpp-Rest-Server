#pragma once

#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;

class ActiveWeaponController
{
public:
	ActiveWeaponController() {};
	~ActiveWeaponController() {};

	void Process(http_request request);
};

