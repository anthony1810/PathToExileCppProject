#ifndef _SHORTEST_H_
#define _SHORTEST_H_
#include "Class.h"
#define GRAPHSIZE 2048
#define INFINITY GRAPHSIZE*GRAPHSIZE 
#define MAX(a, b) ((a > b) ? (a) : (b))
class Shortest{
	
public:
int n; /* The number of nodes in the graph */
static int dist[][2000]; /* Shortest::dist[i][j] is the distance between node i and j; or 0 if there is no direct connection */
int d[GRAPHSIZE]; /* d[i] is the length of the shortest path between the source (s) and node i */
int prev [2048];
int a;
// void set_n(int value){
// 	n=value;
// }
// void printD() {
//     int i;
//     for (i = 1; i <= n; ++i)
//         // printf("%10d", i);
//     cout<<i<<"    ";
//         // printf("\n");
//     cout<<"\n";
//     for (i = 1; i <= n; ++i) {
//         // printf("%10ld", d[i]);
//         cout<<d[i]<<"    ";
//     }
//     // printf("\n"); 
//     cout<<"\n";
 
// }


void printPath(int dest,std::vector<Node> allNode);

void dijkstra(int s);

};



#endif