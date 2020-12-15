#include "ActiveWeaponController.h"
#include "ActiveWeaponRequest.h"
#include "ActiveWeaponResponse.h"
#include "ActiveWeaponModel.h"

void ActiveWeaponController::Process(http_request request)
{
	http_headers reqHeaders = request.headers();
	ActiveWeaponRequest requestHandler;
	ActiveWeaponResponse responseHandler;
	ActiveWeaponModel modelData;

	if (!requestHandler.ValidateHeaders(reqHeaders))
	{
		request.reply(status_codes::FailedDependency, "Missing Headers");
	}

	if (!requestHandler.ProcessRequest(request, modelData))
	{
		request.reply(status_codes::BadRequest, "Failed to process request");
	}

	if (!responseHandler.ProcessResponse(modelData))
	{
		request.reply(status_codes::BadRequest, "Failed to process response");
	}

	responseHandler.SendResponse(request);
}
