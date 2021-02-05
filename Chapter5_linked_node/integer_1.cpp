#include "integer_1.h"
#include <string>
namespace hiukong_dan{

Integer::Integer(){
	headPtr = NULL;
}

Integer::Integer(const Integer& other){
	headPtr = NULL;
	Node* cursor = other.headPtr;
	while(cursor != NULL){
		node_insert_tail(headPtr, cursor->data());
		cursor = cursor->link();
	}
}

// Postcondition: store digits in little endian order
Integer::Integer(std::string digits){
	headPtr = NULL;
	size_type size = digits.size();
	size_type zeroToInsert = size%3;
	zeroToInsert = zeroToInsert==0?0:3-zeroToInsert;
	size += zeroToInsert;
	for(size_type i = 0; i < zeroToInsert; ++i){
		digits.insert(0, "0");
	}

	for(int i = size-1; i >= 2; i -= 3){
		value_type tmpSum = 0;
		tmpSum += digits.at(i) - '0';
		tmpSum += (digits.at(i-1) - '0') * 10;
		tmpSum += (digits.at(i-2) - '0') * 100;
		node_insert_tail(headPtr, tmpSum);
	}
}

Integer Integer::operator +(const Integer& other){
	Integer res(*this);
	res += other;
	return res;
}

void Integer::operator +=(const Integer& other){
	Node* head_ret = NULL;
	Node* cursor_0 = this->headPtr;
	Node* cursor_1 = other.headPtr;
	
	value_type carry = 0;
	value_type res = 0;
	while(cursor_0 != NULL && cursor_1 != NULL){
		res = cursor_0->data() + cursor_1->data() + carry;
		carry = res/1000;
		res %= 1000;
		node_insert_tail(head_ret, res);
		
		cursor_0 = cursor_0->link();
		cursor_1 = cursor_1->link();
	}
	Node* cursor = NULL;
	if(cursor_0 != NULL){
		cursor = cursor_0;
	}
	else if(cursor_1 != NULL){
		cursor = cursor_1;
	}
	
	if(cursor != NULL){
		while(cursor != NULL){
			res = cursor->data() + carry;
			carry = res/1000;
			res %= 1000;
			node_insert_tail(head_ret, res);
			cursor = cursor->link();
		}
	}
	
	if(carry == 1){
		node_insert_tail(head_ret, 1);
	}
	node_clear(this->headPtr);
	this->headPtr = head_ret;
}

Integer Integer::operator -(const Integer& other){
	Integer ret(*this);
	ret -= other;
	return ret;
}

// Precondition: Assume the first operand is bigger than the second one.
void Integer::operator -=(const Integer& other){
	Node* head_ret = NULL;
	Node* cursor_0 = this->headPtr;
	Node* cursor_1 = other.headPtr;
	
	value_type carry = 0;
	value_type res = 0;
	while(cursor_0 != NULL && cursor_1 != NULL){
		res = cursor_0->data() + 1000 - carry - cursor_1->data();
		carry = 1 - res / 1000;
		res %= 1000;
		node_insert_tail(head_ret, res);
		cursor_0 = cursor_0->link();
		cursor_1 = cursor_1->link();
	}
	
	while(cursor_0 != NULL){
		res = cursor_0->data() + 1000 - carry;
		carry = 1 - res / 1000;
		res %= 1000;
		node_insert_tail(head_ret, res);
		cursor_0 = cursor_0->link();
	}
	node_clear(headPtr);
	headPtr = head_ret;
}

/*
Integer Integer::operator *(const Integer& other){
	
}

void Integer::operator *=(const Integer& other){
	
}


Integer Integer::operator /(const Integer& other){
	
}
void Integer::operator /=(const Integer& other){
	
}

void Integer::operator %(const Integer& other){
	
}

void Integer::operator %=(const Integer& other){
	
}
*/

std::string Integer::to_string(){
	std::string ret = "";
	Node* cursor = headPtr;
	while(cursor != NULL){
		value_type tmp = cursor->data();
		
		std::string strTmp = "";
		strTmp.push_back(tmp/100 + '0');
		tmp = tmp%100;
		strTmp.push_back(tmp/10 + '0');
		tmp = tmp%10;
		strTmp.push_back(tmp + '0');
		
		ret = strTmp + ret;
		
		cursor = cursor->link();
	}
	
	for(int i = 0; i < 3; i++){
		if(ret.at(0) == '0'){
			ret.erase(0, 1);
		}
		else{
			break;
		}
	}
	
	return ret;
}
};

