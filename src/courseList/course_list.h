// course_list.h
// A simple course_list class

#ifndef COURSE_LIST_H
#define COURSE_LIST_H

#include <string>
#include "src/extensionCourse/course.h"
#include <list>



class Course_list
{
	private:

		std::list<Ext_Course> course_list;
		int total_course_count;
		
	public:

		bool add_course(const Ext_Course& course);
		bool delete_course(const Ext_Course& course);

		void print_full_list(); // imprime por pantalla la lista de cursos, incluyendo toda la info de los mismos (nombre, plazas, descripcion, profesores ...)
		bool print_course(std::string course_name); // imprime por pantalla la info de un curso especifico (buscará el curso con el nombre especificado, devuelve false si no lo encuentra)
		
		bool list_to_file(); // imprimirá toda la lista en el fichero
		bool file_to_list(); // introducirá toda la info del fichero en la lista (quizas se pueda hacer en el constructor)
};

#endif // COURSE_LIST_H