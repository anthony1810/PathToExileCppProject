#include <iostream>
#include <string>
#include <fstream>
#include <curl/curl.h> //your directory may be different
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
//#include "Utility.h"

using namespace std;

string data; //will hold the url's contents


int main()
{
//    CURL* curl; //our curl object
//
//    curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
//    curl = curl_easy_init();
//
//    curl_easy_setopt(curl, CURLOPT_URL, "http://www.pathofexile.com/passive-skill-tree");
//    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
//    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
//
//    curl_easy_perform(curl);
//
//    cin.get();
//
//    curl_easy_cleanup(curl);
//    curl_global_cleanup();
//    std::size_t found = data.find("var passiveSkillTreeData = ");
//    std::size_t found2 = data.find("0.3835]}");
//    if (found!=std::string::npos){
//        std::string str2 = data.substr (found+27,(found2-19)-found);  
//        ofstream myfile ("example.txt");
//          if (myfile.is_open())
//          {
//            myfile<<str2;
//            myfile.close();
//          }
//          else cout << "Unable to open file";
//            cout<<"aaaa";
//    }

    //open file for streaming
    FILE* pFile = fopen("Skilltree.txt", "rb");
    char buffer[65536];
    
    //parse file to DOM
    rapidjson::FileReadStream is(pFile, buffer, sizeof(buffer));
    rapidjson::Document document;
    document.ParseStream<0, rapidjson::UTF8<>, rapidjson::FileReadStream>(is);
    
    
    //traverse through character data
    for (rapidjson::Value::ConstMemberIterator m = document["characterData"].MemberBegin(); m != document["characterData"].MemberEnd(); ++m) {
        std::cout<< "Character number " <<m->name.GetString() <<" :";
        for(rapidjson::Value::ConstMemberIterator m2 = document["characterData"][m->name.GetString()].MemberBegin(); m2 != document["characterData"][m->name.GetString()].MemberEnd(); ++m2){
            std::cout << m2->name.GetString() <<":";
            std::cout<< m2->value.GetInt()<<" ";
        }
        cout<<"\n";
    }

    
//    //traverse through main (i don't know what the fuck is this but yeah let's print it out)
    for (rapidjson::Value::ConstMemberIterator m = document["main"].MemberBegin(); m != document["main"].MemberEnd(); ++m) {
        cout<< m->name.GetString() <<" ";
        
//        for(rapidjson::Value::ConstMemberIterator m2 = document["groups"][m->name.GetString()].MemberBegin(); m2 != document["groups"][m->name.GetString()].MemberEnd(); ++m2){
//            cout<< m2->value.GetInt()<<" ";
//        }
        cout<<"\n";
    }
    

   // traverse through nodes data (skills)
    const rapidjson::Value& a = document["nodes"]; // Using a reference for consecutive access is handy and faster.
    assert(a.IsArray());
    for (rapidjson::SizeType i = 0; i < a.Size(); i++)
    {
        const rapidjson::Value& c = a[i];
        
        printf("Skill ID: %d, Skill name: %s\n",c["id"].GetInt(), c["dn"].GetString());
    }

    
    return 0;
}









