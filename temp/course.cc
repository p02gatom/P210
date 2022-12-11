//course.cc
// Definición de Course en el fichero.cc

#include "course.h"

#include <string>


Course::Course(std::string name, std::string description, std::string asigned_coordinator, 
	std::string asigned_rcoordinator, std::struct Date start_date, std::struct Date end_date,
	int students, bool availability, int available_places, int max_places){
	name_=name;
	description_=description;
	asigned_coordinator_=asigned_coordinator;
	asigned_rcoordinator_=asigned_rcoordinator;
	start_date_=start_date;
	end_date_=end_date;
	students_=students;
	availability_=availability;
	available_places_=available_places;
	max_places_=max_places;
	if(max_places > available_places) availability_=availability;
	else availability_= false;
}	

bool Course::set_available_places(bool availability, int max_places, int available_places){
	if (max_places > available_places){
		availability_=availability;
		return true;
	}
	else {
		return false;
	}
}




