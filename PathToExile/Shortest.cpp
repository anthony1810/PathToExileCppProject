#include "Shortest.h"

int Shortest::dist[2000][2000];


void Shortest::printPath(int dest,std::vector<Node>& allNode,std::vector<int>& user_tree) {
	if (prev[dest] != -1){
        printPath(prev[dest], allNode,user_tree);
    }
    int real_id=return_real_id_from_count_id(allNode,dest);
    bool found=false;
    for (std::vector<int>::iterator i = user_tree.begin(); i != user_tree.end(); ++i)
    {
        if( (*i)==real_id )   {
            found=true;
        }
    }
    if(!found){
        user_tree.push_back(real_id);
    }
    // cout<<return_real_id_from_count_id(allNode,dest)<<" ";
}
void Shortest::printPath(int dest,std::vector<Node>& allNode,int& total_dis){
    if (prev[dest] != -1){
        printPath(prev[dest], allNode,total_dis);
    }
    total_dis++;
    // cout<<return_real_id_from_count_id(allNode,dest)<<" ";
}
void Shortest::dijkstra(int s) {
	 int i, k, mini;
    int visited[GRAPHSIZE];//contain node that already optimize =1/ not optimized=0;
 
    for (i = 1; i <= n; ++i) {
        d[i] = INFINITY2;
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
            if (Shortest::dist[mini][i]!=0){ //check the neighboor node of the minimized node
                if (d[mini] + Shortest::dist[mini][i] < d[i]) {//caculate the shorter path for the node[i], 
                    d[i] = d[mini] + Shortest::dist[mini][i];
                    // printf("%d %d ", i,mini );
                    prev[i] = mini;
                }
            }
    }
}