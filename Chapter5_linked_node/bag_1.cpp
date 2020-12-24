// IMPLEMENTATION FOR Bag CLASS

#include "bag_1.h"

Bag::Bag(){
	this->bagSize = 0;
	this->headPtr = NULL;
}

Bag::Bag(const Bag& other){
	if(&other == this)
		return;
		
	if(other.bagSize == 0)
		return;
		
	this->bagSize = other.bagSize;
	
	this->headPtr = NULL;
	Node* otherHeadPtr = other.headPtr;
	
	node_insert_head(headPtr, otherHeadPtr->data());
	Node* cursor = headPtr;
	otherHeadPtr = otherHeadPtr->link();
	while(otherHeadPtr != NULL){
		node_insert(cursor, otherHeadPtr->data());
		cursor = cursor->link();
		otherHeadPtr = otherHeadPtr->link();
	}
}
	
void Bag::put(const Bag::value_type entry){
	node_insert_head(headPtr, entry);
	++this->bagSize;
}
	
Node* Bag::fetch(const Bag::value_type target){
	return node_search(headPtr, target);
}

Bag::value_type Bag::grab(){
	Bag::size_type i = rand() % size();
	assert(size() >= i);
	
	Node* cursor = node_locate(headPtr, i);
	
	assert(cursor != NULL);
	return cursor->data();
}
	
Bag::size_type Bag::size(){
	return this->bagSize;
}

Node*& Bag::head(){
	return headPtr;
}

const Node* Bag::head() const{
	return headPtr;
}

void Bag::traverse(){
	node_traverse(this->headPtr);
}

void Bag::operator-=(const Bag& other){
	Node* otherCursor = other.headPtr;
	Node* cursor = headPtr;
	
	node_sort(otherCursor);
	node_sort(cursor);
	while(cursor != NULL && otherCursor != NULL){
		if(cursor->data() == otherCursor->data()){
			node_remove(this->headPtr, cursor);
			otherCursor = otherCursor->link();
		}
		else if(cursor->data() < otherCursor->data()){
			cursor = cursor->link();
		}
		else if(cursor->data() > otherCursor->data()){
			otherCursor = otherCursor->link();
		}
	}
}

Bag Bag::operator-(const Bag& other){
	Bag ret(*this);
	ret -= other;
	return ret;
}
