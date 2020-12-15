#pragma once

#include <cpprest/http_listener.h>
#include "RobotsKilledModel.h"

using namespace web;
using namespace web::http;

class RobotsKilledRequest
{
public:
	RobotsKilledRequest() {};
	~RobotsKilledRequest() {};

	bool ProcessRequest(http_request request);
	bool ValidateBody(RobotsKilledModel& modelData, http_request request);
	json::value GetRobotKillsJSON() { return reqBodyJSON; };
	void SetRobotKillsJSON(json::value bodyValue) { reqBodyJSON = bodyValue; };

private:
	json::value reqBodyJSON = json::value::object();
};

