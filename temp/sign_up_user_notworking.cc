#include <iostream>
#include <fstream>
#include <string>
#include "registered_user.h"

int main() {
	User user("Juan", "Juan123", "juan@example.com", "123456", "user");

	std::ofstream myfile;
	myfile.open("user_data.txt");
	myfile << "Name: " << user.get_name() << "\n";
	myfile << "Email: " << user.get_email() << "\n";
	myfile << "Username: " << user.get_username() << "\n";
	myfile << "Password: " << user.get_password() << "\n";
	myfile << "User Type: " << user.get_user_type() << "\n";
	myfile.close();

	std::cout << "Data written to file successfully" << std::endl;

	return 0;
}