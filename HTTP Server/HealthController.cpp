#include "HealthController.h"
#include "HealthRequest.h"
#include "HealthResponse.h"
#include "HealthModel.h"

void HealthController::Process(http_request request)
{
	HealthRequest requestHandler;
	HealthResponse responseHandler;
	HealthModel modelData;

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