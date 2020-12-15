#pragma once

#include <cpprest/http_listener.h>
#include "HealthModel.h"
#include "HealthRequest.h"

using namespace web;
using namespace web::http;


class HealthResponse : HealthRequest
{
public:

	bool ProcessResponse(HealthModel modelData);
	void SendResponse(http_request request, HealthModel modelData);
};

