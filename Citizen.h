//
// Created by HP-WIN10 on 25/12/2021.
//

#ifndef SKILL_CPP_CITIZEN_H
#define SKILL_CPP_CITIZEN_H

#include <string>
#include <ostream>
#include "Skill.h"

namespace mtm {

    class Citizen {
    protected:
        unsigned int id;
        std::string name;
        std::string familyName;
        unsigned int BirthYear;


        Citizen()=default;
        Citizen(unsigned int id, std::string name, std::string familyName, unsigned int birthYear);
        /**
         * constructor that only is accessible for the inheriting classes
         * id - the citizen id
         * name - the citizen first name
         * familyName - the citizen lastname
         * birthYear - the year our citizen was born
         */

    public:

      unsigned int getId() const;

       const std::string &getFirstName() const;

       const std::string &getLastName() const;

       unsigned int getBirthYear() const;

       virtual void printShort( std::ostream  &os )
        {
            os<<"hi"<<std::endl;
        }
       virtual void printLong(std::ostream &os)
        {
           os<<"hi"<<std::endl;
        }
        bool operator==(const Citizen &rhs) const;

        bool operator<(const Citizen &rhs) const;


        class Compare{
        public:
            bool operator()(Citizen* c1, Citizen* c2){
                return (c1->getId() < c2->getId());
            }
         };
        Compare citizenCompare;

        Citizen (const Citizen&)=default;

        Citizen& operator=(const Citizen &citizen2);

        virtual void setSalary( int salary) = 0;

        virtual Citizen* clone() const = 0;

        virtual int getSalary() const = 0;

        virtual ~Citizen();


    };

    bool operator!=(const Citizen &citizen1, const Citizen &citizen2);

    bool operator<=(const Citizen &citizen1, const Citizen &citizen2);

    bool operator>=(const Citizen &citizen1, const Citizen &citizen2);

    bool operator>(const Citizen &citizen1, const Citizen &citizen2);


}

#endif //SKILL_CPP_CITIZEN_H
