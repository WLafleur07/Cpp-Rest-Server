#pragma once

#include <cpprest/http_listener.h>
#include "HealthModel.h"

using namespace web;
using namespace web::http;

class HealthRequest
{
public:
	HealthRequest() {};
	~HealthRequest() {};

	bool ProcessRequest(http_request request);
	bool ValidateBody(HealthModel& modelData, http_request request);
	json::value GetHealthJSON() { return reqBodyJSON; };
	void SetHealthJSON(json::value bodyValue) { reqBodyJSON = bodyValue; };

private:
	json::value reqBodyJSON = json::value::object();
};

