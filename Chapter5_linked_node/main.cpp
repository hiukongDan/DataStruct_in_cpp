#include "bag_1.h"
#include <iostream>
#include <cstring>
#include "integer_1.h"
#include "sequence_1.h"
#include "sequence_2.h"
#include "circular_linked_list_1.h"

using namespace hiukong_dan;

/*
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

void dsc_chap5_11(){
	hiukong_dan::Integer integer("1234567890");
	hiukong_dan::Integer integer1("987654321");
	
	std::cout<<"   "<<integer.to_string()<<"\n"<<"-  "<<integer1.to_string()<<"\n";
	std::cout<<"-----------------------\n";
	hiukong_dan::Integer integer2 = integer - integer1;
	std::cout<<"  "<<integer2.to_string()<<std::endl;
}


void dsc_chap5_14(){
	hiukong_dan::Sequence s1;
	s1.insert(12);
	s1.insert(100);
	s1.insert(30);
	for(s1.start(); s1.is_item(); s1.advance()){
		std::cout<<s1.current()<<" ";
	}
	
	s1.start();  // ->30 100 12
	s1.advance();	// 30 ->100 12
	s1.advance();	// 30 100 ->12
	s1.attach(77); // 30 100 12 ->77
	s1.insert(89);	// 30 100 12 ->89 77
	s1.remove_current(); // 30 100 12 ->77
	s1.start();	// ->30 100 12 77
	s1.remove_current();	// ->100 12 77
	std::cout<<"current: (100) "<<s1.current()<<std::endl;
	std::cout<<"after removal: ";
	std::cout<<"itemCount: "<<s1.size()<<std::endl;
	for(s1.start(); s1.is_item(); s1.advance()){
		std::cout<<s1.current()<<" ";
	}
}



void dsc_chap5_15(){
		
	DL_Node* headPtr = NULL;
	dl_attach(headPtr, 3);
	DL_Node* tailPtr = headPtr;
	dl_traverse(headPtr);
	dl_attach(tailPtr, 4);
	tailPtr = tailPtr->next_link();
	dl_traverse(headPtr);
	dl_attach(tailPtr, 5);
	tailPtr = tailPtr->next_link();
	dl_traverse(headPtr);
	dl_attach(tailPtr, 6);
	tailPtr = tailPtr->next_link();
	dl_traverse(headPtr);
	
	
	DL_Node *headPtr1, *tailPtr1;
	headPtr = NULL;
	headPtr1 = tailPtr1 = NULL;
	dl_copy(headPtr, headPtr1, tailPtr1);
	std::cout<<"copied: ";
	dl_traverse(headPtr1);
	
	
	Sequence_DL s1;
	Sequence_DL s2;
	s1.remove_current();
	s1.attach(12);
	s1.attach(34);
	s1.attach(89);
	s1.attach(100);
	s1.end();
	s1.remove_current();
	for(s1.start(); s1.is_item(); s1.advance()){
		std::cout<<s1.current()<<" ";
	}
}
*/

void dsc_chap5_17(){
	CL_Node* headPtr = NULL;
	cl_insert_head(headPtr, 1);
	
	std::cout<<cl_count(headPtr, 1)<<std::endl;
	std::cout<<cl_count(headPtr, 0)<<std::endl;
	std::cout<<cl_size(headPtr)<<std::endl;
	cl_insert_head(headPtr, 2);
	std::cout<<cl_count(headPtr, 2)<<std::endl;
	std::cout<<cl_size(headPtr)<<std::endl;
	CL_Node* cursor = headPtr->link();
	cl_insert(cursor, 3);
	cl_attach(cursor, 4);
	cl_traverse(headPtr);
	//CL_Node* target = cl_search(headPtr, 3);
	//cl_remove(headPtr, target);
	//cl_remove(headPtr, 2);
	//cl_traverse(headPtr);
	CL_Node* headPtr1 = NULL;
	cl_copy(headPtr, headPtr1);
	cl_traverse(headPtr1);
	cl_insert_head(headPtr, 8);
	cl_insert_head(headPtr, 9);
	cl_copy(headPtr, headPtr1);
	cl_traverse(headPtr1);
}

int main(int argc, char** argv){
	
	dsc_chap5_17();
	
	return 0;
}


