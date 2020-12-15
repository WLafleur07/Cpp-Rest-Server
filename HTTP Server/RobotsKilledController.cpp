#include "RobotsKilledController.h"
#include "RobotsKilledRequest.h"
#include "RobotsKilledResponse.h"
#include "RobotsKilledModel.h"

void RobotsKilledController::Process(http_request request)
{
	RobotsKilledRequest requestHandler;
	RobotsKilledResponse responseHandler;
	RobotsKilledModel modelData;

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