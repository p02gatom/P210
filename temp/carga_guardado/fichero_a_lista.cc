#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "registered_user.h"

int main() {
	
	// Create a list container and insert class objects via txt file

	std::list<User> users;

	std::ifstream file("users.txt");

	if (file.is_open()) {

		std::string name, username, email, password, user_type;

		while (file >> name >> username >> email >> password >> user_type) {

			User user(name, username, email, password, user_type);
			users.push_back(user);

		}

		file.close();

	}

    // Iterate through list and print student info

    std::list<User>::iterator it;
    for (it = users.begin(); it != users.end(); ++it) {

        std::cout << "Name: " << it->get_name() << " Username: " << it->get_username() <<" Email: " << it->get_email() <<" Password: " << it->get_password() <<" User type: " << it->get_user_type() << std::endl;

	}

	return 0;

}