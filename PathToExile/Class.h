#ifndef _CLASS_H_
#define _CLASS_H_
#include <iostream>
#include <vector>
using namespace std;

class Node{
	
	
	int count_id;
	int real_id;
	std::vector<Node> all_neighbor;
public:
	static int count;
	static Node nullNode;
	Node(int real_id): real_id(real_id){ 
		count_id=count;
		count++;
	};
	void add_neighbor(Node neighbor);
	int get_count_id();
	int get_real_id();
	int get_count_id_from_real_id(int real_id_para);
	vector<Node>& get_all_neighbor( );
};
int return_count_id_from_real_id(std::vector<Node> all_node,int real_id_para);
int return_real_id_from_count_id(std::vector<Node> all_node,int count_id_para);
Node& find_node_based_on_real_id(std::vector<Node> all_node,int real_id);
#endif