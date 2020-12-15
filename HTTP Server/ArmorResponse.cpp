#include "ArmorResponse.h"

bool ArmorResponse::ProcessResponse(ArmorModel modelData)
{
	bool success = false;

	json::value bufferJSON = GetArmorJSON();
	bufferJSON[L"Armor"] = modelData.Armor;

	if (bufferJSON.has_integer_field(L"Armor"))
	{
		success = true;
	}

	return success;
}

void ArmorResponse::SendResponse(http_request request, ArmorModel modelData)
{
	request.reply(status_codes::OK, modelData.Armor);
}