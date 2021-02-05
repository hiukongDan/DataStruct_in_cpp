#ifndef _HIUKONG_DAN_DOUBLY_LINKED_LIST_1_H_
#define _HIUKONG_DAN_DOUBLY_LINKED_LIST_1_H_

#include <cstdlib>

namespace hiukong_dan{
class DL_Node{
	public:
		typedef int value_type;
		typedef std::size_t size_type;
		
		DL_Node();
		DL_Node(const DL_Node&);
		DL_Node(value_type data, DL_Node* prev_link, DL_Node* next_link);
		
		void set_data(const value_type& data);
		void set_prev_link(DL_Node* link);
		void set_next_link(DL_Node* link);
		
		value_type& data();
		const value_type& data() const;
		DL_Node*& prev_link();
		const DL_Node* prev_link() const;
		DL_Node*& next_link();
		const DL_Node* next_link() const;
		
	private:
		DL_Node* prev_link_field;
		DL_Node* next_link_field;
		value_type data_field;
};

DL_Node::size_type dl_size(const DL_Node* headPtr);

DL_Node::size_type dl_count(const DL_Node* headPtr, const DL_Node::value_type target);

void dl_insert_head(DL_Node*& headPtr, DL_Node::value_type entry);

void dl_insert(DL_Node*& insertPtr, DL_Node::value_type entry);

void dl_attach(DL_Node*& attachPtr, DL_Node::value_type entry);

const DL_Node* dl_search(const DL_Node* headPtr, DL_Node::value_type target);

DL_Node* dl_search(DL_Node* headPtr, DL_Node::value_type target);

void dl_remove(DL_Node*& headPtr, DL_Node::value_type target);

void dl_remove(DL_Node*& headPtr, DL_Node*& targetPtr);

DL_Node* dl_locate(DL_Node* headPtr, DL_Node::size_type i);

DL_Node::size_type dl_copy(DL_Node*& sourcePtr, DL_Node*& headPtr, DL_Node*& tailPtr);

void dl_traverse(const DL_Node* headPtr);

void dl_clear(DL_Node* headPtr);

void dl_sort(DL_Node* headPtr);

};

#endif
