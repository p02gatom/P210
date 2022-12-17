#include "src/admin/admin.h"
#include "src/extensionCourse/course.h"
#include "src/registeredUser/registered_user.h"
#include "src/resources/resources.h"
#include "src/student/student.h"
#include "src/mainProgram/funciones.h"

#include <iostream>
#include <string>
#include <fstream>
#include <list>

int main()
{
	std::list<User> users;
	load_users_database(users);
	std::cout << "Bienvenido a la plataforma de Cursos de Extensión de la UCO" << std::endl;
	std::cout << "Introduzca 1 para INICIAR SESION con su cuenta en el sistema" << std::endl;
	std::cout << "Introduzca 2 para REGISTRARSE si no dispone de cuenta en el sistema" << std::endl;
	std::cout << "Introduzca 3 para ACCEDER COMO INVITADO" << std::endl;
	std::cout << "Introduzca 4 si desea SALIR" << std::endl;
	int option;

	while (1)
	{

		std::cin >> option;

		switch (option)
		{
		case 1: // INICIAR SESION

			log_in(users);

		break;

		case 2: // REGISTRARTE

			sign_up(users);

		break;

		case 3: // ACCESO COMO INVITADO

			std::cout << "Bienvenido.\nHa accedido usted como invitado." << std::endl;
			std::cout << "Escriba 1 para ver todos los cursos disponibles en la plataforma" << std::endl;



		break;

		case 4: // SALIR

			std::cout << "Gracias por su atención." << std::endl;

			return 0;

		break;

		default:
			std::cout << "Elección no válida.\nInténtelo de nuevo:" << std::endl;
		}
	}