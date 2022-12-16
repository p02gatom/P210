//main header file
#ifndef MAIN_H
#define MAIN_H

#include <list>
#include "registered_user.h"

User log_in(std::list<User> users);
User sign_up(std::list<User> &users);

#endif 