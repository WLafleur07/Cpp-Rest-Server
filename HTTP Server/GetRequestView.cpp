#include "GetRequestView.h"
#include "PlayerDiedController.h"
#include "ActiveWeaponController.h"
#include "PickupTypeController.h"
#include <iostream>
#include <string>

void handle_get(http_request request)
{
	cout << "\nhandle GET\n";

	wstring APIuri = request.absolute_uri().to_string();
	wcout << "endpoint URI: " << APIuri << endl;

	if (wcscmp(APIuri.c_str(), L"/PartnerProject/PlayerDied") == 0)
	{
		PlayerDiedController Controller;
		Controller.Process(request);
	}

	if (wcscmp(APIuri.c_str(), L"/PartnerProject/ActiveWeapon") == 0)
	{
		ActiveWeaponController Controller;
		Controller.Process(request);
	}

	if (wcscmp(APIuri.c_str(), L"/PartnerProject/Pickup") == 0)
	{
		PickupTypeController Controller;
		Controller.Process(request);
	}

	request.reply(status_codes::BadRequest, "API endpoint not found");
}