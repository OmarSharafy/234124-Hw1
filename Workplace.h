//
// Created by HP-WIN10 on 24/12/2021.
//

#ifndef SKILLS_H_WORKPLACE_H
#define SKILLS_H_WORKPLACE_H

#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include "Manager.h"
#include "Employee.h"

namespace mtm {


    class Workplace {
    private:
        unsigned int id{};
        std::string work_place_name;
        int employ_salary{};
        int manger_salary{};
        std::list<Manager *> Mangers;
        std::list<Manager *>::iterator it;

        friend class City;

    public:
/* 
 the function which return which manager id is bigger 
 it takes two managers and compare between them
*/
        static bool compareManagers(mtm::Manager *c1, mtm::Manager *c2) {
            if (c1->getId() < c2->getId())
                return true;
            else
                return false;
        }

        Workplace(unsigned int id, std::string name, int employ_salary, int manger_salary);
/* 
function to get the id of the workplace 
*/
        unsigned int getId() const;
/* 
function to get the name of the workplace
*/
        const std::string &getName() const;
/* 
function to get the salary of the employee
*/
        int getWorkersSalary() const;
/* 
function to get the salary of the manager
*/
        int getManagersSalary() const;

        template<typename condition>
/* 
the function where we hire the employee(add him to our workplace set)
the function reieve the employee and the manager id and the conition to cosider for hiring
if the employee already is not existed the function return exeption EmployeeNotSelected
if the manager is not existed the function return exeption ManagerIsNotHired
*/
        void hireEmployee(condition condition1, Employee *Employ, const unsigned int mangerId) {
            if (!(condition1(Employ))) {
                throw EmployeeNotSelected();

            }
            it = this->Mangers.begin();
            while (it != this->Mangers.end()) {

                if (it.operator*()->getId() == mangerId) {
                    break;
                }
                it++;
            }
            if (it == this->Mangers.end()) {
                throw ManagerIsNotHired();
            }
            it.operator*()->addEmployee(Employ);
            Employ->setSalary(this->getWorkersSalary());
        }

/* 
the function where we hire the manager(add him to our workplace set)
the function reieve the manager which we want to hire
if the manager already hired the function return exeption ManagerAlreadyHired
if the manager cannot be because he is working in another workplace hired the function return exeption CanNotHireManager
*/
        void hireManager(Manager *manager);
/* 
the function where we fire the employee(remove him from our workplace set)
the function reieve the employee id and his manager id
if the employee does not work for this manager the function return exeption EmployeeIsNotHired
if the manager does not exist in the workplace the function return exeption ManagerIsNotHired
*/
        void fireEmployee(unsigned int mangerId, unsigned int employeeId);
/* 
 the function where we fire the manager(remove him from our workplace set)
 the function reieve the manager id
if the manager does not exist in the workplace the function return exeption ManagerIsNotHired
*/ 
        void fireManager(const unsigned int mangerId);
/* 
the function where we print the information about our workplace
the function reieve the workplace and the print operator
and print specific information about it
*/
        friend std::ostream &operator<<(std::ostream &os, const Workplace &place);
/* 
the function where we check if the manager is working (still in our workplace set)
the function reieve the manager id
*/
         bool MangerIsWorking(unsigned int);
/* 
 the insert operator which with it we enter new information to an existed variable
 the function recieve the workplace which we want to insert new information to it
*/
        Workplace& operator=(const Workplace& );
/* 
 the copy constructor for our workplace
 the function recieve a workplace(by the name of work) and make a copy of it
*/
        Workplace (const Workplace& );
/* 
 the () opreator
*/
        Workplace()=default;
/* 
the destructor
*/
        ~Workplace()=default;
    };

}
#endif //SKILLS_H_WORKPLACE_H
