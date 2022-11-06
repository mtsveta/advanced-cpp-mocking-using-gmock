#include "gtest/gtest.h"
#include "TheMovieDbRepository.h"
#include "TheMovieDbDataFactory.h"
#include "MovieNotFoundException.h"
#include "FakeRestApiClient.h"

using namespace testing;
const std::string fictiveApiKey = "1234";

TEST(TheMovieDbRepositoryTests, FindMovieData_ApiReturnsEmptyString_ThrowException)
{
	TheMovieDbDataFactory factory;
	FakeRestApiClient fakeClient;
	EXPECT_CALL(fakeClient, HttpGet(_)).WillOnce(Return(""));

	TheMovieDbRepository repository(fictiveApiKey, factory, fakeClient);

	ASSERT_THROW( repository.FindMovieData("movie name"), MovieNotFoundException );
}

TEST(TheMovieDbRepositoryTests, FindMovieData_ApiReturnsEmptyResult_ThrowException)
{
	TheMovieDbDataFactory factory;
	FakeRestApiClient fakeClient;
	EXPECT_CALL(fakeClient, HttpGet(_)).WillOnce(Return("{\"results\":[]}"));

	TheMovieDbRepository repository(fictiveApiKey, factory, fakeClient);

	ASSERT_THROW( repository.FindMovieData("movie name"), MovieNotFoundException );
}