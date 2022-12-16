// registered_user.cc
//  Definición de User en el fichero.cc

#include "registered_user.h"
#include <string>
#include <list>
#include <iostream>

/* User::User(std::string name, std::string username, std::string email, std::string password, std::string user_type)
{
	name_=name;
	username_=username;
	email_=email;
	password_=password;
	user_type_=user_type;
} */

std::string log_in(std::list<User> users)
{
	std::string username, password;
	std::list<User>::iterator it;
	while (1)
	{
		std::cout << "Introduzca su usuario o teclee E para salir:" << std::endl;
		std::cin >> username;

		if (username == "E" || username == "e")
		{
			return "guest";
		}

		std::cout << "Introduzca su contraseña:" << std::endl;
		std::cin >> password;

		for (it = users.begin(); it != users.end(); ++it)
		{
			if ((it->get_username() == username) && (it->get_password() == password))
			{
				std::cout << "Bienvenido de nuevo, " << it->get_name() << std::endl;
				return it->get_user_type();
			}
		}

		std::cout << "Credenciales erróneas, inténtelo de nuevo" << std::endl;
		std::cout << "Introduzca E para salir" << std::endl;
	}
}