#include "doubly_linked_list_1.h"

#include <iostream>

namespace hiukong_dan{

DL_Node::DL_Node(){
	data_field = value_type();
	prev_link_field = NULL;
	next_link_field = NULL;
}

DL_Node::DL_Node(value_type data, DL_Node* prev_link_field, DL_Node* next_link_field){
	data_field = data;
	this->prev_link_field = prev_link_field;
	this->next_link_field = next_link_field;
}

void DL_Node::set_data(const value_type& data){
	data_field = data;
}

void DL_Node::set_prev_link(DL_Node* link){
	prev_link_field = link;
}

void DL_Node::set_next_link(DL_Node* link){
	next_link_field = link;
}

DL_Node::value_type& DL_Node::data(){
	return data_field;
}

const DL_Node::value_type& DL_Node::data() const{
	return data_field;
}

DL_Node*& DL_Node::prev_link(){
	return prev_link_field;
}

const DL_Node* DL_Node::prev_link() const{
	return prev_link_field;
}

DL_Node*& DL_Node::next_link(){
	return next_link_field;
}

const DL_Node* DL_Node::next_link() const{
	return next_link_field;
}

DL_Node::size_type dl_size(const DL_Node* headPtr){
	const DL_Node* cursor = headPtr;
	DL_Node::size_type ret = 0;
	while(cursor != NULL){
		++ret;
		cursor = cursor->next_link();
	}
	return ret;
}

DL_Node::size_type dl_count(const DL_Node* headPtr, const DL_Node::value_type target){
	const DL_Node* cursor = headPtr;
	DL_Node::size_type ret = 0;
	while(cursor != NULL){
		if(cursor->data() == target){
			++ret;
		}
		cursor = cursor->next_link();
	}
	return ret;
}

// Postcondition: headPtr now points to the newly inserted item
void dl_insert_head(DL_Node*& headPtr, DL_Node::value_type entry){
	DL_Node* old = headPtr;
	headPtr = new DL_Node(entry, NULL, headPtr);
	if(old != NULL){
		old->set_prev_link(headPtr);
	}
}

// Postcondition: headPtr now points to the newly inserted item
void dl_insert(DL_Node*& insertPtr, DL_Node::value_type entry){
	if(insertPtr == NULL || insertPtr->prev_link() == NULL){
		dl_insert_head(insertPtr, entry);
	}
	else{
		DL_Node* nodeToInsert = new DL_Node(entry, insertPtr->prev_link(), insertPtr);
		insertPtr->prev_link()->set_next_link(nodeToInsert);			
		insertPtr->set_prev_link(nodeToInsert);
		insertPtr = nodeToInsert;
	}
}

// Postcondition: headPtr now points to the newly attached item
void dl_attach(DL_Node*& attachPtr, DL_Node::value_type entry){
	if(attachPtr == NULL){
		dl_insert_head(attachPtr, entry);
	}
	else{
		DL_Node* nodeToAttach = new DL_Node(entry, attachPtr, attachPtr->next_link());
		if(attachPtr->next_link() != NULL){
			attachPtr->next_link()->set_prev_link(nodeToAttach);
		}
		attachPtr->set_next_link(nodeToAttach);
		attachPtr = nodeToAttach;
	}
}

const DL_Node* dl_search(const DL_Node* headPtr, DL_Node::value_type target){
	const DL_Node* cursor = headPtr;
	while(cursor != NULL){
		if(cursor->data() == target){
			break;
		}
		cursor = cursor->next_link();
	}
	return cursor;
}

DL_Node* dl_search(DL_Node* headPtr, DL_Node::value_type target){
	DL_Node* cursor = headPtr;
	while(cursor != NULL){
		if(cursor->data() == target){
			break;
		}
		cursor = cursor->next_link();
	}
	return cursor;
}

void dl_remove(DL_Node*& headPtr, DL_Node::value_type target){
	DL_Node* cursor = dl_search(headPtr, target);
	if(cursor != NULL){
		DL_Node* prev = cursor->prev_link();
		DL_Node* next = cursor->next_link();
		if(prev != NULL){
			prev->set_next_link(next);
		}
		if(next != NULL){
			next->set_prev_link(prev);
		}
		delete cursor;
	}
}

DL_Node* dl_locate(DL_Node* headPtr, DL_Node::size_type i){
	DL_Node* cursor = headPtr;
	for(DL_Node::size_type x = 0; x < i && cursor != NULL; ++x){
		cursor = cursor->next_link();
	}
	return cursor;
}

DL_Node::size_type dl_copy(DL_Node*& sourcePtr, DL_Node*& headPtr, DL_Node*& tailPtr){
	if(sourcePtr == NULL || dl_size(sourcePtr) == 0)
		return 0;
	
	dl_insert_head(headPtr, sourcePtr->data());
	tailPtr = headPtr;
	DL_Node* cursor = sourcePtr->next_link();
	DL_Node::size_type ret = 1;
	while(cursor != NULL){
		dl_attach(tailPtr, cursor->data());
		tailPtr = tailPtr->next_link();
		cursor = cursor->next_link();
	}
}

void dl_reverse(DL_Node*& headPtr);

void dl_traverse(const DL_Node* headPtr){
	const DL_Node* cursor = headPtr;
	while(cursor != NULL){
		std::cout<<cursor->data()<<" ";
		cursor = cursor->next_link();
	}
	std::cout<<std::endl;
}

void dl_clear(DL_Node* headPtr){
	DL_Node* old;
	while(headPtr != NULL){
		old = headPtr;
		headPtr = headPtr->next_link();
		delete old;
	}
}

void dl_sort(DL_Node*& headPtr){
	
}
};
