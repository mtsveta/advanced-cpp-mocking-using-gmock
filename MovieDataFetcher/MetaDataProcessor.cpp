#include "MetaDataProcessor.h"
#include "MovieData.h"

// Constructor accepting `MovieMetaDataRepository` will always call
// constructor  accepting `MovieMetaDataRepository` and `std::shared_ptr<LoggerFactory> `
MetaDataProcessor::MetaDataProcessor(MovieMetaDataRepository& repository) : 
	MetaDataProcessor(repository, std::make_shared<LoggerFactory>())
{
}

MetaDataProcessor::MetaDataProcessor(MovieMetaDataRepository& respository, std::shared_ptr<LoggerFactory> loggerFactory)
	: m_repository(respository), m_loggerFactory(loggerFactory)
{

}

MetaDataProcessor::~MetaDataProcessor()
{
}

void MetaDataProcessor::ProcessMovies(const std::vector<std::string>& movieNames, Movies& result)
{
	if(movieNames.size() == 0)
	{
		return;
	}

	for (auto movieName : movieNames)
	{
		try
		{
			std::shared_ptr<MovieData> movieData = m_repository.FindMovieData(movieName);

			result.push_back(movieData);
		}
		catch(...)
		{
			// Factory is called to create a logger (writing the error into the logs)
			m_loggerFactory->CreateLogger()->LogError(movieName);
		}
	}
}
