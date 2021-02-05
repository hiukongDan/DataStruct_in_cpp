#include <iostream>
#include "include/node_2.h"
#include "include/bag5.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace hiukong_dan;

template<class Item, class size_type>
size_type count_less_than(const Bag<Item>& bag, Item target){
    Const_NodeIterator<Item> it = bag.begin();
    Const_NodeIterator<Item> end_it = bag.end();
    size_type ret = 0;
    while(it != end_it){
        if(*it < target)
            ++ret;
        ++it;
    }
    return ret;
}

int main(int argc, char** argv) {
	/*
	Bag<int> bag;
	bag.insert(5);
	bag.insert(9);
    bag.insert(10);
    bag.insert(59);
    std::cout<<count_less_than<int, std::size_t>(bag, 60)<<std::endl;

    */

    Node<int>* headPtr = NULL;
    list_head_insert(headPtr, 1);
    list_head_insert(headPtr, 2);
    list_head_insert(headPtr, 3);



    Node<int>* cursor = headPtr;
    list_remove(headPtr, cursor);

    //list_traverse(headPtr);

	return 0;
}
