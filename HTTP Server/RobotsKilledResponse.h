#pragma once

#include <cpprest/http_listener.h>
#include "RobotsKilledModel.h"
#include "RobotsKilledRequest.h"

using namespace web;
using namespace web::http;


class RobotsKilledResponse : RobotsKilledRequest
{
public:

	bool ProcessResponse(RobotsKilledModel modelData);
	void SendResponse(http_request request, RobotsKilledModel modelData);
};

