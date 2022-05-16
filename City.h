//
// Created by HP-WIN10 on 30/12/2021.
//

#ifndef CITY_H
#define CITY_H
#include "Employee.h"
#include "Manager.h"
#include "Citizen.h"
#include "Workplace.h"
#include "Faculty.h"
#include "exceptions.h"
#include <string>
#include <list>
#include <iterator>

namespace mtm {



    class City {
    private:
        std::string CityName;
        std::list<Employee*> Employees;
        std::list<Employee*> :: iterator Employee_it,Employee_it_helper;
        std::list<Manager*> Mangers;
        std::list<Manager*> :: iterator Manger_it;
        std::list<Workplace> work;
        std::list<Workplace> :: iterator work_it;
        std::list<Citizen*> Citizens;
        std::list<Citizen*> ::iterator Citizens_it;
        std::list<Faculty<Condition>> Faculties;
        std::list<Faculty<Condition>> :: iterator it_Faculties;



    public:
/*
the constructor
*/
        explicit City(const std::string &cityName);
        City()=default;
/* 
 the function which we add by it the employee to the wanted city
 the function recieve employee id and his first and last name and his birth year
 if the employee already exists the function will return the exeption CitizenAlreadyExists
*/    
        void addEmployee(const unsigned id, const std::string& first ,const std::string& last, const unsigned int birth);
/* 
 the function which we add by it the manager to the wanted city
 the function recieve manager id and his first and last name and his birth year
 if the manager already exists the function will return the exeption CitizenAlreadyExists
*/        
        void addManager(const unsigned id, const std::string& first ,const std::string& last, const unsigned int birth);
/* 
the function which add the the faculte by it to the wanted city
 the function recieve faculty id and the desired skills and the wanted score and a condition for work
 if the faculty already exists in the city the function will return the exeption FacultyAlreadyExists
*/ 
        void addFaculty(const unsigned id, const Skill& teached_Skill ,const unsigned int score ,  Condition* facultyCondtion );
/* 
the function which we create by it a new workplace and add it to the wanted city
 the function recieve workplace id and its name and the salary of managers and employees
 if the workplace already exists the function will return the exeption WorkplaceAlreadyExists
*/
        void createWorkplace(unsigned int id,  std::string name,  int employ_salary,  int manger_salary);
/* 
 the function which we by it try to teach the employee a specific skill 
 the function recieve worker and faculty id
 if the employee does not exists in the city the function will return the exeption EmployeeDoesNotExist
if the faculty does not exists in the city the function will return the exeption FacultyDoesNotExist
*/
        void teachAtFaculty( unsigned int id_worker , unsigned int id_faculty );
        template<class HiringCondition>
/* 
 the function which we add by it the employee to the wanted workplace 
 the function recieve employee and manager and workplace id and condition to consider hiring the worker
 if the manager does not exists in the city the function will return the exeption ManagerDoesNotExist
if the workplace does not exists in the city the function will return the exeption WorkplaceDoesNotExist
 if the employee does not exists in the city the function will return the exeption EmployeeDoesNotExist

*/  
        void hireEmployeeAtWorkplace(HiringCondition condition1 ,const unsigned int workerId, const unsigned int mangerId,unsigned int workplaceId)
        {
            for ( Employee_it= this->Employees.begin();Employee_it!= this->Employees.end(); Employee_it++) {
                if (Employee_it.operator*()->getId()==workerId)
                {
                    break;
                }
            }
            if (Employee_it== this->Employees.end())
            {
                throw EmployeeDoesNotExist();
            }

            for ( Manger_it= this->Mangers.begin();Manger_it!= this->Mangers.end(); Manger_it++) {
                if (Manger_it.operator*()->getId()==mangerId)
                {
                    break;
                }
            }
            if (Manger_it== this->Mangers.end())
            {
                throw ManagerDoesNotExist();
            }

            for ( work_it= this->work.begin();work_it!= this->work.end(); work_it++) {
                if (work_it->getId()==workplaceId)
                {
                    break;
                }
            }
            if (work_it== this->work.end())
            {
                throw WorkplaceDoesNotExist();
            }

            for (const auto &item : this->Employees)
            {
                if(item->getId()==workerId)
                {
                    work_it->template hireEmployee(condition1,item,mangerId);
                    break;
                }
            }
        }
/* 
 the copy constructor for out city
 the function recieve a city(by the name of oldCity) and make a copy of it
*/
        City (const City&);
/* 
 the insert operator which with it we enter new information to an existed variable
 the function recieve the city which we want to insert new information to it
*/
        City& operator=(const City &s );
/* 
 the function which we add by it the manager to the wanted workplace 
 the function recieve manager and workplace id
 if the manager does not exists in the city the function will return the exeption ManagerDoesNotExist
if the workplace does not exists in the city the function will return the exeption WorkplaceDoesNotExist
*/ 
        void hireManagerAtWorkplace(unsigned int mangerId,unsigned int WorkId);
/* 
 the function which we by it fire employee from specific workplace 
 the function recieve worker and manager and workplace id
 if the employee does not exists in the city the function will return the exeption EmployeeDoesNotExist
if the manager does not exists in the city the function will return the exeption ManagerDoesNotExist
if the workplace does not exists in the city the function will return the exeption WorkplaceDoesNotExist
*/
        void fireEmployeeAtWorkplace(unsigned int workerId,unsigned int mangerId,unsigned int workId);
/* 
 the function which we by it fire manager from specific workplace 
 the function recieve  manager and workplace id
if the manager does not exists in the city the function will return the exeption ManagerDoesNotExist
if the workplace does not exists in the city the function will return the exeption WorkplaceDoesNotExist
*/
        void fireManagerAtWorkplace(unsigned int mangerId,unsigned int workId);
/* 
 the function which we by it we check if to employees are working in the same workplace 
 the function recieve the two workers id
if one of the workers at least does not exists in the city the function will return the exeption EmployeeDoesNotExist
*/
        bool isWorkingInTheSameWorkplace(unsigned int worker1,unsigned int worker2);
/* 
 the function which print a short description about all the citizen that apply to the condition which there
 wage is higher than a given wage and the return how much they are 
 the function recieve the conditional wage and the operator to print
*/
        int getAllAboveSalary(std::ostream &os ,  int wage) ;
/* 
 the function which print a short description about all the citizen that apply to the condition which if
 they have the given skill  
 the function recieve the conditional skillId and the operator to print
*/
        void printAllEmployeesWithSkill(std::ostream &os , unsigned int SkillId);
/* 
 a function which chick if the employee is a citizen
 the function recieve the citizen id
*/
        bool isCitizen(unsigned int id);
/* 
 the destructor for out city
 the function recieve a delete all the exsisted citizens
*/
        ~City();

    };



}



#endif //CITY_H
