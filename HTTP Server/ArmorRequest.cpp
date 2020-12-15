#include "ArmorRequest.h"

bool ArmorRequest::ProcessRequest(http_request request)
{
	bool success = true;
	json::value bufferJSON = GetArmorJSON();

	request.extract_json().then([&bufferJSON](pplx::task<json::value>task)
	{
		bufferJSON = task.get();

	}).wait();

	SetArmorJSON(bufferJSON);

	return success;
}

bool ArmorRequest::ValidateBody(ArmorModel& modelData, http_request request)
{
	bool success = false;

	http_headers reqHeaders = request.headers();
	json::value bufferJSON = GetArmorJSON();

	if (bufferJSON.has_integer_field(L"Armor"))
	{
		success = true;
		modelData.Armor = bufferJSON.at(L"Armor").as_integer();
	}

	return success;
}
