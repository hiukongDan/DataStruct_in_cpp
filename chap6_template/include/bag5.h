#ifndef HIUKONG_DAN_BAG_5_H
#define HIUKONG_DAN_BAG_5_H

#include "node_2.h"

namespace hiukong_dan{

template<class Item>
class Bag{
    public:
        typedef std::size_t size_type;
        typedef Item value_type;
        typedef NodeIterator<Item> iterator;
        typedef Const_NodeIterator<Item> const_iterator;

        // CONSTRUCTORS AND DESTRUCTORS
        Bag(){
            headPtr = NULL;
            bag_size = 0;
        }

        Bag(const Bag& source){
            headPtr = NULL;
            bag_size = source.bag_size;
            iterator end_it = source.end();
            for(iterator it = source.begin(); it != end_it; ++it){
                insert(*it);
            }
        }

        ~Bag(){
            list_clear(headPtr);
        }

        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(Item target){
            size_type ret = 0;
            Node<Item>* cursor = headPtr;
            Node<Item>* precursor = NULL;
            while(cursor != NULL){
                if(cursor.data() == target){
                    if(precursor == NULL){
                        precursor = cursor;
                        headPtr = cursor;
                        cursor = cursor->link();
                        delete precursor;
                        precursor = NULL;
                        ++ret;
                    }
                    else{
                        precursor->set_link(cursor->link());
                        delete cursor;
                        cursor = precursor->link();
                        ++ret;
                    }
                }
                else{
                    precursor = cursor;
                    cursor = cursor->link();
                }
            }
            bag_size -= ret;
            return ret;
        }

        void erase_one(Item target){
            Node<Item>* cursor = headPtr;
            Node<Item>* precursor = NULL;
            while(cursor != NULL){
                if(cursor.data() == target){
                    if(precursor == NULL){
                        precursor = cursor;
                        headPtr = cursor;
                        cursor = cursor->link();
                        delete precursor;
                    }
                    else{
                        precursor->set_link(cursor->link());
                        delete cursor;
                    }
                    --bag_size;
                    break;
                }
                else{
                    precursor = cursor;
                    cursor = cursor->link();
                }
            }
        }

        void insert(Item target){
            list_head_insert(headPtr, target);
            ++bag_size;
        }

        void operator +=(const Bag& other){
            bag_size += other.bag_size;
            iterator end_it = other.end();
            for(iterator it = other.begin(); it != end_it; ++it){
                insert(*it);
            }
        }

        void operator =(const Bag& source){
            list_clear(headPtr);
            headPtr = NULL;
            bag_size = source.bag_size;
            iterator end_it = end();
            for(iterator it = source.begin(); it != end_it; ++it){
                insert(*it);
            }
        }

        // CONST MEMBER FUNCTIOS
        size_type count(Item target) const{
            size_type ret = 0;
            iterator end_it = end();
            for(iterator it = begin(); it != end_it; ++it){
                if(*it == target)
                    ++ret;
            }
            return ret;
        }

        Item grab() const{
            size_type index = rand() % size();
            const_iterator it = begin();
            for(size_type i = 0; i < index; ++i){
                ++it;
            }
            return *it;
        }
        size_type size() const {return bag_size;}

        // ITERATOR FUNCTIONS
        iterator begin(){return iterator(headPtr);}
        const_iterator begin() const{return const_iterator(headPtr);}
        iterator end(){return iterator();}
        const_iterator end() const{return const_iterator();}

    private:
        Node<Item>* headPtr;
        size_type bag_size;

}; // class Bag

}; // namespace hiukong_dan

#endif // HIUKONG_DAN_BAG_5_H
