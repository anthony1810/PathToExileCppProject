#include "Class.h"

int Node::count=0;

Node Node::nullNode(0);

void Node::add_neighbor(Node neighbor){
	all_neighbor.push_back(neighbor);
}
void Node::add_description(string descrip){ 
	description=descrip;
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
string Node::get_description(){
	return description;
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

void user_node_description(std::vector<string>& user_stas, std::vector<Node> all_node, std::vector<int> user_tree){
	string temp;
	bool found=false;
	user_stas.clear();
	for (std::vector<int>::iterator i = user_tree.begin(); i != user_tree.end(); ++i)
	{	
		// stas+= find_node_based_on_real_id(all_node, (*i) ).get_description();
		temp=find_node_based_on_real_id(all_node, (*i) ).get_description();
		// cout<<temp;
		std::vector<std::string> tokens;
		boost::split( tokens, temp, is_any_of( "\n" ) );
		  // print( tokens );
		for (std::vector<string>::iterator i2 = tokens.begin(); i2 != tokens.end(); ++i2)
		{
			// cout<< (*i2)<<" ";
			for (std::vector<string>::iterator i3 = user_stas.begin(); i3 != user_stas.end(); ++i3)
			{
				if( get_word_only(*i2).compare(get_word_only(*i3)) ==0 ){
					found=true;
					(*i3)= combine_2_description( *i3, get_number_only(*i2) );
					// cout<<combine_2_description( *i3, get_number_only(*i2) );
					// cout<< get_number_only(*i2);
					break;
				}
			} 
			if(found==false){
				user_stas.push_back(*i2);	
			}
			found=false;
		}
	}
	// std::string expression = "+10 to Intelligence";
	// std::string number;
	// boost::regex re("\\d+");
	// boost::sregex_iterator i(expression.begin (),expression.end (),re);
	// boost::sregex_iterator j;
	// for(; i!=j; ++i) {
	// 	number+= i->str();
	// }
	// int a=atoi(number.c_str())+10;
	// string s;
	// std::size_t found = expression.find(number);
	// expression.replace(found,number.size(),to_string(a));
	// cout<<stas;
}
string get_word_only(string s){
	std::string word;
	boost::regex re("[a-z,A-Z]+");
	boost::sregex_iterator i(s.begin (),s.end (),re);
	boost::sregex_iterator j;
	for(; i!=j; ++i) {
		word+= i->str();
	}
	return word;
}

int get_number_only(string s){
	// std::string expression = "+10 to Intelligence";
	std::string number;
	boost::regex re("\\d+");
	boost::sregex_iterator i(s.begin (),s.end (),re);
	boost::sregex_iterator j;
	for(; i!=j; ++i) {
		number+= i->str();
	}

	int a=atoi(number.c_str());
	return a;
}

string combine_2_description(string expression, int i2){
	// std::string expression = "+10 to Intelligence";
	std::string number;
	boost::regex re("\\d+");
	boost::sregex_iterator i(expression.begin (),expression.end (),re);
	boost::sregex_iterator j;
	for(; i!=j; ++i) {
		number+= i->str();
	}
	int a=atoi(number.c_str())+i2;
	string s;
	std::size_t found = expression.find(number);
	expression.replace(found,number.size(),to_string(a));
	// cout<<expression;
	return expression;	
}