//
// Created by HP-WIN10 on 25/12/2021.
//
#include "Employee.h"
#include "string"
namespace mtm {
    bool compareSkills(const Skill& c1,const Skill& c2)
    {
        if (c1.getId()<c2.getId())
            return true;
        else
            return false;
    }



    std::list<Skill>::iterator it;
    Employee::Employee(unsigned int id, const std::string &name, const std::string &familyName,
                            unsigned int birthYear) :
            Citizen(id, name, familyName, birthYear), Employ_Skills(){
        Salary=0, Score=0;
//        std::list<Skill> Skills;

    }

     int Employee::getSalary() const {
        return this->Salary;
    }


     int Employee::getScore() const {
        return this->Score;
    }

    void Employee::setSalary( int salary) {
        this-> Salary += salary;
        if (this->Salary<=0)
        {
            this->Salary=0;
        }
    }

    void Employee::setScore( int score) {
        this -> Score += score;
        if (this->Score<0)
        {
            this->Score=0;
        }
    }


    void Employee::learnSkill(const Skill& learnedSkill)  {

        if (learnedSkill.getRequiredPoints()> this->getScore())
        {
            throw CanNotLearnSkill();
        }
        if(this->Employ_Skills.empty())
        {
            this->Employ_Skills.push_front(learnedSkill);
            return;
        }

        it = this->Employ_Skills.begin();
        while (it!= this->Employ_Skills.end())
        {
            if(it->getId()== learnedSkill.getId())
            {
                break;
            }
            it++;
        }
        if (it==Employ_Skills.end())
        {
            this->Employ_Skills.push_front(learnedSkill);
            this->Employ_Skills.sort(compareSkills);

            return;
        }

        else
            throw SkillAlreadyLearned();
        //iterator = std::find(Employ_Skills.begin() , Employ_Skills.end() , learnedSkill.getName());
    }


    void Employee::forgetSkill( unsigned int id)
    {
        if(this->Employ_Skills.empty())
        {
            throw DidNotLearnSkill();
        }
        for (it = this->Employ_Skills.begin(); it !=this->Employ_Skills.end(); it++)
        {
            if (it->getId() == id)
            {
                this->Employ_Skills.erase(it);
                return;
            }
        }
        throw DidNotLearnSkill();
    }

    bool Employee::hasSkill(unsigned int id)
    {
        if(this->Employ_Skills.empty())
        {
            return false;
        }
        for (it = this->Employ_Skills.begin(); it !=this->Employ_Skills.end(); it++)
        {
            if (it->getId()==id)
            {
                return true;
            }
        }
        return false;

    }



    void Employee::printShort(std::ostream &os) {
        os<< this->getFirstName() << " " << this->getLastName() << std::endl;
        os<<"Salary: " << this->getSalary() << " " <<"Score: " << this->getScore()<<std::endl;
    }

    void Employee::printLong(std::ostream &os)
    {
        os<< this->getFirstName() << " " << this->getLastName() << "\n"
          << "id - "<< this->getId() << " " << "birth_year - "<< this->getBirthYear() <<  "\n"
          << "Salary: " << this->getSalary() << " " <<"Score: " << this->getScore() ;


        if (this->Employ_Skills.empty())
        {
            os<<"\n";
            return;
        }
        os<<" Skills: " << "\n";
        it=this->Employ_Skills.begin();
        while(true)
        {
            os<< it->getName() <<std::endl;
            it++;
            if( it==this->Employ_Skills.end())
            {
                break;
            }
        }
    }

    Employee *Employee::clone() const {
        Employee *ptr = new Employee(this->getId(), this->getFirstName(), this->getLastName(), this->getBirthYear());
        for (const auto &item : this->Employ_Skills)
        {
            ptr->learnSkill(item);
        }
        return (ptr) ;
    }

    void Employee::addWork(unsigned int workId) {
        this->Workplaces.insert(workId);
    }

    void Employee::removeWork(unsigned int workId) {

        int count =0;
        for (const auto &item : this->Workplaces)
        {
            if (item==workId)
            {
                count++;
            }
        }
        this->Workplaces.erase(workId);
        if (count>1)
        {
            while (count!=1) {
                count--;
                this->Workplaces.insert(workId);
            }
        }
    }

    bool Employee::isWorkingAt(unsigned int id) {
        for (const unsigned int &item : this->Workplaces)
        {
            if(item==id)
            {
                return true;
            }
        }
        return false;
    }

    Employee &Employee::operator=(const Employee &employee) {
        if (this == &employee)
        {
            return *this;
        }
        this->name=employee.getFirstName();
        this->familyName=employee.getLastName();
        this->id=employee.getId();
        this->BirthYear=employee.getBirthYear();
        this->Score=employee.getScore();
        this->Salary=employee.getSalary();
        for (const auto &item : employee.Employ_Skills)
        {
            this->learnSkill(item);
        }

        return *this;
    }

    Employee::Employee (const Employee&employee) : Citizen(employee)
    {
        this->name=employee.getFirstName();
        this->familyName=employee.getLastName();
        this->id=employee.getId();
        this->BirthYear=employee.getBirthYear();
        this->Score=employee.getScore();
        this->Salary=employee.getSalary();
        for (const auto &item : employee.Employ_Skills)
        {
            this->learnSkill(item);
        }

    }


}