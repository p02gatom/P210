// Ext_Course.h
// A simple Ext_Course class

#ifndef EXTCOURSE_H
#define EXTCOURSE_H

#include <string>
#include <vector>
#include <iostream>
#include "resources.h"

struct Date { 
    int day;
    int month;
    int year;
};

class Ext_Course
{
	private:

		std::string name_, description_, asigned_coordinator_, asigned_rcoordinator_;
		Date start_date_, end_date_;
		int available_places_, max_places_;
		std::vector <std::string> students_vector_; // vector con el mail de los estudiantes (podriamos establecer de primeras el tmñ = max_places_)
		bool availability_;
		Resources resources_; // recursos asignados para cada objeto curso creado

	public:

		Ext_Course(std::string name="empty",
					std::string description="empty",
					std::string asigned_coordinator="empty",
					std::string asigned_rcoordinator="empty",
					Date start_date,
					Date end_date,	
					bool availability = true,
					int available_places = 0,
					int max_places = 0);

	//getters
		inline std::string get_name() {return name_;}
		inline std::string get_description() {return description_;}
		inline std::string get_asigned_coordinator() {return asigned_coordinator_;}
		inline std::string get_asigned_rcoordinator() {return asigned_rcoordinator_;}
		inline struct Date get_start_date() {return start_date_;}
		inline struct Date get_end_date() {return end_date_;}
		inline int get_students() {return students_;}
		inline bool get_availability() {return availability_;}
		inline int get_available_places() {return available_places_;}
		inline int get_max_places() {return max_places_;}
				// de la clase Resources
		inline std::string get_material(){ return resources_.get_material(); }
		inline std::string get_classroom(){ return resources_.get_classroom(); }
		inline float get_budget(){ return resources_.get_budget(); }
		inline std::string get_full_resources(){ return resources_.get_full_resources(); }


	//setters
		inline void set_name(std::string name) {name_=name;}
		inline void set_description(std::string description) {description_=description;}
		inline void set_asigned_coordinator(std::string asigned_coordinator) {asigned_coordinator_=asigned_coordinator;}
		inline void set_start_date(struct Date start_date) {start_date_=start_date;}
		inline void set_end_date(struct Date end_date) {end_date_=end_date;}
		inline void set_students(int students) {students_=students;}
		bool set_available_places(bool availability, int max_places, int available_places);
		inline void set_available_places(int available_places) {available_places_=available_places;}
		inline void set_max_places(int max_places) {max_places_=max_places;}
				// de la clase Resources
		inline void set_material(std::string material){ resources_.set_material(material); }
		inline void set_budget(float budget){ resources_.set_budget(budget); }
		inline void set_classroom(std::string classroom){ resources_.set_classroom(classroom); }

		bool add_student(std::string student);
		void delete_student(std::string student);

		

};

#endif