#ifndef HIUKONG_DAN_NODE_1_H
#define HIUKONG_DAN_NODE_1_H

#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cstring>

class Node{
	public:
		typedef std::string value_type;
		typedef std::size_t size_type;
		
		Node();
		
		Node(const value_type data, Node* link);
		
		void set_data(value_type& data);
		
		void set_link(Node*& link);
		
		value_type& data();
		
		const value_type& data() const;
		
		Node*& link();
		
		const Node* link() const;
	
	private:
		value_type data_field;
		Node* link_field;
};

Node::size_type node_size(const Node* headPtr);

Node::size_type node_count(const Node* headPtr, const Node::value_type target);

void node_insert_head(Node*& headPtr, Node::value_type entry);

void node_insert(Node*& insertPtr, Node::value_type entry);

const Node* node_search(const Node* headPtr, Node::value_type target);

Node* node_search(Node* headPtr, Node::value_type target);

Node* node_locate(Node* headptr, Node::size_type i);

Node::size_type node_copy(Node*& sourcePtr, Node*& headPtr, Node*& tailPtr);

Node* node_set(Node* headPtr);

void node_traverse(const Node* headPtr);

#endif // HIUKONG_DAN_NODE_1_H
