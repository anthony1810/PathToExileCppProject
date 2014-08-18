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
        character.setClassType(DataPopulater::convertToClassType(id_in_integer, filename,character));
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

void DataPopulater::populateSkills(std::string filename, std::vector<Node>& skillList,Shortest& s){
    
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
        Node n(c["id"].GetInt());
        skillList.push_back(n);
    }

    const rapidjson::Value& a1 = document["nodes"]; // Using a reference for consecutive access is handy and faster.
    assert(a1.IsArray());

    int track=0; 
    for (rapidjson::SizeType i = 0; i < a1.Size(); i++)
    {
        const rapidjson::Value& c = a1[i];
                  
        for(rapidjson::Value::ConstValueIterator m2 = c["out"].Begin(); m2 != c["out"].End(); ++m2){
            skillList.at(track).add_neighbor( find_node_based_on_real_id(skillList, m2->GetInt() ) );
     
       }
       for(rapidjson::Value::ConstValueIterator m2 = c["sd"].Begin(); m2 != c["sd"].End(); ++m2){
            string pre_description=skillList.at(track).get_description();
            if(!pre_description.empty()){
                skillList.at(track).add_description( pre_description+ "\n"+m2->GetString());    
            }else{
                skillList.at(track).add_description(m2->GetString());    
            }
            
       }
       track++;
    }
    s.n=skillList.size()-1;

     for (std::vector<Node>::iterator i = skillList.begin(); i != skillList.end(); ++i)
    {
        std::vector<Node> a=(*i).get_all_neighbor();
        if(a.size()>0){
            for (std::vector<Node>::iterator i2 = a.begin(); i2 != a.end(); ++i2)
            {
                Shortest::dist[ (*i).get_count_id() ][(*i2).get_count_id()]=1;    
                Shortest::dist[(*i2).get_count_id()][(*i).get_count_id()]=1;    
            }
        }
    }

}

std::string DataPopulater::convertToClassType(int heroId, std::string filename,Character& character){
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
                character.set_staring_pos(c["id"].GetInt());
                if(classType == "Seven"){
                    classType="SCION";
                }else if(classType=="SIX"){
                    classType="SHADOW";
                }
            }
        }
    }

    return classType;
}


