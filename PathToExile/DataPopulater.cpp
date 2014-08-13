//
//  DataPopulater.cpp
//  PathToExile
//
//  Created by Anthony Tran on 8/13/14.
//  Copyright (c) 2014 VIOTHUN INC. All rights reserved.
//

#include "DataPopulater.h"

void DataPopulater::populateCharacters(std::string filename, std::vector<Character>& characterList){
    
    FILE* pFile = fopen(filename.c_str(), "rb");
    char buffer[65536];
    //parse file to DOM
    rapidjson::FileReadStream is(pFile, buffer, sizeof(buffer));
    rapidjson::Document document;
    document.ParseStream<0, rapidjson::UTF8<>, rapidjson::FileReadStream>(is);

    
    //traverse through character data
    for (rapidjson::Value::ConstMemberIterator m = document["characterData"].MemberBegin(); m != document["characterData"].MemberEnd(); ++m) {
        
        std::string id = m->name.GetString();
        Character character(id);
        istringstream convert(id);
        int id_in_integer;
        convert >> id_in_integer;
        character.setClassType(DataPopulater::convertToClassType(id_in_integer, filename));
        for(rapidjson::Value::ConstMemberIterator m2 = document["characterData"][m->name.GetString()].MemberBegin(); m2 != document["characterData"][m->name.GetString()].MemberEnd(); ++m2){
           
            std::string att = m2->name.GetString();
           
            if(att.compare("base_str") == 0){
                character.setStrength(m2->value.GetInt());
            }else if(att.compare("base_dex") == 0){
                character.setDexterity(m2->value.GetInt());
            }else if(att.compare("base_int") == 0){
                character.setIntelligence(m2->value.GetInt());
            }
            
        }
       characterList.push_back(character);
    }
}

void DataPopulater::populateSkills(std::string filename, std::vector<Node>& skillList){
    
    FILE* pFile = fopen(filename.c_str(), "rb");
    char buffer[65536];
    //parse file to DOM
    rapidjson::FileReadStream is(pFile, buffer, sizeof(buffer));
    rapidjson::Document document;
    document.ParseStream<0, rapidjson::UTF8<>, rapidjson::FileReadStream>(is);

    
    // traverse through nodes data (skills)
    const rapidjson::Value& a = document["nodes"]; // Using a reference for consecutive access is handy and faster.
    assert(a.IsArray());
    for (rapidjson::SizeType i = 0; i < a.Size(); i++)
    {
        const rapidjson::Value& c = a[i];
        const rapidjson::Value& d = c["out"];
        
        Node n(c["id"].GetInt());
        
        assert(d.IsArray());
        for(rapidjson::SizeType j = 0; j < d.Size(); j++){
            Node n2(d[j].GetInt());
            n.add_neighbor(n2);
        }
        skillList.push_back(n);
    }

}

std::string DataPopulater::convertToClassType(int heroId, std::string filename){
    std::string classType;
    FILE* pFile = fopen(filename.c_str(), "rb");
    char buffer[65536];
    //parse file to DOM
    rapidjson::FileReadStream is(pFile, buffer, sizeof(buffer));
    rapidjson::Document document;
    document.ParseStream<0, rapidjson::UTF8<>, rapidjson::FileReadStream>(is);
    
    // traverse through nodes data (skills)
    const rapidjson::Value& a = document["nodes"]; // Using a reference for consecutive access is handy and faster.
    assert(a.IsArray());
    for (rapidjson::SizeType i = 0; i < a.Size(); i++)
    {
        const rapidjson::Value& c = a[i];
        const rapidjson::Value& d = c["spc"];
        
        assert(d.IsArray());
        for(rapidjson::SizeType j = 0; j < d.Size(); j++){
            if(d[j].GetInt() == heroId){
                classType = c["dn"].GetString();
            }
        }
    }

    return classType;
}


