#pragma once
#include "gmock/gmock.h"

#include "RestApiClient.h"

class FakeRestApiClient : public RestApiClient
{
public:
	// Here, 1 in METHOD1 stands for 1 argument
	MOCK_METHOD1(HttpGet, std::string(std::string&));
};