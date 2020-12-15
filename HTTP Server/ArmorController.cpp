#include "ArmorController.h"
#include "ArmorRequest.h"
#include "ArmorResponse.h"
#include "ArmorModel.h"

void ArmorController::Process(http_request request)
{
	ArmorRequest requestHandler;
	ArmorResponse responseHandler;
	ArmorModel modelData;

	if (!requestHandler.ProcessRequest(request))
	{
		request.reply(status_codes::BadRequest, "Failed to process request");
	}

	if (!requestHandler.ValidateBody(modelData, request))
	{
		request.reply(status_codes::FailedDependency, "Missing body");
	}

	if (!responseHandler.ProcessResponse(modelData))
	{
		request.reply(status_codes::BadRequest, "Failed to process response");
	}

	responseHandler.SendResponse(request, modelData);
}