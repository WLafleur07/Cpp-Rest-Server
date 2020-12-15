#pragma once

#include "PickupTypeModel.h"

#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;

class PickupTypeResponse
{
public:
	PickupTypeResponse() {};
	~PickupTypeResponse() {};

	json::value ResponseBody;

	bool ProcessResponse(PickupTypeModel& modelData);
	void SendResponse(http_request request);
};

