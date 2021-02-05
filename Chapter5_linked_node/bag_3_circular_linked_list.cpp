#include "bag_3_circular_linked_list.h"
#include <cassert>

namespace hiukong_dan{

Bag_CL::Bag_CL(){
	headPtr= NULL;
	bagSize = 0;
}

Bag_CL::Bag_CL(const Bag_CL& source){
	headPtr = NULL;
	cl_copy(source.headPtr, headPtr);
	bagSize = source.bagSize;
}

Bag_CL::~Bag_CL(){
	cl_clear(headPtr);
	bagSize = 0;
}

Bag_CL::size_type Bag_CL::count(const Bag_CL::value_type& target){
	return cl_count(headPtr, target);
}

Bag_CL::size_type Bag_CL::erase(const Bag_CL::value_type& target){
	while(cl_remove(headPtr, target))
		;
}

bool Bag_CL::erase_one(const Bag_CL::value_type& target){
	return cl_remove(headPtr, target);
}

Bag_CL::value_type Bag_CL::grab() const{
	assert(bagSize > 0);
	
	Bag_CL::size_type i = rand() % bagSize;
	CL_Node* cursor = headPtr;
	for(size_type x = 0; x < i; ++x){
		cursor = cursor->link();
	}
	
	return cursor->data();
}

void Bag_CL::insert(const Bag_CL::value_type& entry){
	cl_insert(headPtr, entry);
	++bagSize;
}

void Bag_CL::operator +=(const Bag_CL& addend){
	if(addend.bagSize == 0)
		return;
	cl_copy(addend.headPtr, headPtr);
	bagSize += addend.bagSize;
}

void Bag_CL::operator =(const Bag_CL& source){
	headPtr = NULL;
	cl_copy(source.headPtr, headPtr);
	bagSize = source.bagSize;
}

Bag_CL Bag_CL::operator +(const Bag_CL& other){
	Bag_CL ret;
	ret += other;
	return ret;
}
	
};
