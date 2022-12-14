#include"course.h"
.
.
.
#include "student.h"

#include<iostream>
#include<string>

int main()
{
	std::cout << "Introduce 1 para INICIAR SESION con tu cuenta en el sistema." << std::endl;
	std::cout << "Introduce 2 si no dispones de cuenta para REGISTRARTE en el sistema." << std::endl;
	std::cout << "Introduce 3 si deseas SALIR"
	int option;
	cin >> option;

	switch(option)
	{
		case 1: // INICIAR SESION

		if( inicio_sesion() )
		{
			if() // si userType
		}
		break;
		case 2: // REGISTRARTE


		break;
		case 3: // SALIR


		break;
		defeult:
	}
}