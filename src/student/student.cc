//student.cc
//functions no inline of student.h

#include <string>
#include <list>
#include "student.h"
#include "registered_user.h"

bool Student::singup_course(std::string c1, std::list <Ext_Course> course_list){

    for(auto it=course_list.begin();it!=course_list.end();it++){

        if(it->course_list==c1){

            if(it->get_availability()==true){
                
                it->add_student(get_mail());
            }

            std::cout<<"Se ha inscrito con exito al curso."<<"\n";
            return true;
        }

        else{
        
            std::cout<<"No se pudo inscribir en el curso"<<"\n";
            return false;
        }

    }

}

void Student::modify_student(Student s){

    std::string nuevo;
    int n;
    std::cin>>n;
    std::cout<<"1 para modificar nombre"<<"\n"<<"2 para modificar username"<<"\n"<<"3 para modificar email"<<"\n"<<"4 para modificar password"<<"\n";

    while(true){

        switch(n){

            case 1:

                std::cout<<"name: "<<"\n";
                std::cin>>nuevo;
                s.set_name(nuevo);

            break;

            case 2:

                std::cout<<"username: "<<"\n";
                std::cin>>nuevo;
                s.set_username(nuevo);

            break;

            case 3:

                std::cout<<"email: "<<"\n";
                std::cin>>nuevo;
                s.set_email(nuevo);

            break;

            case 4:

                std::cout<<"password: "<<"\n";
                std::cin>>nuevo;
                s.set_password(nuevo);

            break;

        }
        
    }

}       

void Student::delete_student(Student s){

    for(auto it=course_list.begin();it!=course_list.end();it++){

        for(auto it2=students_list_.begin();it2!=students_list_.end();it2++){

            if(s==it->get_student()){

                students_list_.erase(it2);                
            }

        }

    }

    delete s;
}

std::list <Ext_Course> Student::get_course_list(){


}
