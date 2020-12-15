#pragma once

#include "PickupTypeModel.h"
#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;

class PickupTypeRequest
{
public:
	PickupTypeRequest() {};
	~PickupTypeRequest() {};

	bool ValidateHeaders(http_headers reqHeaders);

	bool ProcessRequest(http_request request, PickupTypeModel& modelData);
};

