#pragma once

#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;

class ArmorController

{
public:
	ArmorController() {};
	~ArmorController() {};

	void Process(http_request request);
};

