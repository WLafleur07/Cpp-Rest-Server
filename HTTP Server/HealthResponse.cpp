#include "HealthResponse.h"

bool HealthResponse::ProcessResponse(HealthModel modelData)
{
	bool success = false;

	json::value bufferJSON = GetHealthJSON();
	bufferJSON[L"Health"] = modelData.Health;

	if (bufferJSON.has_integer_field(L"Health"))
	{
		success = true;
	}

	return success;
}

void HealthResponse::SendResponse(http_request request, HealthModel modelData)
{
	request.reply(status_codes::OK, modelData.Health);
}