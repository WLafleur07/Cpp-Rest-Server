#include "ActiveWeaponRequest.h"

bool ActiveWeaponRequest::ValidateHeaders(http_headers reqHeaders)
{
	bool success = false;

	if (reqHeaders.has(L"ActiveWeapon"))
	{
		success = true;
	}

	return success;
}

bool ActiveWeaponRequest::ProcessRequest(http_request request, ActiveWeaponModel& modelData)
{
	bool success = true;

	http_headers reqHeaders = request.headers();

	modelData.ActiveWeapon = reqHeaders[L"ActiveWeapon"];

	return success;
}
