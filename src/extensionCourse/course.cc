//course.cc
// Definición de Ext_Course en el fichero.cc

#include "src/extensionCourse/course.h"
#include "src/student/student.h"
#include <string>


Ext_Course Course(std::string name, std::string description, std::string asigned_coordinator, 
			std::string asigned_rcoordinator, Date start_date, Date end_date,
			int max_places, std::list<Student> students, bool availability, int available_places)
{
	/* name_=name;
	description_=description;
	asigned_coordinator_=asigned_coordinator;
	asigned_rcoordinator_=asigned_rcoordinator;

	start_date_.day=start_date.day;
	start_date_.month=start_date.month;
	start_date_.year=start_date.year;
	end_date_.day=end_date.day;
	end_date_.month=end_date.month;
	end_date_.year=end_date.year;
//pendiente
	max_places_=max_places;
	students_=students;
	availability_=availability;
	available_places_=available_places; */
	

	if(max_places > available_places) availability_=true;
	
}	

int Ext_Course::set_available_places(int max_places, int available_places)
{
	if (max_places > available_places)
	{
		available_places_=available_places;
	}
	else {
		std::cout<<"Error: No puede superar el aforo"<<std::endl;
	}
}

bool Ext_course::add_student(std::string mail)
{
	if(availability_ == false) // si el curso no esta disponible
	{
		std::cout << "El curso seleccionado esta completo, prueba a elegir otros" << std::endl;
		return false;
	} 
	else 
	{
		for(auto it=student_list.begin(); it!=student_list.end(); it++)
			if (it->get_email() == mail) // el usuario ya se encuentra inscrito en el curso
			{
				std::cout << "Ya estás inscrito en este curso." << std::endl;
				return false;
			} 
		
		else {
			student_list_.push_back(student); // paso el objeto student
		}
		if(student_vector_.size() == max_places_) set
	}
}

bool Ext_course::delete_student(std::string student)
{
	if(student_vector_.size() >= max_places_) return false;
	else
	{
		for(int i = 0; student_vector_.size(); i++)
		{
			if (student_vector_[i] == student) return false;
			else
			{ student_vector_.erase(student_vector_.begin() + i); }
		} 
	}
	return true;
}

void fichero_a_lista_students_curso()
{

	std::ifstream file(get_name() + "_lista.txt");

	if (file.is_open()) 
	{
		std::string name, email; 

		while (getline(file, name)) 
		{
			getline(file, email);
			Student student(name, " ", email);
			student_list_.push_back(student);
		}
		file.close();
	} else {

		std::cout<<"Error en la apertura del fichero";

	}
}



