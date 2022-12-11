//registered_user.cc
// Definición de User en el fichero.cc

#include "registered_user.h"

#include <string>


User::User(std::string name, std::string username, std::string email, std::string password, std::string user_type){
	name_=name;
	username_=username;
	email_=email;
	password_=password;
	user_type_=user_type;
}