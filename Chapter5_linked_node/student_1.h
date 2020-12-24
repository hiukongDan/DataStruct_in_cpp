#ifndef _HIUKONG_DAN_STUDENT_1_H
#define _HIUKONG_DAN_STUDENT_1_H

#include "course_1.h"

class Student{
	private:
		CourseNode* headPtr;
	public:
		Student();
		
		void set_course_score(std::string course_name, int course_score);
		
		// print scores including GPA
		void print();
};

#endif  // _HIUKONG_DAN_STUDENT_1_H
