//
// Created by HP-WIN10 on 25/12/2021.
//

#include "Citizen.h"
namespace mtm {


    const std::string &Citizen::getFirstName() const {
        return this->name;
    }

    const std::string &Citizen::getLastName() const {
        return this->familyName;
    }

    unsigned int Citizen::getBirthYear() const {
        return this->BirthYear;
    }

    unsigned int Citizen::getId() const {
        return this->id;
    }

    Citizen::Citizen(unsigned int id, std::string name, std::string familyName, unsigned int birthYear) : id(
            id), name(std::move(name)), familyName(std::move(familyName)), BirthYear(birthYear) {}

    bool Citizen::operator==(const Citizen &citizen2) const {
        return (this->id == citizen2.id);
    }

    bool Citizen::operator<(const Citizen &rhs) const {
        return (this->id < rhs.id);
    }

     int Citizen::getSalary() const {
        return 0;
    }

    Citizen &Citizen::operator=(const Citizen &citizen2) {
        this->name=citizen2.getFirstName();
        this->familyName=citizen2.getLastName();
        this->BirthYear=citizen2.getBirthYear();
        this->id=citizen2.getId();
        return *this;
    }

    Citizen::~Citizen() = default;


    bool operator<=(const Citizen &citizen1, const Citizen &citizen2) {
        return ((citizen1 < citizen2) || (citizen1 == citizen2));
    }

    bool operator!=(const Citizen &citizen1, const Citizen &citizen2) {
        return !(citizen1 == citizen2);
    }

    bool operator>(const Citizen &citizen1, const Citizen &citizen2) {
        return !(citizen1 <= citizen2);
    }

    bool operator>=(const Citizen &citizen1, const Citizen &citizen2) {
        return (!(citizen1 <= citizen2) || (citizen1 == citizen2));
    }


}
