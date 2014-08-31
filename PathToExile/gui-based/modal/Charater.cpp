//
//  Charater.cpp
//  PathToExile
//
//  Created by Anthony Tran on 8/12/14.
//  Copyright (c) 2014 VIOTHUN INC. All rights reserved.
//
#include "Charater.h"
Character::Character(std::string id){
    charId = id;
}

void Character::setStrength(int value){
    strength = value;
}

void Character::setDexterity(int value){
    dexterity = value;
}

void Character::setIntelligence(int value){
    intelligence = value;
}

void Character::setClassType(std::string value){
    classType = value;
}

void Character::set_staring_pos(int start_pos){
    starting_pos=start_pos;
}

std::string Character::getInfo(){
    std::stringstream ss;
    ss << charId << "- " << classType << std::endl;
    ss << "Strength: " << strength << std::endl;
    ss << "Dexterity: " << dexterity << std::endl;
    ss << "Inteligence: " << intelligence << std::endl << std::endl;
    
    return ss.str();
}

std::string Character::get_charID(){
    return charId;
}
std::string Character::get_classType(){
    return classType;
}
int Character::get_starting_pos(){
    return starting_pos;
}

int Character::getStr(){
    return strength;
}

int Character::getDex(){
    return dexterity;
}

int Character::getInt(){
    return intelligence;
}
