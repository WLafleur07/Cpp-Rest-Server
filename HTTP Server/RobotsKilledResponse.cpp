#include "RobotsKilledResponse.h"

bool RobotsKilledResponse::ProcessResponse(RobotsKilledModel modelData)
{
	bool success = false;

	json::value bufferJSON = GetRobotKillsJSON();
	bufferJSON[L"Kills"] = modelData.Kills;
	bufferJSON[L"Name"] = json::value::string(modelData.Name);

	if (bufferJSON.has_integer_field(L"Kills") && bufferJSON.has_string_field(L"Name"))
	{
		success = true;
	}

	return success;
}

void RobotsKilledResponse::SendResponse(http_request request, RobotsKilledModel modelData)
{
	request.reply(status_codes::OK, modelData.Kills);
}