#include "HealthRequest.h"

bool HealthRequest::ProcessRequest(http_request request)
{
	bool success = true;
	json::value bufferJSON = GetHealthJSON();

	request.extract_json().then([&bufferJSON](pplx::task<json::value>task)
	{
		bufferJSON = task.get();

	}).wait();

	SetHealthJSON(bufferJSON);

	return success;
}

bool HealthRequest::ValidateBody(HealthModel& modelData, http_request request)
{
	bool success = false;

	http_headers reqHeaders = request.headers();
	json::value bufferJSON = GetHealthJSON();

	if (bufferJSON.has_integer_field(L"Health"))
	{
		success = true;
		modelData.Health = bufferJSON.at(L"Health").as_integer();
	}

	return success;
}
