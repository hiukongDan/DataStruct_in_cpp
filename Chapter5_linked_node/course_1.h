#ifndef _HIUKONG_DAN_COURSE_1_H
#define _HIUKONG_DAN_COURSE_1_H

#include <string>

class Course{
	private:
		std::string course_name;
		int course_score;
	public:
		Course();
		Course(std::string course_name, int course_score);
		
		void set_course_score(int course_score);
		void set_course_name(std::string course_name);
		
		bool operator ==(const Course other);
};

class CourseNode{
	private:
		Course data_field;
		CourseNode* link_field;
	public:
		CourseNode();
		CourseNode(Course course, CourseNode* link);
		
		const CourseNode* link() const;
		CourseNode*& link();
		const Course& data() const;
		Course& data();
};

#endif
