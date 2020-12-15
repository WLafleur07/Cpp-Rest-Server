#pragma once

#include "ActiveWeaponModel.h"
#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;

class ActiveWeaponRequest
{
public:
	ActiveWeaponRequest() {};
	~ActiveWeaponRequest() {};

	bool ValidateHeaders(http_headers reqHeaders);

	bool ProcessRequest(http_request request, ActiveWeaponModel& modelData);
};

