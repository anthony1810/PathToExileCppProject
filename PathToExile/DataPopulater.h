//
//  DataPopulater.h
//  PathToExile
//
//  Created by Anthony Tran on 8/13/14.
//  Copyright (c) 2014 VIOTHUN INC. All rights reserved.
//

#ifndef __PathToExile__DataPopulater__
#define __PathToExile__DataPopulater__

#include <iostream>
#include <vector>
#include "Charater.h"
#include "Class.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"

class DataPopulater{
    //static std::vector<Character> characterList;
    static std::vector<Node> skillList;
public:
    static std::vector<Character> getAllCharacters();
    static std::vector<Node> getAllSkills();
    
    static void populateCharacters(std::string filename, std::vector<Character>& characterList);
    
    static void populateSkills(std::string filename, std::vector<Node>& skillList);
    
    static std::string convertToClassType(int heroId, std::string filename);
};

#endif /* defined(__PathToExile__DataPopulater__) */
