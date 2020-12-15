#include "RobotsKilledRequest.h"

bool RobotsKilledRequest::ProcessRequest(http_request request)
{
	bool success = true;
	json::value bufferJSON = GetRobotKillsJSON();

	request.extract_json().then([&bufferJSON](pplx::task<json::value>task)
	{
		bufferJSON = task.get();

	}).wait();

	SetRobotKillsJSON(bufferJSON);

	return success;
}

bool RobotsKilledRequest::ValidateBody(RobotsKilledModel& modelData, http_request request)
{
	bool success = false;

	http_headers reqHeaders = request.headers();
	json::value bufferJSON = GetRobotKillsJSON();

	if (bufferJSON.has_integer_field(L"Kills") && reqHeaders.has(L"Name"))
	{
		success = true;
		modelData.Kills = bufferJSON.at(L"Kills").as_integer();
		modelData.Name = reqHeaders[L"Name"];
	}

	return success;
}
