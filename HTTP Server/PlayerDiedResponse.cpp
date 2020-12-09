#include "PlayerDiedResponse.h"

#include <cpprest/json.h>

bool PlayerDiedResponse::ProcessResponse(PlayerDiedModel& modelData)
{
	bool success = false;

	ResponseBody = json::value::object();
	ResponseBody[L"UserID"] = json::value::string(modelData.UserID);

	if (ResponseBody.has_string_field(L"UserID"))
	{
		success = true;
	}

	return success;
}

void PlayerDiedResponse::SendResponse(http_request request)
{
	request.reply(status_codes::OK, ResponseBody);
}