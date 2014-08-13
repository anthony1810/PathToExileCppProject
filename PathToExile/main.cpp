#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "Class.h"
#include "Shortest.h"
#include "ConnectHandler.h"
#include "DataPopulater.h"


int main()
{
//    ConnectHandler c;
//    c.writeWebToFile("output.txt");
    
    std::vector<Character> charList;
    std::vector<Node> skillList;
    
    //calling populator class to populate 2 vector above
    DataPopulater d;
    
    //populate data to 2 vector
    d.populateCharacters("Skilltree.txt", charList);
    d.populateSkills("Skilltree.txt", skillList);
 
    //testing
    //test character
    for(int i = 0; i<charList.size(); i++){
        std::cout << charList.at(i).getInfo();
    }
    
    //test skills
    for(int i = 0; i<skillList.size(); i++){
        std::cout << skillList.at(i).get_real_id() << ": ";
        std::vector<Node> neighborList = (skillList.at(i)).get_all_neighbor();
        for(int j = 0; j < neighborList.size(); j++){
            std::cout << "{" <<neighborList.at(j).get_real_id() << "} ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n\n";
    Shortest s;
    std::cout << "PATH OF EXILE SKILL PARSER" << std::endl;
    std::cout << std::setw(30) << "@Version 1.0" << std::endl;
    std::cout << std::setw(41) << "@Powered by Viothun Inc" << std::endl << std::endl;
    int initialNode;
    int desNode;
    
    std::cout << "Enter initial node: ";
    std::cin >> initialNode;
    std::cout << std::endl;
    s.dijkstra(initialNode);
        
    std::cout << "Enter destination node: ";
    std::cin >> desNode;
    std::cout << std::endl;
        
        
    std::cout << "Result Node: ";
    s.printPath(desNode, skillList);

    
    return 0;
}









