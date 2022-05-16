//
// Created by HP-WIN10 on 24/12/2021.
//

#ifndef MTM2_SKILLS_H
#define MTM2_SKILLS_H

#include <iostream>
#include <string>
#include <memory>
#include "exceptions.h"
namespace mtm {
    class Skill {
    private:
        /**
         * as suggested , each skill have an id, name , level , an experience needed to earn it.
         */

        unsigned int id ;
        std::string name;
         int required;

    public:
        /**
         * this the constructor
         * @param id - the id for the skill.
         * @param name - the skill's name.
         * @param exp - experience needed to earn the skill.
         * @param level - the level that the skills owner have of it
         */
        Skill(unsigned int id ,const std::string &name , int exp);
        /**
         * we use the default destructor
         */
        ~Skill()=default;
        /**
         * a method that gets the skill's id.
         * @return
         */
        unsigned int getId () const;
        /**
          * a method that gets the skill's name.
          * @return
          */
        const std::string &getName() const;
        /**
         *a method that gets the skill's required points in order to earn it .
         * @return
         */
         int getRequiredPoints()const;
        /**
         * an operator to compare a skill with another , check if they have the same id and therefore are the same skill.
         * @param skill - a skill we want to compere our 'this' with
         * @return
         */
        bool operator==(const Skill &skill) const;

        /**
           an operator to compare a skill with another , check if this id is lower than the skill.
         * @param skill - a skill we want to compere our 'this' with
         * @return
         */
        bool operator<(const Skill &skill) const;
        /**
         *update the num of points needed to earn a skill.
         * @param new_exp - the experience we want to add/decrease from the original experience needed.
         * @return
         */
        Skill& operator+=( int new_exp);

        /**
         * an ++ operator - used as an overload so ++skill dont do anything.
         * @return
         */
        Skill& operator++() = delete;
        /**
         * an overload of ++ operator that actually does the required when we do a skill++.
         * @return
         */
        Skill operator++(int  );

        /**
         * a printing function - is friend so it can accesses the required fields
         * @param os
         * @param skills
         * @return
         */
        friend std::ostream &operator<<(std::ostream &os, const Skill &skills);

        Skill (const Skill&)=default;


    };
    bool operator<=(const Skill &skill1,const Skill &skill2) ;
    bool operator>(const Skill &skill1,const Skill &skill2) ;
    bool operator>=(const Skill &skill1,const Skill &skill2) ;
    bool operator!=(const Skill &skill1,const Skill &skill2);
    Skill operator+( int points,  Skill skill1);
    Skill operator+(Skill skill1,  int points);


}

#endif //MTM2_SKILLS_H
