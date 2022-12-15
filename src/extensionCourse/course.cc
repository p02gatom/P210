//course.cc
// Definición de Course en el fichero.cc

#include "course.h"
#include <string>


Course::Course(std::string name, std::string description, std::string asigned_coordinator, 
			std::string asigned_rcoordinator, Date start_date, Date end_date,
			int max_places, int students, bool availability, int available_places)
{
	name_=name;
	description_=description;
	asigned_coordinator_=asigned_coordinator;
	asigned_rcoordinator_=asigned_rcoordinator;

	start_date_.day=start_date.day;
	start_date_.month=start_date.month;
	start_date_.year=start_date.year;
	end_date_.day=end_date.day;
	end_date_.month=end_date.month;
	end_date_.year=end_date.year;
//pendiente
	max_places_=max_places;
	students_=students;
	availability_=availability;
	available_places_=available_places;
	

	if(max_places > available_places) availability_=availability;
	else availability_= false;
}	

bool Course::set_available_places(bool availability, int max_places, int available_places)
{
	if (max_places > available_places)
	{
		availability_=availability;
		return true;
	}
	else {
		return false;
	}
}




