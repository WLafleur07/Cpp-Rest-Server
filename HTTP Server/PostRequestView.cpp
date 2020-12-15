#include "PostRequestView.h"
#include "RobotsKilledController.h"
#include "HealthController.h"
#include "ArmorController.h"

void handle_post(http_request request)
{
	cout << "\nhandle POST\n";

	wstring APIuri = request.absolute_uri().to_string();
	wcout << "endpoint URI: " << APIuri << endl;

	if (wcscmp(APIuri.c_str(), L"/PartnerProject/RobotsKilled") == 0)
	{
		RobotsKilledController Controller;
		Controller.Process(request);
	}

	if (wcscmp(APIuri.c_str(), L"/PartnerProject/Health") == 0)
	{
		HealthController Controller;
		Controller.Process(request);
	}

	if (wcscmp(APIuri.c_str(), L"/PartnerProject/Armor") == 0)
	{
		ArmorController Controller;
		Controller.Process(request);
	}

	request.reply(status_codes::BadRequest, "API endpoint not found");
}