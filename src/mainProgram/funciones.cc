// main functions file
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "src/registeredUser/registered_user.h"
#include "src/extensionCourse/course.h"
#include "src/resources/resources.h"

void load_users_database(std::list<User> &users)
{
    std::ifstream file("users.txt");

    if (file.is_open())
    {

        std::string name, username, email, password, user_type;

        while (file >> name >> username >> email >> password >> user_type)
        {
            User user(name, username, email, password, user_type);
            users.push_back(user);
        }

        file.close();
    }
}

void save_users_database(std::list<User> users)
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

            file << name << std::endl
                 << username << " " << email << " " << password << " " << user_type << std::endl;
        }

        file.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}

void load_courses_database(std::list<Ext_Course> &courses, std::list<Student> students)
{
    std::ifstream file("courses.txt");

    if (file.is_open())
    {
        std::string name, description, asigned_coordinator, asigned_rcoordinator, fecha;
        Date start_date, end_date;
        bool availability;
        int available_places, max_places;
        Resources resources;
        getline(file, name);
        getline(file, description);
        getline(file, asigned_coordinator);
        getline(file, asigned_rcoordinator);
        getline(file, fecha);
        std::size_t pos1 = fecha.find(" ");
        std::size_t pos2 = fecha.find("/");
        std::size_t pos3 = fecha.find("/", pos2 + 1);

        start_date.day = std::stoi(fecha.substr(pos1 + 1, pos2 - 1));
        start_date.month = std::stoi(fecha.substr(pos2 + 1, pos3 - 1));
        start_date.year = std::stoi(fecha.substr(pos3 + 1));

        getline(file, fecha);
        std::size_t pos1 = fecha.find(" ");
        std::size_t pos2 = fecha.find("/");
        std::size_t pos3 = fecha.find("/", pos2 + 1);

        end_date.day = std::stoi(fecha.substr(pos1 + 1, pos2 - 1));
        end_date.month = std::stoi(fecha.substr(pos2 + 1, pos3 - 1));
        end_date.year = std::stoi(fecha.substr(pos3 + 1));

        getline(file, fecha);
        std::size_t pos = fecha.find(" ");
        std::string value = fecha.substr(pos + 1);
        if (value == "true")
        {
            availability = true;
        }
        else
        {
            availability = false;
        }

        getline(file, fecha);
        std::size_t pos = fecha.find(" ");
        available_places = std::stoi(fecha.substr(0, pos));
        max_places = std::stoi(fecha.substr(pos + 1));
        getline(file, fecha);
        std::size_t pos1 = fecha.find(" ");
        std::size_t pos2 = fecha.find(" ", pos1 + 1);
        resources.set_material(fecha.substr(0, pos1));
        resources.set_budget(std::stoi(fecha.substr(pos1 + 1, pos2 - 1)));
        resources.set_classroom(fecha.substr(pos2 + 1));

        Ext_Course course(name, description, asigned_coordinator, asigned_rcoordinator, start_date, end_date, availability, available_places, students, resources, max_places);
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }

    file.close();
}
}

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

void print_courses_list()
{

    std::
}
