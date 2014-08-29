#ifndef _CLASS_H_
#define _CLASS_H_
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;
class Image{
	string image_name;
	int x; int y;
	int width;
	int height;
public:
	static Image nullImage;
	Image(string image_name,int x,int y,int width,int height):image_name(image_name), x(x),y(y),width(width),height(height){

	}
	string get_image_name();
	int get_x();
	int get_y();
	int get_width();
	int get_height();
};
class Node{
	
	
	int count_id;
	int real_id;
	std::vector<Node> all_neighbor;
	string description;
	Image image ;
public:
	static int count;
	static Node nullNode;
	Node(int real_id,Image image): real_id(real_id), image(image){ 
		count_id=count;
		count++;
	};
	void add_neighbor(Node neighbor);
	void add_description(string descrip);
	void add_image(Image img);
	int get_count_id();
	int get_real_id();
	Image& get_image();
	int get_count_id_from_real_id(int real_id_para);
	string get_description();
	vector<Node>& get_all_neighbor( );
};

Image& return_image_from_image_name(std::vector<Image> all_image,string image_name);

int return_count_id_from_real_id(std::vector<Node> all_node,int real_id_para);
int return_real_id_from_count_id(std::vector<Node> all_node,int count_id_para);
Node& find_node_based_on_real_id(std::vector<Node> all_node,int real_id);
void user_node_description(std::vector<string>& user_stas, std::vector<Node> all_node, std::vector<int> user_tree);

string get_word_only(string s);
int get_number_only(string s);
string combine_2_description(string expression, int i2);

#endif