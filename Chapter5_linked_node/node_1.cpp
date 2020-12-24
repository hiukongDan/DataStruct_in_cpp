// Helper Functions for Node Class
#include "node_1.h"

Node::Node(){
	data_field = value_type();
	link_field = NULL;
}

Node::Node(const value_type data, Node* link){
	data_field = data;
	link_field = link;
}

void Node::set_data(value_type& data){
	data_field = data;
}

void Node::set_link(Node*& link){
	link_field = link;
}

Node::value_type& Node::data(){
	return data_field;
}

const Node::value_type& Node::data() const{
	return data_field;
}

Node*& Node::link(){
	return link_field;
}

const Node* Node::link() const {
	return link_field;
}


Node::size_type node_size(const Node* headPtr){
	const Node* cursor = headPtr;
	int ret = 0;
	for(; cursor != NULL; cursor = cursor->link()){
		++ret;
	}
	return ret;
}

Node::size_type node_count(const Node* headPtr, const Node::value_type target){
	const Node* cursor = headPtr;
	size_t ret = 0;
	for(; cursor != NULL; cursor = cursor->link()){
		if(cursor->data() == target){
			++ret;
		}
	}
	return ret;
}

void node_insert_head(Node*& headPtr, Node::value_type entry){
	headPtr = new Node(entry, headPtr);
}

void node_insert(Node*& insertPtr, Node::value_type entry){
	if(insertPtr == NULL){
		node_insert_head(insertPtr, entry);
	}
	else{
		Node* nodeToInsert = new Node(entry, insertPtr->link());
		insertPtr->set_link(nodeToInsert);
	}
}

const Node* node_search(const Node* headPtr, Node::value_type target){
	const Node* cursor;
	for(cursor = headPtr; cursor != NULL && cursor->data() != target; cursor = cursor->link()){
		if(cursor->data() == target){
			return cursor;
		}
	}
	return NULL;
}

Node* node_search(Node* headPtr, Node::value_type target){
	Node* cursor;
	for(cursor = headPtr; cursor != NULL && cursor->data() != target; cursor = cursor->link())
		;
	return cursor;
}

Node* node_locate(Node* headPtr, Node::size_type pos){
	Node* cursor = headPtr;
	for(Node::size_type i = 1; i < pos && cursor != NULL; ++i){
		cursor = cursor->link();
	}
	return cursor;
}

Node::size_type node_copy(Node*& sourcePtr, Node*& headPtr, Node*& tailPtr){
	if(headPtr == sourcePtr){
		return 0;
	}
	assert(node_size(sourcePtr) > 0);

	headPtr = new Node(sourcePtr->data(), NULL);
	tailPtr = headPtr;
	size_t ret = 1;
	
	Node* cursor = sourcePtr->link();
	
	for(; cursor != NULL; cursor = cursor->link()){
		node_insert_head(headPtr, cursor->data());
		++ret;
	}
	return ret;
}

Node* node_set(Node* headPtr){
	Node* setPtr = NULL;
	Node* cursor = headPtr;
	for(;cursor!=NULL; cursor = cursor->link()){
		if(node_search(setPtr, cursor->data()) == NULL){
			node_insert_head(setPtr, cursor->data());
		}
	}
	return setPtr;
}

void node_reverse(Node*& headPtr){
	if(node_size(headPtr) == 0){
		return;
	}
	
	Node* cursor = headPtr->link();
	Node* tmp;
	
	headPtr->link() = NULL; // tail
	while(cursor != NULL){
		tmp = headPtr;
		headPtr = cursor;
		cursor = cursor->link();
		
		headPtr->link() = tmp;
	}
}

void node_traverse(const Node* headPtr){
	const Node* cursor = headPtr;
	while(cursor != NULL){
		std::cout << cursor->data() << " ";
		cursor = cursor->link();
	}
	std::cout << std::endl;
}

// Postcondition: release every space holding by the nodes in this list pointed by headPtr
void node_clear(Node* headPtr){
	while(headPtr != NULL){
		Node* tmp = headPtr;
		headPtr = headPtr->link();
		delete tmp;
	}
}

// Postcondition: 
void node_remove(Node*& headPtr, Node::value_type target){
	Node* precursor = NULL;
	Node* cursor = headPtr;
	while(cursor != NULL){
		if(cursor->data() == target){
			if(precursor == NULL){
				headPtr = cursor->link();
				delete cursor;
			}
			else{
				precursor->link() = cursor->link();
				delete cursor;
			}
			break;
		}
		precursor = cursor;
		cursor = cursor->link();
	}
}

// Postcondition: headPtr points to the target deleted node list
//					targetPtr pointes to target's link_field which is the next to the deleted node
void node_remove(Node*& headPtr, Node*& targetPtr){
	Node* precursor = NULL;
	Node* cursor = headPtr;
	while(cursor != NULL){
		if(cursor == targetPtr){
			if(precursor == NULL){
				headPtr = cursor->link();
				targetPtr = headPtr;
				delete cursor;
			}
			else{
				precursor->link() = cursor->link();
				targetPtr = cursor->link();
				delete cursor;
			}
			break;
		}
		precursor = cursor;
		cursor = cursor->link();
	}
}

// selection sort with smaller at head
void node_sort(Node*& headPtr){
	Node* resPtr = NULL;
	while(headPtr->link() != NULL){
		Node* biggest_pre = NULL;
		Node* biggest = headPtr;
		Node* cursor_pre = headPtr;
		Node* cursor = headPtr->link();
		while(cursor != NULL){
			if(biggest->data() < cursor->data()){
				biggest = cursor;
				biggest_pre = cursor_pre;
			}
			cursor = cursor->link();
			cursor_pre = cursor_pre->link();
		}
		
		if(biggest_pre == NULL)
			headPtr = biggest->link();
		else
			biggest_pre->link() = biggest->link();
		
		biggest->link() = resPtr;
		resPtr = biggest;
		
	}
	headPtr->link() = resPtr;
}
