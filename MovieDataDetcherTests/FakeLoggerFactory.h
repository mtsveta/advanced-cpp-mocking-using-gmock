#pragma once
#include "gmock/gmock.h"

#include "Logger.h"

class FakeLoggerFactory : public LoggerFactory
{
public:

	// Here, 0 in METHOD1 stands for 0 arguments
	MOCK_METHOD0(CreateLogger, std::shared_ptr<Logger>());
};
