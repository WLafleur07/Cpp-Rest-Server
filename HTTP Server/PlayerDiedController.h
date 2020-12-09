#pragma once

#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;

class PlayerDiedController
{
public:
	PlayerDiedController() {};
	~PlayerDiedController() {};

	void Process(http_request request);
};

