#pragma once

#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;

class PickupTypeController
{
public:
	PickupTypeController() {};
	~PickupTypeController() {};

	void Process(http_request request);
};