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
    static std::string data;
public:
    ConnectHandler();
    
    static size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up);
    
   static FILE* getContentFromWeb( std::string filename);
    
    void writeWebToFile(std::string filename);
    
};
#endif /* defined(__PathToExile__ConnectHandler__) */
