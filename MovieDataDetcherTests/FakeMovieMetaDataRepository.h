#pragma once
#include "gmock/gmock.h"

#include "MovieMetaDataRepository.h"

class FakeMovieMetaDataRepository : public MovieMetaDataRepository
{
public:

	// Here, 1 in METHOD1 stands for 1 argument
	MOCK_METHOD1(FindMovieData, std::shared_ptr<MovieData>(const std::string& movieName));
};
