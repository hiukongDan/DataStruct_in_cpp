#ifndef _HIUKONG_DAN_SEQUENCE_1_H
#define _HIUKONG_DAN_SEQUENCE_1_H

#include "node_1.h"

namespace hiukong_dan{
class Sequence{
	public:
		typedef Node::size_type size_type;
		typedef Node::value_type value_type;
		
		Sequence();
		Sequence(Sequence&);
		
		void start();
		void advance();
		void insert(const value_type& entry);
		void attach(const value_type& entry);
		void remove_current();
		
		size_type size();
		bool is_item();
		value_type current();
		//Sequence operator=(const Sequence&);
		
	private:
		Node* headPtr;
		Node* cursor;
		Node* tailPtr;
		size_type itemCount;
};	
};


#endif
