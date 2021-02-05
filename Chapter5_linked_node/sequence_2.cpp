#include "sequence_2.h"
#include <cassert>

//=======================================================================
//  Implementation of Sequence Class
//  Using Doubly-linked list
//		
//													 Hiukong Dan
//													 26/Dec/2020
//=======================================================================

namespace hiukong_dan{

Sequence_DL::Sequence_DL(){
	headPtr = cursor = tailPtr = NULL;
	itemCount = 0;
}

Sequence_DL::Sequence_DL(Sequence_DL& other){
	if(&other == this){
		return;
	}
	
	assert(other.size() > 0);
	
	itemCount = other.size();
	dl_clear(headPtr);
	headPtr = tailPtr = cursor = NULL;
	
	dl_copy(other.headPtr, headPtr, tailPtr);
}

void Sequence_DL::start(){
	cursor = headPtr;
}

void Sequence_DL::end(){
	cursor = tailPtr;
}

void Sequence_DL::advance(){
	if(is_item())
		cursor = cursor->next_link();
}

void Sequence_DL::retreat(){
	if(is_item())
		cursor = cursor->prev_link();
}

void Sequence_DL::insert(const value_type& entry){
	if(size() == 0){
		dl_insert_head(headPtr, entry);
		cursor = tailPtr = headPtr;
		++itemCount;
	}
	else if(is_item()){
		if(cursor == headPtr){
			dl_insert_head(cursor, entry);
			headPtr = cursor;
		}
		else{
			dl_insert(cursor, entry);
		}
		++itemCount;
	}
}

void Sequence_DL::attach(const value_type& entry){
	if(size() == 0){
		dl_insert_head(headPtr, entry);
		cursor = tailPtr = headPtr;
		++itemCount;
	}
	else if(is_item()){
		if(cursor == tailPtr){
			dl_attach(cursor, entry);
			tailPtr = cursor;
		}
		else{
			dl_attach(cursor, entry);
		}
		++itemCount;
	}
}

void Sequence_DL::remove_current(){
	assert(is_item());
	
	if(cursor == tailPtr){
		tailPtr = tailPtr->prev_link();
		delete cursor;
		--itemCount;
		if(itemCount == 0){
			headPtr = NULL;
		}
		else{
			tailPtr->set_next_link(NULL);
		}
		cursor = NULL;
	}
	else if(cursor == headPtr){
		headPtr = headPtr->next_link();
		delete cursor;
		--itemCount;
		if(itemCount == 0){
			tailPtr = cursor = NULL;
		}
		else{
			headPtr->set_prev_link(NULL);
			cursor = headPtr;
		}
	}
	else{
		cursor->prev_link()->set_next_link(cursor->next_link());
		cursor->next_link()->set_prev_link(cursor->prev_link());
		DL_Node* old = cursor;
		cursor = cursor->next_link();
		delete old;
		itemCount--;
	}
}

bool Sequence_DL::is_item(){
	return cursor != NULL;
}

Sequence_DL::value_type Sequence_DL::current(){
	assert(is_item());
	return cursor->data();
}

Sequence_DL::size_type Sequence_DL::size(){
	return itemCount;
}


};
