#pragma once

#include <cpprest/http_listener.h>
#include "ArmorModel.h"
#include "ArmorRequest.h"

using namespace web;
using namespace web::http;


class ArmorResponse : ArmorRequest
{
public:

	bool ProcessResponse(ArmorModel modelData);
	void SendResponse(http_request request, ArmorModel modelData);
};

