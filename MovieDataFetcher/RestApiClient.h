#pragma once
#include <string>

class RestApiClient
{
public:
	RestApiClient();

	// Virtual destructor is MUST for faking the class
	virtual ~RestApiClient();

	// All the fake methods must virtual or pure virtual (like in class Logger)
	// Having pure virtual test we will be able to change the implementation according to the needs of the test
	virtual std::string HttpGet(std::string& url);
};
