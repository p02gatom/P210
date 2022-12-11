// registered_user.h
// A simple registered user class

#ifndef USER_H
#define USER_H

#include <string>


class User
{
private:
	std::string name_, username_, email_, password_, user_type_;

public:
	User(std::string name="empty",
			std::string username="empty",
			std::string email="empty",
			std::string password="empty",
			std::string user_type="empty");

inline std::string get_name() {return name_;}
inline std::string get_username() {return username_;}
inline std::string get_email() {return email_;}
inline std::string get_password() {return password_;}
inline std::string get_user_type() {return user_type_;}

inline void set_name(std::string name) {name_=name;}
inline void set_username(std::string username) {username_=username;}
inline void set_email(std::string email) {email_=email;}
inline void set_password(std::string password) {password_=password;}
inline void set_user_type(std::string user_type) {user_type_=user_type;}

};

#endif
