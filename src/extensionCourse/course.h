// Ext_Course.h
// A simple Ext_Course class

#ifndef EXTCOURSE_H
#define EXTCOURSE_H

#include <string>

struct Date { // creo que podriamos usar una libreria propia para date
    int day;
    int month;
    int year;
};

class Ext_Course
{
	private:

		std::string name_, description_, asigned_coordinator_, asigned_rcoordinator_;
		struct Date start_date_, end_date_; 
		int students_, available_places_, max_places_;
		bool availability_;

	public:

		Ext_Course(std::string name="empty",
					std::string description="empty",
					std::string asigned_coordinator="empty",
					std::string asigned_rcoordinator="empty",
					struct Date start_date,
					struct Date end_date,
					int students = 0,
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

};

#endif