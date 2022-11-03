#include "RestApiClient.h"
#include "curl/curl.h"

using namespace std;

RestApiClient::RestApiClient()
{
}


RestApiClient::~RestApiClient()
{
}

string buffer;
size_t curl_write(void *ptr, size_t size, size_t nmemb, void *stream)
{
	buffer.append(static_cast<char*>(ptr), size*nmemb);
	return size*nmemb;
}

string RestApiClient::HttpGet(string& url)
{

	CURL *curl_;
	CURLcode res_;

	curl_ = curl_easy_init();
	buffer.clear();
	if(curl_) {
		curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
		/* example.com is redirected, so we tell libcurl to follow redirection */
		curl_easy_setopt(curl_, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, curl_write);

		/* Perform the request, res will get the return code */
		res_ = curl_easy_perform(curl_);
		/* Check for errors */
		if(res_ != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res_));
		/* always cleanup */
		curl_easy_cleanup(curl_);
	}

	return buffer;
}