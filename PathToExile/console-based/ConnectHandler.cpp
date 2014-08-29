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


size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{ //callback must have this declaration
    //buf is a pointer to the data that curl has for us
    //size*nmemb is the size of the buffer
    
    for (int c = 0; c<size*nmemb; c++)
    {
        ConnectHandler::data.push_back(buf[c]);
    }
    return size*nmemb; //tell curl how many bytes we handled
}

FILE* getContentFromWeb( std::string filename){
    CURL* curl; //our curl object
    
    
    curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
    curl = curl_easy_init();
    
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.pathofexile.com/passive-skill-tree");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &ConnectHandler::writeCallback);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
    
    curl_easy_perform(curl);
    
    cin.get();
    
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    std::size_t found = ConnectHandler::data.find("var passiveSkillTreeData = ");
    std::size_t found2 = ConnectHandler::data.find("0.3835]}");
    if (found!=std::string::npos){
        std::string str2 = ConnectHandler::data.substr (found+27,(found2-19)-found);
        ofstream myfile (filename);
        if (myfile.is_open())
        {
            myfile<<str2;
            myfile.close();
        }
        else cout << "Unable to open file";
        cout<<"aaaa";
    }
    return fopen(filename.c_str(), "rb");
}




