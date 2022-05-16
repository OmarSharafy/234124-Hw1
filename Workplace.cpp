//
// Created by HP-WIN10 on 24/12/2021.
//

#include "Workplace.h"
#include "iostream"
namespace mtm {

    Workplace::Workplace(unsigned int id, std::string name, int employ_salary,
                         int manger_salary) :
            id(id), work_place_name(std::move(name)), employ_salary(employ_salary), manger_salary(manger_salary),
            Mangers() {
    }


    unsigned int Workplace::getId() const {
        return this->id;
    }

    const std::string &Workplace::getName() const {
        return work_place_name;
    }

    int Workplace::getWorkersSalary() const {
        return this->employ_salary;
    }

    int Workplace::getManagersSalary() const {
        return this->manger_salary;
    }

    void Workplace::hireManager(Manager *manager) {
        if (this->Mangers.empty()) {
            if ( manager->getSalary() > 0) {
                throw CanNotHireManager();
            }
            this->Mangers.push_front(manager);
            manager->setWorkplaceId(this->getId());
            manager->setSalary((this->getManagersSalary()));
            manager->setWorkerSalary(this->getWorkersSalary());
            for (const auto &item : manager->Crow)
            {
                item->setSalary(this->getWorkersSalary());
            }
            return;
        }

        it = this->Mangers.begin();
        for (; it != this->Mangers.end(); it++) {
            if (it.operator*()->getId() == manager->getId()) { break; }
        }
        if (it != this->Mangers.end()) {
            throw ManagerAlreadyHired();
        }
        if ( manager->getSalary() > 0) {
            throw CanNotHireManager();
        }

        this->Mangers.push_front(manager);
        this->Mangers.sort(compareManagers);
        manager->setSalary((this->getManagersSalary()));
        manager->setWorkerSalary(this->getWorkersSalary());
        manager->setWorkplaceId(this->getId());
        for (const auto &item : manager->Crow)
        {
            item->setSalary(this->getWorkersSalary());
        }
        // wait for piazza
    }

    void Workplace::fireEmployee(const unsigned int employeeId, const unsigned int mangerId) {
        for (it = this->Mangers.begin(); it != this->Mangers.end(); it++) {
            if (it.operator*()->getId() == mangerId) {
                break;
            }
        }
        if (it == this->Mangers.end()) {
            throw ManagerIsNotHired();
        }

        for (const auto &item : it.operator*()->Crow)
        {
            if (item->getId()==employeeId)
            {
                it.operator*()->removeEmployee(employeeId);
                return;
            }
        }

        throw EmployeeIsNotHired();
    }

    void Workplace::fireManager(const unsigned int mangerId) {
        for (const auto &item : this->Mangers)
        {
            if (item->getId()==mangerId)
            {

                {
                    for (const auto &item2 : item->Crow)
                    {
                        item2->setSalary(-this->getWorkersSalary());
                    }
                    item->setSalary(0);
                    item->setWorkplaceId(0);
                    this->Mangers.remove(item);
                    return;
                }
            }
        }
            throw ManagerIsNotHired();
    }

    std::ostream &operator<<(std::ostream &os, const Workplace &place) {
        os << "Workplace name - " << place.work_place_name;
        if (!place.Mangers.empty()) {
            os << " Groups:\n";
        } else {
            os << "\n";

            return os;
        }
        for (const auto &item: place.Mangers) {
            os << "Manager ";
            item->printLong(os);
        }
        return os;
    }

    bool Workplace::MangerIsWorking(unsigned int Manger_id) {
        for (const auto &item : this->Mangers)
        {
            if(item->getId()==Manger_id)
            {
                return true;
            }
        }
        return false;
    }
   

    Workplace::Workplace(const Workplace &work) {

        this->work_place_name=work.getName();
        this->id=work.getId();
        this->employ_salary=work.getWorkersSalary();
        this->manger_salary=work.getManagersSalary();

        for (const auto &item : work.Mangers)
        {
            this->Mangers.push_back(item);
        }
    }
   

    Workplace &Workplace::operator=(const Workplace &work) {
        if (this==&work)
        {
            return *this;
        }
        this->work_place_name=work.getName();
        this->id=work.getId();
        this->employ_salary=work.getWorkersSalary();
        this->manger_salary=work.getManagersSalary();

        for (const auto &item : work.Mangers)
        {
            Manager* m1= item->clone();
            this->Mangers.push_back(m1);
        }
        return *this;
    }

}

