#ifndef _HIUKONG_DAN_BAG_3_CIRCULAR_LINKED_LIST_H
#define _HIUKONG_DAN_BAG_3_CIRCULAR_LINKED_LIST_H

#include "circular_linked_list_1.h"
namespace hiukong_dan{

class Bag_CL{
	public:
		typedef CL_Node::value_type value_type;
		typedef std::size_t size_type;
		
		Bag_CL();
		Bag_CL(const Bag_CL& source);
		~Bag_CL();
		size_type count(const value_type& target);
		size_type erase(const value_type& target);
		bool erase_one(const value_type&  target);
		value_type grab() const;
		void insert(const value_type& entry);
		void operator +=(const Bag_CL& addend);
		void operator =(const Bag_CL& source);
		Bag_CL operator +(const Bag_CL& other);
	private:
		CL_Node* headPtr;
		size_type bagSize;
};

};



#endif // _HIUKONG_DAN_BAG_3_CIRCULAR_LINKED_LIST_H
