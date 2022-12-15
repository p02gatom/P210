#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "registered_user.h"

void lista_users_a_fichero(std::list<User> users)
{
	std::ofstream file("users.txt");

	if (file.is_open())
	{
		std::string name, username, email, password, user_type;

		std::list<User>::iterator it;
    	for (it = users.begin(); it != users.end(); ++it) 
		{	
			name = it->get_name();
			username = it->get_username();
			email = it->get_email();
			password = it->get_password();
			user_type = it->get_user_type();

			file << name << " " << username << " " << email << " " << password << " " << user_type << std::endl;
		}

		file.close();

	} else 
	{
        std::cout << "Unable to open file" << std::endl;
    }
}