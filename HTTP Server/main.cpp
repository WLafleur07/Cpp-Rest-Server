// the following code is an adaptation of the code presented on: 
// https://mariusbancila.ro/blog/2017/11/19/revisited-full-fledged-client-server-example-with-c-rest-sdk-2-10/

#include <cpprest/http_listener.h>
#include <cpprest/json.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <map>

#include "GetRequestView.h"
//#include "PostRequestView.h"

#pragma comment(lib, "cpprest_2_10")

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;
using namespace std;

int main()
{
	srand(time(NULL));

	http_listener listener(L"http://localhost:8989/PartnerProject/");

	listener.support(methods::GET, handle_get);
	//listener.support(methods::POST, handle_post);

	try
	{
		listener.open().then([&listener]()
		{
			wcout << ("\nlistening::\n") << listener.uri().to_string().c_str();
		})
			.wait();
	}
	catch (exception const& e)
	{
		wcout << e.what() << endl;
	}

	// infinite while loop to ensure our application continues to run and doesn't reach the end
	while (true);

	return 0;
}
