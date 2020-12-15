#include "ActiveWeaponResponse.h"

#include <cpprest/json.h>

bool ActiveWeaponResponse::ProcessResponse(ActiveWeaponModel& modelData)
{
	bool success = false;

	ResponseBody = json::value::object();
	ResponseBody[L"ActiveWeapon"] = json::value::string(modelData.ActiveWeapon);

	if (ResponseBody.has_string_field(L"ActiveWeapon"))
	{
		success = true;
	}

	return success;
}

void ActiveWeaponResponse::SendResponse(http_request request)
{
	request.reply(status_codes::OK, ResponseBody);
}