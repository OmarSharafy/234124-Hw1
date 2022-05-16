//
// Created by HP-WIN10 on 02/01/2022.
//

#ifndef MANAGER_CPP_FACULTY_H
#define MANAGER_CPP_FACULTY_H
#include "Manager.h"
#include "Employee.h"
#include "Skill.h"
namespace mtm {
    using namespace std;
    class Condition{
    public:
        virtual bool operator()(Employee* employee) = 0;
    };

    template<class T> class Faculty {
    private:
        unsigned int id;
        Skill learendSkill;
        unsigned int points;
        T* facultyCondtion;

        /**
         * for every faculty - we have an id ,Skill it teaches , num of pints that each Employee that learns get
         * and a coundtion to get acce[ted
         */
    public:
        /**
         * our constractor
         * @param id
         * @param skill
         * @param points
         * @param facultyCondtion
         */
        Faculty(unsigned int id, const class Skill &skill, unsigned int points, T *facultyCondtion);
        ~Faculty()=default;
        /**
         * gets the id of this faculty
         * @return
         */

        unsigned int getId() const;
        /**
         * gets the added points
         * @return
         */

        unsigned int getAddedPoints() const;

        /**
         * gets the skill
         * @return
         */

        Skill getSkill() const;
        /**
         * gets the coundtion
         * @return
         */

        T *getFacultyCondtion() const;
        /**
         * gets an employee and teach him the skill - if he is not accepted it throw a EmployeeNotAccepted
         * if he dont have enoghf points it throws a " cant learn skill"
         * @param e1
         */

        void teach(Employee* e1) const;

        Faculty<T> & operator=(const Faculty<T>& faculty)=default;
    };

    template<class T>
    Faculty<T>::Faculty(unsigned int id, const class Skill &skill, unsigned int points,  T* facultyCondtion)
            :id(id), learendSkill(skill),points(points),facultyCondtion(facultyCondtion) {}

    template<class T>
    unsigned int Faculty<T>::getId() const {
        return this->id;
    }

    template<class T>
    unsigned int Faculty<T>::getAddedPoints() const {
        return this->points;
    }

    template<class T>
     Skill Faculty<T>::getSkill() const {
        return this->learendSkill;
    }

    template<class T>
    void Faculty<T>::teach(Employee* e1) const {
        if(!(this->facultyCondtion->operator()(e1)))
        {
            throw EmployeeNotAccepted();
        }
        e1->learnSkill(this->learendSkill);
        e1->setScore(this->getAddedPoints());
    }

    template<class T>
    T *Faculty<T>::getFacultyCondtion() const {
        return this->facultyCondtion;
    }


}
#endif //MANAGER_CPP_FACULTY_H
