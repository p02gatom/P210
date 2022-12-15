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
		inline void set_material(std::string material){ material_ = material;}
		inline void set_budget(float budget){ budget_ = budget;}
		inline void set_classroom(std::string classroom){ classroom_ = classroom;}

		//getters
		inline std::string get_material() const { return material_;}
		inline float get_budget() const { return budget_;}
		inline std::string get_classroom() const { return classroom_;}
		inline std::string get_full_resources(){ return material_ + "\n" + budget_ + "\n" + classroom_ ; } // concatenacion de todos los recursos
}

#endif // RESOURCES_H