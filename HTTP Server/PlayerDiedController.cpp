#include "PlayerDiedController.h"
#include "PlayerDiedRequest.h"
#include "PlayerDiedResponse.h"
#include "PlayerDiedModel.h"

void PlayerDiedController::Process(http_request request)
{
	http_headers reqHeaders = request.headers();
	PlayerDiedRequest requestHandler;
	PlayerDiedResponse responseHandler;
	PlayerDiedModel modelData;

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