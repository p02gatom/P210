//student.h
// A simple student class

#ifndef STUDENT_H
#define STUDENT_H

#include "registered_user.h"
#include "course.h"
#include <string>
#include <list>

class Student : public Registered_user{

	private:

	public:

		Student(

			std::string name="empty",
			std::string username="empty",
			std::string email="empty",
			std::string password="empty",				
			std::string user_type="empty"):Registered_user(name, username, email, password, user_type);

	bool singup_course(std::string c1, std::list <Ext_Course> course_list);
	void modify_student(Student s);
	bool delete_student(Student s);
	std::list <Ext_Course> get_course_list();
	std::list <Ext_Course> get_mycourses();
	

};

#endif // STUDENT_H
