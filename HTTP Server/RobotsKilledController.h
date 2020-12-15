#pragma once

#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;

class RobotsKilledController
{
public:
	RobotsKilledController() {};
	~RobotsKilledController() {};

	void Process(http_request request);
};

