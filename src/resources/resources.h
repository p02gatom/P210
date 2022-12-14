//resources.h
// A simple resources class

#ifndef RESOURCES_H
#define RESOURCES_H


#include <string>

class Resources :
{
	private:

		std::string material_;
		float budget_;
		std::string classroom_;

	public:

		// constructor

		//setters
		void set_material(std::string material){ material_ = material;}
		void set_budget(float budget){ budget_ = budget;}
		void set_classroom(std::string classroom_){ classroom_ = classroom;}

		//getters
		std::string get_material() const { return material_;}
		float get_budget() const { return budget_;}
		std::string get_classroom() const { return classroom_;}
		std::string get_full_resources(){ return material_ + "\n" + budget_ + "\n" + classroom_ ; }
}

#endif // RESOURCES_H