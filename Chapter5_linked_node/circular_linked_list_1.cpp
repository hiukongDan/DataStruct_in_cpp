#include "circular_linked_list_1.h"

#include<iostream>
#include<cassert>

namespace hiukong_dan{

CL_Node::CL_Node(){
	data_field = value_type();
	link_field = NULL;	
}

CL_Node::CL_Node(CL_Node::value_type data, CL_Node* link){
	this->data_field = data;
	this->link_field = link;
}

void CL_Node::set_link(CL_Node*& link){
	link_field = link;	
}

void CL_Node::set_data(CL_Node::value_type& data){
	data_field = data;
}

CL_Node::value_type& CL_Node::data(){
	return data_field;
}

const CL_Node::value_type CL_Node::data() const{
	return data_field;
}

CL_Node*& CL_Node::link(){
	return link_field;	
}

const CL_Node* CL_Node::link() const{
	return link_field;
}


CL_Node::size_type cl_size(const CL_Node* headPtr){
	const CL_Node* cursor = headPtr;
	CL_Node::size_type ret = 0;
	while(cursor != NULL && cursor->link() != headPtr){
		++ret;
		cursor = cursor->link();
	}
	if(cursor != NULL)
		++ret;
	return ret;
}

CL_Node::size_type cl_count(const CL_Node* headPtr, const CL_Node::value_type target){
	CL_Node::size_type ret = 0;
	if(headPtr == NULL){
		return 0;
	}
	const CL_Node* cursor = headPtr;
	while(cursor->link() != headPtr){
		if(cursor->data() == target)
			++ret;
		cursor = cursor->link();
	}
	if(cursor != NULL && cursor->data() == target){
		++ret;
	}
	return ret;
}

void cl_insert_head(CL_Node*& headPtr, CL_Node::value_type entry){
	if(headPtr == NULL){
		headPtr = new CL_Node(entry, NULL);
		headPtr->set_link(headPtr);
	}
	else{
		// find tailPtr
		CL_Node* cursor = headPtr;
		while(cursor->link() != headPtr){
			cursor = cursor->link();
		}
		headPtr = new CL_Node(entry, headPtr);
		cursor->set_link(headPtr);
	}
}

void cl_insert(CL_Node*& insertPtr, CL_Node::value_type entry){
	cl_insert_head(insertPtr, entry);
}

void cl_attach(CL_Node*& attachPtr, CL_Node::value_type entry){
	if(attachPtr == NULL){
		cl_insert_head(attachPtr, entry);
	}
	else{
		CL_Node* nodeToInsert = new CL_Node(entry, attachPtr->link());
		attachPtr->set_link(nodeToInsert);
		attachPtr = nodeToInsert;
	}
}

const CL_Node* cl_search(const CL_Node* headPtr, CL_Node::value_type target){
	if(headPtr != NULL && headPtr->data() == target){
		return headPtr;
	}
	const CL_Node* cursor = headPtr;
	while(cursor != NULL && cursor->link() != headPtr){
		if(cursor->data() == target)
			break;
		
		cursor = cursor->link();
	}
	return cursor;
}

CL_Node* cl_search(CL_Node* headPtr, CL_Node::value_type target){
		if(headPtr != NULL && headPtr->data() == target){
		return headPtr;
	}
	CL_Node* cursor = headPtr;
	while(cursor != NULL && cursor->link() != headPtr){
		if(cursor->data() == target)
			break;
		
		cursor = cursor->link();
	}
	return cursor;
}

bool cl_remove(CL_Node*& headPtr, CL_Node::value_type target){
	return cl_remove(headPtr, cl_search(headPtr, target));
}

bool cl_remove(CL_Node*& headPtr, CL_Node* targetPtr){
	if(headPtr == NULL){
		return false;
	}
	CL_Node* cursor = headPtr;
	do{
		if(cursor != NULL && cursor->link() == targetPtr){
			cursor->set_link(targetPtr->link());
			if(targetPtr == headPtr){
				if(cursor == headPtr){
					cursor = NULL;
					headPtr = NULL;
				}
				else{
					headPtr = cursor;
				}
			}
			delete targetPtr;
			targetPtr = NULL;	
			return true;
		}
		cursor = cursor->link();
	}while(cursor != NULL && cursor != headPtr);
	return false;
}

CL_Node::size_type cl_copy(CL_Node*& sourcePtr, CL_Node*& headPtr){
	assert(cl_size(sourcePtr) > 0);
	// if(cl_size(sourcePtr) == 0) return 0;
	CL_Node* srcCursor = sourcePtr;
	CL_Node* dstCursor = headPtr;
	
	cl_insert_head(headPtr, srcCursor->data());
	dstCursor = headPtr;
	srcCursor = srcCursor->link();
	while(srcCursor != sourcePtr){
		cl_attach(dstCursor, srcCursor->data());
		srcCursor = srcCursor->link();
		if(srcCursor == sourcePtr){
			break;
		}
	}
}

CL_Node::size_type cl_copy(const CL_Node* const& sourcePtr, CL_Node*& headPtr){
	assert(cl_size(sourcePtr) > 0);
	// if(cl_size(sourcePtr) == 0) return 0;
	const CL_Node* srcCursor = sourcePtr;
	CL_Node* dstCursor = headPtr;
	
	cl_insert_head(headPtr, srcCursor->data());
	dstCursor = headPtr;
	srcCursor = srcCursor->link();
	while(srcCursor != sourcePtr){
		cl_attach(dstCursor, srcCursor->data());
		srcCursor = srcCursor->link();
		if(srcCursor == sourcePtr){
			break;
		}
	}
}

void cl_traverse(const CL_Node* headPtr){
	const CL_Node* cursor = headPtr;
	while(cursor != NULL && cursor->link() != headPtr){
		std::cout<<cursor->data()<<" ";
		cursor = cursor->link();
	}
	if(cursor!=NULL){
		std::cout<<cursor->data()<<"\n";
	}
}

void cl_clear(CL_Node* headPtr){
	CL_Node* cursor = headPtr;
	while(cursor != NULL && cursor->link() != headPtr){
		CL_Node* old = cursor;
		cursor = cursor->link();
		delete old;
	}
	if(cursor != NULL){
		delete cursor;
	}
	headPtr = NULL;
}

};
