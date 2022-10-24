cmake_minimum_required(VERSION 3.24)
project(advanced_cpp_mocking_using_gmock)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE CPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} MovieDataFetcher/*.cpp)
file(GLOB_RECURSE H_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} MovieDataFetcher/*.h)

# Create a library target for okapi-lib
set(MOVIE_RUNNER_LIB_NAME "movie-runner-lib")
add_library(${MOVIE_RUNNER_LIB_NAME} ${CPP_FILES})
include_directories(MovieDataFetcher)

# brew install curl
set(BASE_DIR      "/opt/homebrew/opt")
set(CURL_ROOT_DIR    ${CURL_BASE_DIR}/curl)
set(CURL_LIB_DIR     ${CURL_ROOT_DIR}/lib)
set(CURL_INCLUDE_DIR ${CURL_ROOT_DIR}/include)
set(CURL_LIBRARIES   ${CURL_LIB_DIR}/libcurl.a)

find_package(CURL REQUIRED)
find_package(rapidjson)

# brew install rapidjson
set(BASE_RAPIDJSON_DIR      "/opt/homebrew/Cellar/rapidjson/1.1.0")
set(RAPIDJSON_LIB_DIR     ${BASE_RAPIDJSON_DIR}/lib)
set(RAPIDJSON_INCLUDE_DIR ${BASE_RAPIDJSON_DIR}/include)
set(RAPIDJSON_LIBRARIES   ${RAPIDJSON_LIB_DIR}/pkgconfig/RapidJSON.pc)
include_directories(${RAPIDJSON_INCLUDE_DIR})

target_link_libraries(${MOVIE_RUNNER_LIB_NAME} ${CURL_LIBRARIES} ${RAPIDJSON_LIBRARIES})

add_executable(MovieDataFetcherRunner MovieDataFetcherRunner.cpp)
target_link_libraries(MovieDataFetcherRunner ${MOVIE_RUNNER_LIB_NAME})

# Provides functionality to download content of googletest and add it
include(FetchContent)
FetchContent_Declare(googletest
                     GIT_REPOSITORY https://github.com/google/googletest.git
                     GIT_TAG release-1.12.1)
# Ensure the named dependencies have been populated
FetchContent_MakeAvailable(googletest)

# Enable testing for this directory and below.
enable_testing()

# Declare the C++ test binary
#file(GLOB_RECURSE TEST_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} MovieDataDetcherTests/*.cpp)
file(GLOB_RECURSE TEST_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        MovieDataDetcherTests/TheMovieDbRepositoryTests.cpp
        MovieDataDetcherTests/TheMovieDbDataFactoryTests.cpp
        MovieDataDetcherTests/StringHtmlEncoderTests.cpp
        MovieDataDetcherTests/MetaDataProcessorTests.cpp
        MovieDataDetcherTests/JsonHelperTests.cpp
        MovieDataDetcherTests/main.cpp)
add_executable(google-tests ${TEST_FILES})
target_link_libraries(google-tests GTest::gtest GTest::gmock ${MOVIE_RUNNER_LIB_NAME})
include_directories(MovieDataDetcherTests)

include(GoogleTest)
gtest_discover_tests(google-tests)