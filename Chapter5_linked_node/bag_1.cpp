// IMPLEMENTATION FOR Bag CLASS

#include "bag_1.h"

Bag::Bag(){
	this->bagSize = 0;
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
