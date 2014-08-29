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
void DataPopulater::populateImageType(std::string filename,std::vector<Image>& all_image,string node_type){
     FILE* pFile = fopen(filename.c_str(), "rb");
    char buffer[65536];
    //parse file to DOM
    rapidjson::FileReadStream is(pFile, buffer, sizeof(buffer));
    rapidjson::Document document;
    document.ParseStream<0, rapidjson::UTF8<>, rapidjson::FileReadStream>(is);
    const rapidjson::Value& skillSprites = document["skillSprites"]; // Using a reference for consecutive access is handy and faster.
    const rapidjson::Value& node_type_1 = skillSprites[node_type.c_str()];
    const rapidjson::Value& node_image_1= node_type_1[3];
    const rapidjson::Value& cor_image_1= node_image_1["coords"];
    for (rapidjson::Value::ConstMemberIterator itr = cor_image_1.MemberBegin(); itr != cor_image_1.MemberEnd(); ++itr){
        string img_name=itr->name.GetString();
        int w= cor_image_1[itr->name.GetString()]["w"].GetInt();
        int h= cor_image_1[itr->name.GetString()]["h"].GetInt();
        int x= cor_image_1[itr->name.GetString()]["x"].GetInt();
        int y= cor_image_1[itr->name.GetString()]["y"].GetInt();
        Image i(img_name,x,y,w,h);
        all_image.push_back(i);
    }
}
void DataPopulater::populateImage(std::string filename,std::vector<Image>& all_image){
    populateImageType(filename,all_image,"normalActive");
    populateImageType(filename,all_image,"notableActive");
    populateImageType(filename,all_image,"keystoneActive");
}
void DataPopulater::populateSkills(std::string filename, std::vector<Node>& skillList,Shortest& s, std::vector<Image>& all_image){
    
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
        string s= c["icon"].GetString();

        Node n(c["id"].GetInt(), return_image_from_image_name(all_image,s));
        // n.add_image(c["icon"].GetString());
        skillList.push_back(n);
    }

    const rapidjson::Value& a1 = document["nodes"]; // Using a reference for consecutive access is handy and faster.
    assert(a1.IsArray());

    int track=0; 
    for (rapidjson::SizeType i = 0; i < a1.Size(); i++)
    {
        const rapidjson::Value& c = a1[i];
                  
        for(rapidjson::Value::ConstValueIterator m2 = c["out"].Begin(); m2 != c["out"].End(); ++m2){
        	// int current_node_id=skillList.at(track).get_real_id();
        	int neighbor_node_id= m2->GetInt();
            skillList.at(track).add_neighbor( find_node_based_on_real_id(skillList, neighbor_node_id ) );
            // int count_id=return_count_id_from_real_id(skillList, neighbor_node_id );
            //comment either this or Shortest::dist[(*i2).get_count_id()][(*i).get_count_id()]=1;    
     		// skillList.at( return_count_id_from_real_id(skillList, neighbor_node_id) -1) .add_neighbor ( find_node_based_on_real_id(skillList, current_node_id ) );
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
                // comment either this or skillList.at( return_count_id_from_real_id(skillList, neighbor_node_id) -1) .add_neighbor (  find_node_based_on_real_id(skillList, current_node_id )  );
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


