#ifndef _HIUKONG_DAN_DIGITS_1_H
#define _HIUKONG_DAN_INTEGER_1_H

#include "node_1.h"
#include <string>
namespace hiukong_dan{
class Integer{
	public:
		typedef Node::value_type value_type;
		typedef size_t size_type;
		
		Integer();
		Integer(const Integer&);
		Integer(std::string );
		Integer operator +(const Integer& other);
		void operator +=(const Integer& other);
		Integer operator -(const Integer& other);
		void operator -=(const Integer& other);
		//Integer operator *(const Integer& other);
		//void operator *=(const Integer& other);
		//Integer operator /(const Integer& other);
		//void operator /=(const Integer& other);
		//void operator %(const Integer& other);
		//void operator %=(const Integer& other);
		std::string to_string();
		
	private:
		Node* headPtr;
};
};
#endif
