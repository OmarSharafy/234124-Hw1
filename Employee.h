//
// Created by HP-WIN10 on 25/12/2021.
//

#ifndef SKILL_CPP_EMPLOYEE_H
#define SKILL_CPP_EMPLOYEE_H

#include "Citizen.h"
#include "Skill.h"
#include "exceptions.h"
#include <list>
#include <iterator>
#include "ostream"
#include <set>
namespace mtm {
    class Employee : public Citizen {
    private:
         int Salary;
         int Score;
         std::list<Skill> Employ_Skills;
         std::set<unsigned int> Workplaces;
         friend class City;
    public:
         Employee(unsigned int id, const std::string &name, const std::string &familyName, unsigned int birthYear);

         int getSalary() const override;

         Employee (const Employee&);

         Employee& operator=(const Employee& employee);

         int getScore() const;

         void setSalary( int salary) override;

         void setScore( int score);

         void learnSkill (const Skill&) ;

         void forgetSkill(unsigned int id);

         bool hasSkill(unsigned  int id);

         Employee* clone() const override;

         void printShort(std::ostream &os)  override;

         void  printLong(std::ostream &os) override;

         void addWork(unsigned int workId);

         void removeWork(unsigned int workId);

         bool isWorkingAt(unsigned int);

         ~Employee() override =default;

        };

}
#endif //SKILL_CPP_EMPLOYEE_H
