#include "PickupTypeController.h"
#include "PickupTypeRequest.h"
#include "PickupTypeResponse.h"
#include "PickupTypeModel.h"

void PickupTypeController::Process(http_request request)
{
	http_headers reqHeaders = request.headers();
	PickupTypeRequest requestHandler;
	PickupTypeResponse responseHandler;
	PickupTypeModel modelData;

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