#pragma once

#include <cpprest/http_listener.h>
#include "ArmorModel.h"

using namespace web;
using namespace web::http;

class ArmorRequest
{
public:
	ArmorRequest() {};
	~ArmorRequest() {};

	bool ProcessRequest(http_request request);
	bool ValidateBody(ArmorModel& modelData, http_request request);
	json::value GetArmorJSON() { return reqBodyJSON; };
	void SetArmorJSON(json::value bodyValue) { reqBodyJSON = bodyValue; };

private:
	json::value reqBodyJSON = json::value::object();
};

