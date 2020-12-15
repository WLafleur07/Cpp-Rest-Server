#include "PickupTypeResponse.h"

#include <cpprest/json.h>

bool PickupTypeResponse::ProcessResponse(PickupTypeModel& modelData)
{
	bool success = false;

	ResponseBody = json::value::object();
	ResponseBody[L"PickupType"] = json::value::string(modelData.PickupType);
	ResponseBody[L"PickupAmount"] = modelData.PickupAmount;

	if (ResponseBody.has_string_field(L"PickupType") && ResponseBody.has_integer_field(L"PickupAmount"))
	{
		success = true;
	}

	return success;
}

void PickupTypeResponse::SendResponse(http_request request)
{
	request.reply(status_codes::OK, ResponseBody);
}