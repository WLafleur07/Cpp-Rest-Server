#pragma once

#include <cpprest/http_listener.h>
#include "PlayerDiedModel.h"

using namespace web;
using namespace web::http;

class PlayerDiedResponse
{
public:
	PlayerDiedResponse() {};
	~PlayerDiedResponse() {};

	json::value ResponseBody;

	bool ProcessResponse(PlayerDiedModel& modelData);
	void SendResponse(http_request request);
};

