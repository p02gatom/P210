#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "registered_user.h"


std::list<User> fichero_a_lista_users()
{

	std::list<User> users;

	std::ifstream file("users.txt");

	if (file.is_open()) 
	{
		std::string name, username, email, password, user_type; // variables para almacenar temporalmente los atributos de los objetos tipo User

		while (file >> name >> username >> email >> password >> user_type) 
		{
			User user(name, username, email, password, user_type);
			users.push_back(user);

		}

		file.close();
	}

	return users;
}
