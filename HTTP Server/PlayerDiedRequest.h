#pragma once

#include <cpprest/http_listener.h>
#include "PlayerDiedModel.h"

using namespace web;
using namespace web::http;

class PlayerDiedRequest
{
public:
	PlayerDiedRequest() {};
	~PlayerDiedRequest() {};

	bool ValidateHeaders(http_headers reqHeaders);

	bool ProcessRequest(http_request request, PlayerDiedModel& modelData);
};

