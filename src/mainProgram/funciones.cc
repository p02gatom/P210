// main functions file
#include <iostream>
#include <string>
#include <list>
#include "registeredUser/registered_user.h"

User log_in(std::list<User> users)
{
    std::string username, password;
    std::list<User>::iterator it;
    while (1)
    {
        std::cout << "Introduzca su usuario o teclee E para salir:" << std::endl;
        std::cin >> username;

        if (username == "E" || username == "e")
        {
            return User("Guest", "Guest", "", "", "guest");
        }

        std::cout << "Introduzca su contraseña:" << std::endl;
        std::cin >> password;

        for (it = users.begin(); it != users.end(); ++it)
        {
            if ((it->get_username() == username) && (it->get_password() == password))
            {
                std::cout << "Bienvenido de nuevo, " << it->get_name() << std::endl;
                return User(it->get_name(), it->get_username(), it->get_email(), it->get_password(), it->get_user_type());
            }
        }

        std::cout << "Credenciales erróneas, inténtelo de nuevo" << std::endl;
        std::cout << "Introduzca E para salir" << std::endl;
    }
}

void sign_up(std::list<User> &users)
{
    std::string name = "", username = "", email = "", password = "", user_type = "";
    while (name == "")
    {
        std::cout << "Introduzca su nombre y apellidos" << std::endl;
        std::cin >> name;
        if (name == "")
        {
            std::cout << "Error: No puede dejar su nombre en blanco" << std::endl;
        }
    }

    std::cout << "Introduzca su correo corporativo del dominio uco.es" << std::endl;
    std::cin >> email;
    int pos = email.find('@');
    if (email.substr(pos) != "@uco.es")
    {
        std::cout << "Error: No ha introducido una dirección de correo válida." << std::endl;
    }
    else
    {
        username = email.substr(0, pos);
    }

    while (username == "")
    {
        std::cout << "Introduzca su correo corporativo del dominio uco.es" << std::endl;
        std::cin >> email;

        pos = email.find('@');

        if (email.substr(pos) != "@uco.es")
        {
            std::cout << "Error: No ha introducido una dirección de correo válida." << std::endl;
        }
        else
        {
            username = email.substr(0, pos);
        }
    }

    std::cout << "Por favor, introduzca una contraseña.\n Debe tener al menos una mayúscula, una minúscula y un número: " << std::endl;
    bool accepted = false;

    while (accepted == false)
    {
        bool hasUpper = false;
        bool hasLower = false;
        bool hasNum = false;
        std::getline(std::cin, password);
        for (int i = 0; i < password.length(); i++)
        {
            if (isupper(password[i]))
            {
                hasUpper = true;
            }
            if (islower(password[i]))
            {
                hasLower = true;
            }
            if (isdigit(password[i]))
            {
                hasNum = true;
            }
        }
        if (hasUpper && hasLower && hasNum)
        {
            accepted = true;
            std::cout << "Contraseña aceptada." << std::endl;
        }
        else
        {
            std::cout << "Error: La contraseña debe contener al menos una mayúscula, una minúscula y un número" << std::endl;
        }
    }
    accepted = false;
    int n;

    while (accepted == false)
    {
        std::cout << "Introduzca 1 si es alumno de la UCO, 2 si es coordinador de cursos o 3 si es coordinador de recursos:" << std::endl;
        std::cin >> n;

        switch (n)
        {

        case 1:
            accepted = true;
            user_type = "student";
            break;

        case 2:
            accepted = true;
            user_type = "coodinator";
            break;

        case 3:
            accepted = true;
            user_type = "rcoordinator";
            break;

        default:
            std::cout << "Error: No ha escogido una opción válida" << std::endl;
            
        }
    }
    User user(name, username, email, password, user_type);
    users.push_back(user);
    std::cout << "Enhorabuena, acaba usted de registrarse exitosamente." << std::endl;
}
