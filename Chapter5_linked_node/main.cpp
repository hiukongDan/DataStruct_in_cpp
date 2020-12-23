// Test Program for node_1.h

#include "bag_1.h"
#include <iostream>
#include <cstring>

// Precondition: typedef std::string Node::value_type at node_1.h
void dsc_chap5_1(){
	Bag nounBag;
	Bag verbBag;
	
	std::string tmp;
	
	Bag::size_type wordCount = 5;
	Bag::size_type testCount = 5;
	
	std::cout<<"Enter " << wordCount << " nouns: "<<std::endl;
	for(Bag::size_type i = 0; i < wordCount; i++){
		std::cin >> tmp;
		nounBag.put(tmp);
	}
	
	std::cout<<"Enter " << wordCount << " verbs: "<<std::endl;
	for(Bag::size_type i = 0; i < wordCount; ++i){
		std::cin>>tmp;
		verbBag.put(tmp);
	}
	
	for(Bag::size_type i = 0; i < testCount; ++i){
		std::cout << "The " << nounBag.grab() << " " << verbBag.grab() << "s " <<
			"the " << nounBag.grab() << ".\n";
	}
	std::cout<<std::endl;
}

void dsc_chap5_2(){	
	Node* headPtr = NULL;
	node_insert_head(headPtr, "hello");
	node_insert_head(headPtr, "and");
	node_insert_head(headPtr, "good");
	node_insert_head(headPtr, "bye");
	node_insert_head(headPtr, "and");
	
	Node* setPtr = node_set(headPtr);
	node_traverse(headPtr);
	node_traverse(setPtr);
}

void _dsc_chap5_3(Node* headPtr, Node::value_type x, Node::value_type y){
	Node* xPtr = node_search(headPtr, x);
	Node* yPtr = node_search(headPtr, y);

	if(xPtr == NULL || yPtr == NULL){
		std::cout<<"target not found"<<std::endl;
		return;
	}
	for(xPtr = xPtr->link(); xPtr != NULL && xPtr != yPtr; xPtr = xPtr->link()){
		std::cout<<xPtr->data()<<std::endl;
	}
}

void dsc_chap5_3(){
	Node* headPtr = NULL;
	node_insert_head(headPtr, "hello");
	node_insert_head(headPtr, "and");
	node_insert_head(headPtr, "good");
	node_insert_head(headPtr, "bye");
	node_insert_head(headPtr, "and");
	
	_dsc_chap5_3(headPtr, "and", "hello");
}

int main(int argc, char** argv){
	
	dsc_chap5_3();
	
	return 0;
}


