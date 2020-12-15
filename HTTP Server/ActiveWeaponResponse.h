#pragma once

#include "ActiveWeaponModel.h"

#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;

class ActiveWeaponResponse
{
public:
	ActiveWeaponResponse() {};
	~ActiveWeaponResponse() {};

	json::value ResponseBody;

	bool ProcessResponse(ActiveWeaponModel& modelData);
	void SendResponse(http_request request);
};

