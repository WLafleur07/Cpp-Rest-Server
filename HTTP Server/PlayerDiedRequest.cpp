#include "PlayerDiedRequest.h"

bool PlayerDiedRequest::ValidateHeaders(http_headers reqHeaders)
{
	bool success = false;

	if (reqHeaders.has(L"UserID"))
	{
		success = true;
	}

	return success;
}

bool PlayerDiedRequest::ProcessRequest(http_request request, PlayerDiedModel& modelData)
{
	bool success = true;

	http_headers reqHeaders = request.headers();

	modelData.UserID = reqHeaders[L"UserID"];

	return success;
}