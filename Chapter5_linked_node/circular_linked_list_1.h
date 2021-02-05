#ifndef _HIUKONG_DAN_CIRCULAR_LINKED_LIST_1_H_
#define _HIUKONG_DAN_CIRCULAR_LINKED_LIST_1_H_

#include <cstdlib>

namespace hiukong_dan{
	
class CL_Node{
	public:
		typedef int value_type;
		typedef std::size_t size_type;
		
		CL_Node();
		CL_Node(value_type data, CL_Node* link);
		
		void set_link(CL_Node*& link);
		void set_data(value_type& data);
		
		value_type& data();
		const value_type data() const;
		CL_Node*& link();
		const CL_Node* link() const;
		
	private:
		value_type data_field;
		CL_Node* link_field;
};

CL_Node::size_type cl_size(const CL_Node* headPtr);

CL_Node::size_type cl_count(const CL_Node* headPtr, const CL_Node::value_type target);

void cl_insert_head(CL_Node*& headPtr, CL_Node::value_type entry);

void cl_insert(CL_Node*& insertPtr, CL_Node::value_type entry);

void cl_attach(CL_Node*& attachPtr, CL_Node::value_type entry);

const CL_Node* cl_search(const CL_Node* headPtr, CL_Node::value_type target);

CL_Node* cl_search(CL_Node* headPtr, CL_Node::value_type target);

bool cl_remove(CL_Node*& headPtr, CL_Node::value_type target);

bool cl_remove(CL_Node*& headPtr, CL_Node* targetPtr);

//CL_Node* cl_locate(CL_Node* headPtr, CL_Node::size_type i);

CL_Node::size_type cl_copy(CL_Node*& sourcePtr, CL_Node*& headPtr);

CL_Node::size_type cl_copy(const CL_Node* const& sourcePtr, CL_Node*& headPtr);

void cl_traverse(const CL_Node* headPtr);

void cl_clear(CL_Node* headPtr);

};

#endif
