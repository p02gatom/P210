//main header file
#ifndef MAIN_H
#define MAIN_H

#include <list>
#include "registered_user.h"

void load_users_database(std::list<User> &users);
User log_in(std::list<User> users);
User sign_up(std::list<User> &users);

#endif 