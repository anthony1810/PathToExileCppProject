//
//  Charater.h
//  PathToExile
//
//  Created by Anthony Tran on 8/12/14.
//  Copyright (c) 2014 VIOTHUN INC. All rights reserved.
//

#ifndef __PathToExile__Charater__
#define __PathToExile__Charater__

#include <iostream>
#include "Class.h"
#include <sstream>

class Character{
    std::string charId;
    int strength;
    int dexterity;
    int intelligence;
    
    std::string classType;
public:
    Character(std::string id);
    
    //setter
    void setStrength(int value);
    void setDexterity(int value);
    void setIntelligence(int value);
    void setClassType(std::string value);
    
    //getter
    std::string getInfo();
};

#endif /* defined(__PathToExile__Charater__) */
