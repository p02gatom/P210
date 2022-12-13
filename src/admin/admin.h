//admin.h
// A simple admin class

#ifndef ADMIN_H
#define ADMIN_H

#include "registered_user.h"
#include <string>

class Admin : public registered_user
{
	private:

	public:

		Admin();	// constructor

		bool delete_account();
		bool create_account();
		void validate_account();
		void modify_account();
}

#endif // ADMIN_H