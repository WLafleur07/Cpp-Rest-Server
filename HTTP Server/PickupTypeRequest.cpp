#include "PickupTypeRequest.h"

bool PickupTypeRequest::ValidateHeaders(http_headers reqHeaders)
{
	bool success = false;

	if (reqHeaders.has(L"PickupType") && reqHeaders.has(L"PickupAmount"))
	{
		success = true;
	}

	return success;
}

bool PickupTypeRequest::ProcessRequest(http_request request, PickupTypeModel& modelData)
{
	bool success = true;

	http_headers reqHeaders = request.headers();

	modelData.PickupType = reqHeaders[L"PickupType"];
	modelData.PickupAmount = stoi(reqHeaders[L"PickupAmount"]);

	return success;
}
