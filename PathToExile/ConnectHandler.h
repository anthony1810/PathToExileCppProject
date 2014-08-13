//
//  ConnectHandler.h
//  PathToExile
//
//  Created by Anthony Tran on 8/12/14.
//  Copyright (c) 2014 VIOTHUN INC. All rights reserved.
//

#ifndef __PathToExile__ConnectHandler__
#define __PathToExile__ConnectHandler__

#include <curl/curl.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class ConnectHandler{
    
public:
    ConnectHandler();
    
    static size_t data_write(void* buf, size_t size, size_t nmemb, void* userp);
    
    CURLcode curl_read(const std::string& url, std::ostream& os, long timeout = 30);
    
    void writeWebToFile(std::string filename);
    
};
#endif /* defined(__PathToExile__ConnectHandler__) */
