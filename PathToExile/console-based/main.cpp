#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "Class.h"
#include "Shortest.h"
#include "DataPopulater.h"
Shortest s;
std::vector<int> user_tree;
std::vector<Character> charList;
std::vector<Node> skillList;
std::vector<string> user_stas;   
std::vector<Image> all_image;
typedef std::map<int,int>  MAP;
typedef std::pair<int,int> PAIR;

int get_new_pos(int desNode,int& max_node);

string data; //will hold the url's contents
size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{ //callback must have this declaration
    //buf is a pointer to the data that curl has for us
    //size*nmemb is the size of the buffer

    for (int c = 0; c<size*nmemb; c++)
    {
        data.push_back(buf[c]);
    }
    return size*nmemb; //tell curl how many bytes we handled
}
int main()
{
    int max=15;
    // CURL* curl; //our curl object

    // curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
    // curl = curl_easy_init();

    // curl_easy_setopt(curl, CURLOPT_URL, "http://www.pathofexile.com/passive-skill-tree");
    // curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
    // curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress

    // curl_easy_perform(curl);

    // cout << endl << "Getting data from website" << endl;

    // std::size_t found = data.find("var passiveSkillTreeData = ");
    // std::size_t found2 = data.find("0.3835]}");
    // if (found!=std::string::npos){
    //     std::string str2 = data.substr (found+27,(found2-19)-found);
    //     ofstream myfile ("Skilltree.txt");
    //     if (myfile.is_open())
    //     {	
    //         myfile<<str2;
    //         myfile.close();
    //     }
    //     else cout << "Unable to open file";
    //     cout<<"aaaa";
    // }
    // // cin.get();
    

    // curl_easy_cleanup(curl);
    // curl_global_cleanup();
     
    
    //calling populator class to populate 2 vector above
    DataPopulater d;
     
    //populate data to 2 vector
    d.populateCharacters("Skilltree.txt", charList);
    d.populateImage("Skilltree.txt",all_image);
    d.populateSkills("Skilltree.txt", skillList,s,all_image);
 	
 	// cout<< return_image_from_image_name(all_image, "Art/2DArt/SkillIcons/passives/chaosresist.png").get_x();
    //testing
    //test character
    // for(int i = 0; i<charList.size(); i++){
    //     std::cout << charList.at(i).getInfo();
    // }
    //test image
    // for (std::vector<Image>::iterator i = all_image.begin(); i != all_image.end(); ++i)
    // {
    // 	cout<< (*i).get_image_name()<<" "<< (*i).get_x()<<" "<< (*i).get_y()<<" ";

    // }
    //test skills
    // for(int i = 0; i<skillList.size(); i++){
    //     std::cout << skillList.at(i).get_real_id() << ": ";
    // //     std::vector<Node> neighborList = (skillList.at(i)).get_all_neighbor();
    // //     for(int j = 0; j < neighborList.size(); j++){
    // //         std::cout << "{" <<neighborList.at(j).get_real_id() << "} ";
    // //     }
    // //     cout<<skillList.at(i).get_description();
    //     cout<<skillList.at(i).get_image().get_image_name()<<" "<< skillList.at(i).get_image().get_x()<<" "<<skillList.at(i).get_image().get_y();
    //     std::cout << std::endl;
    // }

    std::cout << "\n\n\n";
    
    std::cout << "PATH OF EXILE SKILL PARSER" << std::endl;
    std::cout << std::setw(30) << "@Version 1.0" << std::endl;
    std::cout << std::setw(41) << "@Powered by Viothun Inc" << std::endl << std::endl;
    int initialNode;
    int class_input;
    int desNode;
    
     for(int i = 0; i<charList.size(); i++){
        std::cout << charList.at(i).get_classType()<<"--"<< charList.at(i).get_charID()<<"\n";
    }
    std::cout << "Enter class id: ";
    std::cin >> class_input;
    std::cout << std::endl;
    std::cout << "Enter max node: ";
    std::cin >> max;
    std::cout << std::endl;
    for(int i=0;i<charList.size();i++){
    	if(class_input == atoi(charList.at(i).get_charID().c_str()) ){
    		initialNode= charList.at(i).get_starting_pos();
    		user_tree.push_back(initialNode);
    	}else{
    		initialNode= charList.at(1).get_starting_pos();
    	}
    }
  	
    //while loop for entering new destination mode
    while(true){
    	//18663(Minion instability)    21958(Purity of flesh)
    	//19635 (+10 intel below Instability) 49651( +10 intel below arcane vision)
    	//27929 (deep wisdom)  17790(10% flask after deepwisdom) 
    	//22972 (wandslinger) 27415 (+10 intel below deepwisdom)
    	//56075 (battery) 11420(Elemetal Dom)  56716(Lightning weaver)
        //15711 (blast radius)   21934 (spell damage above Elemental)
	    std::cout << "Enter destination node: ";
	    std::cin >> desNode;
	    std::cout << std::endl;
			        
		        
	    std::cout << "Result Node: ";
        int new_node_start=get_new_pos(desNode,max);
        if(new_node_start!=-1){
            s.dijkstra(return_count_id_from_real_id(skillList,new_node_start )) ; 
         	s.printPath( return_count_id_from_real_id(skillList,desNode) , skillList, user_tree);   
         // cout<< ((max- user_tree.size())<0 ) <<"  ";
           
            for (std::vector<int>::iterator i = user_tree.begin(); i != user_tree.end(); ++i)
            {
                cout<<(*i)<<" ";
            }
            cout<<"\n";
            user_node_description(user_stas,skillList,user_tree);
            for (std::vector<string>::iterator i = user_stas.begin(); i != user_stas.end(); ++i)
            {
                cout<< (*i)<<"\n";
            }
            cout<<"\n";
            cout<<max<<" node remain   \n";
        }else{
        	cout<<"More than allow"<<max<<" node remain\n";        
        }
    }

    

    
    return 0;
}
//this method used to check all the path from all selected node to new destination node
int get_new_pos(int desNode,int& max_node){
	MAP squares_map;
	for (std::vector<int>::iterator i = user_tree.begin(); i != user_tree.end(); ++i)
	{	int total_dis=0;
		s.dijkstra(return_count_id_from_real_id(skillList,(*i) ) );
		s.printPath( return_count_id_from_real_id(skillList,desNode) , skillList,total_dis);	
		squares_map.insert( PAIR(total_dis, (*i)) );			
	}
	if (!squares_map.empty())
    {
        MAP::iterator it_min = squares_map.begin();

        MAP::iterator it_max = squares_map.end();  // points to just past last element
        --it_max;          // points to last element
        if( max_node - it_min->first <0  ){
            return -1;
        }else{       
        max_node-= (it_min->first-1);                 
            return it_min->second;
        }
    }
    return -1; 
	
}







