#ifndef HIUKONG_DAN_BAG_1_H
#define HIUKONG_DAN_BAG_1_H

#include "node_1.h"

class Bag{
	public:
		typedef Node::value_type value_type;
		typedef Node::size_type size_type;
		
		Bag();
		void put(const value_type entry);
		Node* fetch(const value_type target);
		Bag::value_type grab();
		size_t size();
		
	private:
		Node* headPtr;
		size_t bagSize;
};

#endif // HIUKONG_DAN_BAG_1_H
