#ifndef _HIUKONG_DAN_SEQUENCCE_2_H_
#define _HIUKONG_DAN_SEQUENCCE_2_H_

#include "doubly_linked_list_1.h"

namespace hiukong_dan{
class Sequence_DL{
	public:
		typedef DL_Node::size_type size_type;
		typedef DL_Node::value_type value_type;
		
		Sequence_DL();
		Sequence_DL(Sequence_DL&);
		
		void start();
		void end();
		void advance();
		void retreat();
		void insert(const value_type& entry);
		void attach(const value_type& entry);
		void remove_current();
		
		size_type size();
		bool is_item();
		value_type current();
		//Sequence operator=(const Sequence&);
		
	private:
		DL_Node* headPtr;
		DL_Node* cursor;
		DL_Node* tailPtr;
		size_type itemCount;
};	
};
#endif
