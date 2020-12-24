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
	// TODO: determine which goes first, x or y
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

// reverse node_list
void _dsc_chap5_4(Node*& headPtr){
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

void dsc_chap5_4(){
	Node* headPtr = NULL;
	node_insert_head(headPtr, "hello");
	node_insert_head(headPtr, "and");
	node_insert_head(headPtr, "good");
	node_insert_head(headPtr, "bye");
	node_insert_head(headPtr, "and");
	
	node_traverse(headPtr);
	
	_dsc_chap5_4(headPtr);
	node_traverse(headPtr);
}

// Preconditions: assumed that headPtr1 and headPtr2 are two pointers pointed to two small-first sorted node-list
// Return value: a new head pointer pointed to a merged sorted set
Node* _dsc_chap5_5(Node* headPtr1, Node* headPtr2){
	Node* resPtr = NULL;

	while(headPtr1 != NULL && headPtr2 != NULL){
		if(headPtr1->data() == headPtr2->data()){
			node_insert_head(resPtr, headPtr1->data());
			headPtr1 = headPtr1->link();
			headPtr2 = headPtr2->link();
		}
		else if(headPtr1->data() < headPtr2->data()){
			node_insert_head(resPtr, headPtr1->data());
			headPtr1 = headPtr1->link();
		}
		else{
			node_insert_head(resPtr, headPtr2->data());
			headPtr2 = headPtr2->link();
		}
	}
	
	if(headPtr1 != NULL){
		while(headPtr1 != NULL){
			node_insert_head(resPtr, headPtr1->data());
			headPtr1 = headPtr1->link();
		}
	}
	else if(headPtr2 != NULL){
		while(headPtr2 != NULL){
			node_insert_head(resPtr, headPtr2->data());
			headPtr2 = headPtr2->link();
		}
	}
	
	node_reverse(resPtr);
	return resPtr;
}

void dsc_chap5_5(){
	Node* headPtr1 = NULL;
	Node* headPtr2 = NULL;
	node_insert_head(headPtr1, "f");
	node_insert_head(headPtr1, "e");
	node_insert_head(headPtr1, "d");
	node_insert_head(headPtr1, "c");
	node_insert_head(headPtr1, "b");
	node_insert_head(headPtr1, "a");
	
	node_insert_head(headPtr2, "i");
	node_insert_head(headPtr2, "h");
	node_insert_head(headPtr2, "g");
	node_insert_head(headPtr2, "f");
	node_insert_head(headPtr2, "e");
	
	Node* resPtr = _dsc_chap5_5(headPtr1, headPtr2);
	
	std::cout<<"list 1: ";
	node_traverse(headPtr1);
	std::cout<<"list 2: ";
	node_traverse(headPtr2);
	std::cout<<"merged outcome: ";
	node_traverse(resPtr);
}

// Precondition: SrcPtr: pointer pointed to the original node list
//		splitter: the Value used to splite the original node list
//		dstPtr1, dstPtr2: the two pointers holding the splited node lists
//			dstPtr1: holds every nodes in srcPtr which is smaller than the splitter
//			dstPtr2: holds anything others
// Postcondition: Destroy the original node list using node_clear
//		Return the two splitted ndoe lists using pointer references
void _dsc_chap5_6(Node* srcPtr, Node::value_type splitter, Node*& dstPtr1, Node*& dstPtr2){
	while(srcPtr != NULL){
		if(srcPtr->data() < splitter){
			node_insert_head(dstPtr1, srcPtr->data());
		}
		else{
			node_insert_head(dstPtr2, srcPtr->data());
		}
		srcPtr = srcPtr->link();
	}
}

void dsc_chap5_6(){
	Node* dstPtr1 = NULL;
	Node* dstPtr2 = NULL;
	
	Node* headPtr = NULL;
	node_insert_head(headPtr, "hello");
	node_insert_head(headPtr, "and");
	node_insert_head(headPtr, "good");
	node_insert_head(headPtr, "bye");
	node_insert_head(headPtr, "and");
	
	std::cout<<"original list: ";
	node_traverse(headPtr);
	
	std::string splitter = "c";
	
	_dsc_chap5_6(headPtr, splitter, dstPtr1, dstPtr2);
	
	std::cout<<"splitter: "<<splitter<<std::endl;
	
	std::cout<<"dst1: ";
	node_traverse(dstPtr1);
	std::cout<<"dst2: ";
	node_traverse(dstPtr2);
}

// Using selection sort
void sort_list(Node*& headPtr){
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

void dsc_chap5_7(){
	Node* headPtr = NULL;
	node_insert_head(headPtr, "hello");
	node_insert_head(headPtr, "and");
	node_insert_head(headPtr, "good");
	node_insert_head(headPtr, "bye");
	node_insert_head(headPtr, "and");
	
	sort_list(headPtr);
	node_traverse(headPtr);
	
	Node* headPtr1 = NULL;
	node_insert_head(headPtr1, "f");
	node_insert_head(headPtr1, "e");
	node_insert_head(headPtr1, "d");
	node_insert_head(headPtr1, "c");
	node_insert_head(headPtr1, "b");
	node_insert_head(headPtr1, "a");
	
	node_insert_head(headPtr1, "i");
	node_insert_head(headPtr1, "h");
	node_insert_head(headPtr1, "g");
	node_insert_head(headPtr1, "f");
	node_insert_head(headPtr1, "e");
	
	sort_list(headPtr1);
	node_traverse(headPtr1);
}

void dsc_chap5_9(){
	Bag bag1;
	bag1.put("hello");
	bag1.put("and");
	bag1.put("good");
	bag1.put("bye");
	bag1.put("and");
	
	Bag bag2;
	bag2.put("and");
	bag2.put("good");
	
	std::cout<<"bag1: ";
	bag1.traverse();
	std::cout<<"bag2: ";
	bag2.traverse();
	
	bag1 = bag1 - bag2;
	std::cout<<"ret :";
	bag1.traverse();
}

int main(int argc, char** argv){
	
	dsc_chap5_9();
	
	return 0;
}


