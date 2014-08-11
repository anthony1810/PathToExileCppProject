#include "Class.h"

int Node::count=0;

Node Node::nullNode(0);

void Node::add_neighbor(Node neighbor){
	all_neighbor.push_back(neighbor);

}
int Node::get_count_id(){
	return count_id;
}
int Node::get_real_id(){
	return real_id;
}
int Node::get_count_id_from_real_id(int real_id_para){
	if(real_id_para==real_id){
		return count_id;
	}else{
		return -1;
	}
}

vector<Node>& Node::get_all_neighbor(){
	return all_neighbor;
}

int return_count_id_from_real_id(std::vector<Node> all_node,int real_id_para){
	for (std::vector<Node>::iterator i = all_node.begin(); i != all_node.end(); ++i)
	{
		if(real_id_para== (*i).get_real_id() ){
			return (*i).get_count_id_from_real_id(real_id_para);
		}
	}
	return -1;
}
int return_real_id_from_count_id(std::vector<Node> all_node,int count_id_para){
	for (std::vector<Node>::iterator i = all_node.begin(); i != all_node.end(); ++i)
	{
		if(count_id_para== (*i).get_count_id() ){
			return (*i).get_real_id();
		}
	}
	return -1;	
}
Node& find_node_based_on_real_id(std::vector<Node> all_node,int real_id){
	for (std::vector<Node>::iterator i = all_node.begin(); i != all_node.end(); ++i)
	{
		if(real_id == (*i).get_real_id()){
			return (*i);
		}
	}
	return Node::nullNode;
}