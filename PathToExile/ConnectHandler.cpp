//
//  ConnectHandler.cpp
//  PathToExile
//
//  Created by Anthony Tran on 8/12/14.
//  Copyright (c) 2014 VIOTHUN INC. All rights reserved.
//

#include "ConnectHandler.h"

ConnectHandler::ConnectHandler(){
    curl_global_init(CURL_GLOBAL_ALL);
}


size_t ConnectHandler::data_write(void* buf, size_t size, size_t nmemb, void* userp)
{
	if(userp)
	{
		std::ostream& os = *static_cast<std::ostream*>(userp);
		std::streamsize len = size * nmemb;
		if(os.write(static_cast<char*>(buf), len))
			return len;
	}
    
	return 0;
}

CURLcode ConnectHandler::curl_read(const std::string& url, std::ostream& os, long timeout)
{
	CURLcode code(CURLE_FAILED_INIT);
	CURL* curl = curl_easy_init();
    
	if(curl)
	{
		if(CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &ConnectHandler::data_write))
           && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L))
           && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L))
           && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_FILE, &os))
           && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout))
           && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_URL, url.c_str())))
		{
			code = curl_easy_perform(curl);
		}
		curl_easy_cleanup(curl);
	}
	return code;
}

void ConnectHandler::writeWebToFile(std::string filename){
    std::ofstream ofs(filename);
	if(CURLE_OK == ConnectHandler::curl_read("http://www.pathofexile.com/passive-skill-tree", ofs))
	{
        std::cout << "Successfully write web to file " << filename << std::endl;
	}
}



