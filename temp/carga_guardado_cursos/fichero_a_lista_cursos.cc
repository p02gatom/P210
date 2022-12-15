#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "course.h"


std::list<Ext_Course> fichero_a_lista_cursos()
{

	std::list<Ext_Course> cursos;

	std::ifstream file("users.txt");

	if (file.is_open()) 
	{
		std::string name, description, asigned_coordinator, asigned_rcoordinator, user_type; 

		while (file >> name >> username >> email >> password >> user_type) 
		{
			User user(name, username, email, password, user_type);
			users.push_back(user);

		}

		file.close();
	}

	return cursos;
}
