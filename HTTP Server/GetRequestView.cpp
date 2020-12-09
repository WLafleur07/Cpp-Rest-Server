#include "GetRequestView.h"
#include "PlayerDiedController.h"
#include <iostream>
#include <string>

void handle_get(http_request request)
{
	cout << "\nhandle GET\n";

	wstring APIuri = request.absolute_uri().to_string();
	wcout << "endpoint URI: " << APIuri << endl;

	// playerdied endpoint
	if (wcscmp(APIuri.c_str(), L"/PartnerProject/PlayerDied") == 0)
	{
		PlayerDiedController Controller;
		Controller.Process(request);
	}

	// playerdied endpoint
	//if (wcscmp(APIuri.c_str(), L"/SLCGame311/PickedUpAmmo") == 0)
	//{
		//AmmoCollect Controller;
		//Controller.Process(request);
	//}

	request.reply(status_codes::BadRequest, "API endpoint not found");
}