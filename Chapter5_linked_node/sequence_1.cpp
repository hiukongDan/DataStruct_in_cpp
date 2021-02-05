#include "sequence_1.h"
#include <cassert>

namespace hiukong_dan{

Sequence::Sequence(){
	headPtr = cursor = tailPtr = NULL;
	itemCount = 0;
}

Sequence::Sequence(Sequence& other){
	if(&other == this){
		return;
	}
	
	assert(other.size() > 0);
	
	itemCount = other.size();
	node_clear(headPtr);
	headPtr = tailPtr = cursor = NULL;
	Node* cursor_other = other.headPtr;
	
	node_insert(headPtr, cursor_other->data());
	cursor = tailPtr = headPtr;
	cursor_other = cursor_other->link();
	while(cursor_other != NULL){
		node_insert(tailPtr, cursor_other->data());
		tailPtr = tailPtr->link();
		cursor_other = cursor_other->link();
	}
}

void Sequence::start(){
	cursor = headPtr;
}

void Sequence::advance(){
	if(is_item())
		cursor = cursor->link();
}

void Sequence::insert(const value_type& entry){
	if(size() == 0){
		node_insert_head(headPtr, entry);
		cursor = tailPtr = headPtr;
		++itemCount;
	}
	else if(is_item()){
		node_insert(cursor, cursor->data());
		cursor->data() = entry;
		++itemCount;
	}
}

void Sequence::attach(const value_type& entry){
	if(size() == 0){
		node_insert_head(headPtr, entry);
		cursor = tailPtr = headPtr;
		++itemCount;
	}
	else if(is_item()){
		node_insert(cursor, entry);
		++itemCount;
		cursor = cursor->link();
	}
}

void Sequence::remove_current(){
	if(size() == 0)
		return;
	assert(is_item());
	Node* cursor_next = cursor->link();
	if(cursor_next == NULL){
		if(size() == 1){
			delete cursor;
			itemCount = 0;
			headPtr = tailPtr = cursor = NULL;
		}
		else{
			tailPtr=  headPtr;
			while(tailPtr->link() != cursor){
				tailPtr = tailPtr->link();
			}
			tailPtr->link() = NULL; 	// break the link
			delete cursor;
			--itemCount;
			cursor = NULL;
		}
	}
	else{
		if(cursor_next->link() == NULL){
			tailPtr = cursor;
		}
		--itemCount;
		cursor->data() = cursor_next->data();
		cursor->link() = cursor_next->link();
		delete cursor_next;
	}
}

bool Sequence::is_item(){
	return cursor != NULL;
}

Sequence::value_type Sequence::current(){
	assert(is_item());
	return cursor->data();
}

Sequence::size_type Sequence::size(){
	return itemCount;
}
};

