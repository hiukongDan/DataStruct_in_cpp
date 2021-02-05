#ifndef _HIUKONG_DAN_BAG_1_H
#define _HIUKONG_DAN_BAG_1_H

#include "node_1.h"	
class Bag{
	public:
		typedef Node::value_type value_type;
		typedef std::size_t size_type;
		
		Bag();
		Bag(const Bag& other);
		void put(const value_type entry);
		Node* fetch(const value_type target);
		Bag::value_type grab();
		size_type size();
		
		Node*& head();
		const Node* head() const;
		
		void operator-=(const Bag& other);
		Bag operator -(const Bag&);
		
		void traverse();
	private:
		Node* headPtr;
		size_type bagSize;
};



#endif // HIUKONG_DAN_BAG_1_H
