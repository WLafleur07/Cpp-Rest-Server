#pragma once

#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;

class HealthController
{
public:
	HealthController() {};
	~HealthController() {};

	void Process(http_request request);
};

