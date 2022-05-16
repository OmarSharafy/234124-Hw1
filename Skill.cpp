//
// Created by HP-WIN10 on 24/12/2021.
//

#include "Skill.h"
namespace mtm {

    Skill::Skill(unsigned int id, const std::string &name,  int required) :
            id(id), name(name), required(required) {}

    unsigned int Skill::getId() const {
        return this->id;
    }

    const std::string &Skill::getName() const {
        return this->name;
    }

     int Skill::getRequiredPoints() const {
        return this->required;
    }

    bool Skill::operator==(const Skill &skill) const {
        return (this->id == skill.id);
    }

    bool Skill::operator<(const Skill &skill) const {
        return (this->id < skill.id);
    }

    bool operator!=(const Skill &skill1, const Skill &skill2) {
        return !(skill1 == skill2);
    }

    bool operator<=(const Skill &skill1, const Skill &skill2) {
        return ((skill1 < skill2) || (skill1 == skill2));
    }

    bool operator>(const Skill &skill1, const Skill &skill2) {
        return !(skill1 <= skill2);
    }

    bool operator>=(const Skill &skill1, const Skill &skill2) {
        return ((skill1 > skill2) || (skill1 == skill2));
    }



    Skill &Skill::operator+=( int points) {
        if (points < 0) {
            throw NegativePoints();
        }
        this->required += points;
        return *this;
    }

    Skill Skill::operator++(int) {
        Skill result = *this;
        *this+=1;
        return result;
    }

    Skill operator+( Skill skill1,  int points)
    {
        if (points<0)
        {
            throw NegativePoints();
        }
        Skill skill2(skill1);
        return skill2+=points;
    }

    Skill operator+(  int points,  Skill  skill1)
    {
        if (points<0)
        {
            throw NegativePoints();
        }
        Skill skill2(skill1);
        return skill2+=points;
    }


    std::ostream &operator<<(std::ostream &os, const Skill &skills) {

        os << skills.name << "\n";
        return os;
    }

}