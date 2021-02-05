#ifndef HIUKONG_DAN_NODE_2_H
#define HIUKONG_DAN_NODE_2_H

namespace hiukong_dan{

template<class Item>
class Node{
	public:
	    typedef std::size_t size_type;
		Node(Item data, Node* link){
			data_field = data;
			link_field = link;
		}

		void set_data(Item data){data_field = data;}
		void set_link(Node* link){link_field = link;}

		Item& data(){return data_field;}
		Node*& link(){return link_field;}

		const Item& data() const{return data_field;}
		const Node* link() const{return link_field;}

	private:
		Item data_field;
		Node<Item>* link_field;
};

template<class Item>
class NodeIterator:public std::iterator<std::forward_iterator_tag, Item>{
	public:
		NodeIterator(Node<Item>* initial = NULL){
			current = initial;
		}
		Item& operator *() const{
			return current->data();
		}
		NodeIterator& operator ++(){
			current = current->link();
			return *this;
		}
		NodeIterator operator ++(int){
			NodeIterator cpy(current);
			current = current->link();
			return cpy;
		}
		bool operator ==(NodeIterator& other){
			return current == other.current;
		}
		bool operator !=(NodeIterator& other){
			return current != other.current;
		}

	private:
		Node<Item>* current;
};

template<class Item>
class Const_NodeIterator:public std::iterator<std::forward_iterator_tag, const Item>{
	public:
		Const_NodeIterator(const Node<Item>* initial = NULL){
			current = initial;
		}
		const Item& operator *() const{
			return current->data();
		}
		Const_NodeIterator& operator ++(){
			current = current->link();
			return *this;
		}
		Const_NodeIterator operator ++(int){
			Const_NodeIterator cpy(current);
			current = current->link();
			return cpy;
		}
		bool operator ==(Const_NodeIterator& other){
			return current == other.current;
		}
		bool operator !=(Const_NodeIterator& other){
			return current != other.current;
		}

	private:
		const Node<Item>* current;
};

template<class Item>
void list_count(Node<Item>* headPtr, Item entry)
{
    Node<Item>* cursor = headPtr;
    typename Node<Item>::size_type res = 0;
    while(cursor != NULL)
    {
        if(cursor->data() == entry)
            ++res;
        cursor = cursor->link();
    }
    return res;
}

template<class Item>
typename Node<Item>::size_type list_size(Node<Item>* headPtr)
{
    Node<Item>* cursor = headPtr;
    typename Node<Item>::size_type res = 0;
    while(cursor != NULL)
    {
        ++res;
        cursor = cursor->link();
    }
    return res;
}

template<class Item>
void list_head_insert(Node<Item>*& headPtr, Item entry)
{
        headPtr = new Node<Item>(entry, headPtr);
}

template<class Item>
void list_head_remove(Node<Item>*& headPtr){
	if(headPtr != NULL){
		Node<Item>* cursor = headPtr;
		headPtr = headPtr->link();
		delete cursor;
	}
}

template<class Item>
void list_remove(Node<Item>*& headPtr, Node<Item>* targetPtr)
{
    Node<Item>* cursor = headPtr;
    Node<Item>* pre_cursor = NULL;
    while(cursor != NULL)
    {
        if(cursor->data() == targetPtr->data())
        {
            if(pre_cursor == NULL)
            {
                headPtr->set_link(cursor->link());
            }
            else
            {
                pre_cursor->set_link(cursor->link());
            }
            delete cursor;
            break;
        }

        pre_cursor = cursor;
        cursor = cursor->link();
    }
}

template<class Item>
void list_zero_all(Node<Item>* headPtr){
    NodeIterator<Item> start(headPtr);
    NodeIterator<Item> end;
    while(start != end){
        *start = 0;
        ++start;
    }
}

template<class Item, class SizeType>
SizeType list_zero_count(const Node<Item>* headPtr){
    Const_NodeIterator<Item> it(headPtr);
    Const_NodeIterator<Item> end;
    SizeType ret = 0;
    while(it != end){
        if(*it == 0){
            ++ret;
        }
        ++it;
    }
    return ret;
}

template<class Item>
void list_traverse(Node<Item>* headPtr){
    NodeIterator<Item> it(headPtr);
    NodeIterator<Item> end;
    while(it != end){
        std::cout<<*it<<" ";
        ++it;
    }
}

template<class Item>
void list_clear(Node<Item>*& headPtr){
    Node<Item>* cursor = headPtr;
    Node<Item>* old;
    while(cursor != NULL){
        old = cursor;
        cursor = cursor->link();
        delete old;
    }
    headPtr = NULL;
}

template<class Item>
void sort_list(Node<Item>*& headPtr)
{
    Node<Item>* new_head = NULL;
    Node<Item>* cursor = headPtr;
    Node<Item>* biggest = cursor;
    while(cursor != NULL)
    {
        if(cursor->data() > biggest->data())
        {
            biggest = cursor;
        }
        cursor = cursor->link();
    }
}


};

#endif
