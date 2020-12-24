#include "course_1.h"

/*
// ============================================================= \\
||                            Course                             ||
\\ ============================================================= //
*/

Course::Course(){
	
}

Course::Course(std::string course_name, int course_score){
	this->course_name = course_name;
	this->course_score = course_score;
}

void Course::set_course_name(std::string course_name){
	this->course_name = course_name;
}

void Course::set_course_score(int course_score){
	this->course_score = course_score;
}

bool Course::operator ==(const Course other){
	return this->course_name == other.course_name;
}



/*
// ============================================================= \\
||                         CourseNode                            ||
\\ ============================================================= //
*/

CourseNode::CourseNode(){
	
}

CourseNode::CourseNode(Course course, CourseNode* link){
	this->data_field = course;
	this->link_field = link;
}

Course& CourseNode::data(){
	return data_field;
}

const Course& CourseNode::data() const{
	return data_field;
}

CourseNode*& CourseNode::link(){
	return link_field;
}

const CourseNode* CourseNode::link() const{
	return link_field;
} 
