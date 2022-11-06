#pragma once
#include "gmock/gmock.h"

#include "Logger.h"

class FakeLogger : public Logger
{
public:

	// Here, 1 in METHOD1 stands for 1 argument
	MOCK_METHOD1(LogError, void(std::string));
};