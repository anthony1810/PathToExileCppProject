#include <iostream>
#include <string>
#include <fstream>
#include <curl/curl.h> //your directory may be different
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
//#include "Utility.h"
// #include <thread>         // std::this_thread::sleep_for
// #include <chrono>         // std::chrono::seconds
#include "Class.h"
using namespace std;

string data; //will hold the url's contents

#define GRAPHSIZE 2048
#define INFINITY GRAPHSIZE*GRAPHSIZE
#define MAX(a, b) ((a > b) ? (a) : (b))
using namespace std; 
int e; /* The number of nonzero edges in the graph */
int n; /* The number of nodes in the graph */
long dist[2000][2000]; /* dist[i][j] is the distance between node i and j; or 0 if there is no direct connection */
// long** dist;
long d[GRAPHSIZE]; /* d[i] is the length of the shortest path between the source (s) and node i */
int prev [2048];

std::vector<Node> allNode;

void printD() {
    int i;
    for (i = 1; i <= n; ++i)
        // printf("%10d", i);
    cout<<i<<"    ";
        // printf("\n");
    cout<<"\n";
    for (i = 1; i <= n; ++i) {
        // printf("%10ld", d[i]);
        cout<<d[i]<<"    ";
    }
    // printf("\n");
    cout<<"\n";
 
}
 void printPath(int dest) {
    if (prev[dest] != -1)
        // cout<<prev[dest];
        printPath(prev[dest]);
    // printf("%d ", dest);
    // cout<<dest<<" ";
    cout<<return_real_id_from_count_id(allNode,dest)<<" ";
}
void dijkstra(int s) {
      int i, k, mini;
    int visited[GRAPHSIZE];//contain node that already optimize =1/ not optimized=0;
 
    for (i = 1; i <= n; ++i) {
        d[i] = INFINITY;
        prev[i] = -1; /* no path has yet been found to i */
        visited[i] = 0; /* the i-th element has not yet been visited */
    }
 
    d[s] = 0;
 
    for (k = 1; k <= n; ++k) {
        //reset the mini
        mini = -1;
        for (i = 1; i <= n; ++i){
            //compared current distance to each node with the distance of "new found" minimized node, ignore any found-before minimized node 
            if (!visited[i] && ((mini == -1) || (d[i] < d[mini]))){ 
                mini = i;                                               //update the minimized index if smaller
                // printf("%d \n", mini );
            }
        }
        visited[mini] = 1;//found the minimized
        //d[mini] the most optimize path distance
        for (i = 1; i <= n; ++i)
            if (dist[mini][i]!=0){ //check the neighboor node of the minimized node
                if (d[mini] + dist[mini][i] < d[i]) {//caculate the shorter path for the node[i], 
                    d[i] = d[mini] + dist[mini][i];
                    // printf("%d %d ", i,mini );
                    prev[i] = mini;
                }
            }
    }
}
int main()
{ n=1515;
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
    
    
//     //traverse through character data
//     for (rapidjson::Value::ConstMemberIterator m = document["characterData"].MemberBegin(); m != document["characterData"].MemberEnd(); ++m) {
//         std::cout<< "Character number " <<m->name.GetString() <<" :";
//         for(rapidjson::Value::ConstMemberIterator m2 = document["characterData"][m->name.GetString()].MemberBegin(); m2 != document["characterData"][m->name.GetString()].MemberEnd(); ++m2){
//             std::cout << m2->name.GetString() <<":";
//             std::cout<< m2->value.GetInt()<<" ";
//         }
//         cout<<"\n";
//     }

    
// //    //traverse through main (i don't know what the fuck is this but yeah let's print it out)
//     for (rapidjson::Value::ConstMemberIterator m = document["main"].MemberBegin(); m != document["main"].MemberEnd(); ++m) {
//         cout<< m->name.GetString() <<" ";
        
//        for(rapidjson::Value::ConstValueIterator m2 = document["main"]["out"].Begin(); m2 != document["main"]["out"].End(); ++m2){
//            cout<< m2->GetInt()<<" ";
//        }
//         cout<<"\n";
//     }
    
    
   // traverse through nodes data (skills)
    const rapidjson::Value& a = document["nodes"]; // Using a reference for consecutive access is handy and faster.
    assert(a.IsArray());
    for (rapidjson::SizeType i = 0; i < a.Size(); i++)
    { 
        const rapidjson::Value& c = a[i];
        
        printf("Skill ID: %d, Skill name: %s",c["id"].GetInt(), c["dn"].GetString());
        cout<<" out: ";
        Node n(c["id"].GetInt());
        allNode.push_back(n);
        for(rapidjson::Value::ConstValueIterator m2 = c["out"].Begin(); m2 != c["out"].End(); ++m2){
            cout<<m2->GetInt()<<" ";
       }
       cout<<"\n";
    }

    //   dist = new long*[n+1];
    // for(int i = 0; i < 7; ++i)
    //     dist[i] = new long[n+1];


    const rapidjson::Value& a1 = document["nodes"]; // Using a reference for consecutive access is handy and faster.
    assert(a1.IsArray());

    int track=0; 
    for (rapidjson::SizeType i = 0; i < a1.Size(); i++)
    {
        const rapidjson::Value& c = a1[i];
                  
        for(rapidjson::Value::ConstValueIterator m2 = c["out"].Begin(); m2 != c["out"].End(); ++m2){
            allNode.at(track).add_neighbor( find_node_based_on_real_id(allNode, m2->GetInt() ) );
     
       }
       track++;
    }
    cout<<allNode.at(7).get_all_neighbor().at(4).get_count_id()<<"\n";
     for (std::vector<Node>::iterator i = allNode.begin(); i != allNode.end(); ++i)
    {
        // cout<<(*i).get_count_id()<<" ";
        std::vector<Node> a=(*i).get_all_neighbor();
        if(a.size()>0){
            for (std::vector<Node>::iterator i2 = a.begin(); i2 != a.end(); ++i2)
            {
                // cout<<(*i2).get_count_id()<<" ";
                 // std::this_thread::sleep_for (std::chrono::seconds(1));
                dist[(*i).get_count_id()][(*i2).get_count_id()]=1;    
            }
        }
        cout<<"\n";
    }
    // cout<< dist[]
    // cout<<Node::count<<"\n";
    //54447
     dijkstra(  return_count_id_from_real_id(allNode,54447)  );
 
    // printD();
     //27611
    printPath( return_count_id_from_real_id(allNode,27611)  );
    return 0;
}









