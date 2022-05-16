//
// Created by HP-WIN10 on 25/12/2021.
//

#include "Manager.h"
//
// Created by HP-WIN10 on 25/12/2021.
//

namespace mtm {

    void Manager::addEmployee(Employee *employee) {
        if (this->Crow.empty()) {
            this->Crow.push_front(employee);
            employee->addWork(this->getWorkplaceId());
            return;
        }
        it_manger = this->Crow.begin();
        for (; it_manger != this->Crow.end(); it_manger++) {
            if ((it_manger.operator*()->getId()) == employee->getId()) {
                break;
            }
        }
        if (it_manger != this->Crow.end()) {
            throw EmployeeAlreadyHired();
        } else
            this->Crow.push_front(employee);
        this->Crow.sort(compareCitizens);
        employee->addWork(this->getWorkplaceId());
    }

    void Manager::setSalary(int salary) {
        this->Salary = salary;
        if (this->Salary < 0) {
            this->Salary = 0;
        }
    }

    void Manager::printShort(std::ostream &os) {
        os << this->getFirstName() << " " << this->getLastName() << "\n"
           << "Salary: " << this->getSalary() << "\n";
    }

    void Manager::printLong(std::ostream &os) {

        os << this->getFirstName() << " " << this->getLastName() << "\n"
           << "id - " << this->getId() << " " << "birth_year - " << this->getBirthYear() << "\n"
           << "Salary: " << this->getSalary() << "\n";

        if (this->Crow.empty())
        {
            return;
        }
        os<<"Employees: " << "\n";

        it_manger = this->Crow.begin();
        while (it_manger != this->Crow.end()) {
            it_manger.operator*()->printShort(os);
            it_manger++;
        }
    }

    int Manager::getSalary() const {
        return this->Salary;
    }

    void Manager::removeEmployee(const unsigned int employeeId) {
        for (it_manger = this->Crow.begin(); it_manger != this->Crow.end(); it_manger++) {
            if (it_manger.operator*()->getId() == employeeId) {
                break;
            }
        }

        if (it_manger == this->Crow.end()) {
            throw EmployeeIsNotHired();
        }

        it_manger.operator*()->setSalary(-this->getWorkerSalary());
        it_manger.operator*()->removeWork(this->WorkplaceId);
        this->Crow.remove(*it_manger);
    }

    void Manager::removeEmployees() {
        this->Crow.clear();
    }

    Manager *Manager::clone() const {
        Manager *ptr = new Manager(*this);
        return ptr;
    }

    int Manager::getWorkerSalary() const {
        return this->workerSalary;
    }

    void Manager::setWorkerSalary(int workerSalary1) {
        Manager::workerSalary = workerSalary1;
    }

    unsigned int Manager::getWorkplaceId() const {
        return this->WorkplaceId;
    }

    void Manager::setWorkplaceId(unsigned int workplace) {
        WorkplaceId = workplace;
    }

    Manager::Manager(unsigned int id, const std::string &name, const std::string &familyName, unsigned int birthYear)
            : Citizen(id, name, familyName, birthYear), Crow() {
        Salary = 0;
        WorkplaceId = 0;
        workerSalary = 0;
    }

    bool Manager::hasWorker(unsigned int employeeId) {
        for (it_manger = this->Crow.begin(); it_manger != this->Crow.end(); it_manger++) {
            if (it_manger.operator*()->getId() == employeeId) {
                return true;
            }
        }
        return false;
    }

    Manager &Manager::operator=(const Manager &manger) {
        if (this == &manger)
        {
            return *this;
        }
        this->name=manger.getFirstName();
        this->familyName=manger.getLastName();
        this->id=manger.getId();
        this->BirthYear=manger.getBirthYear();
        this->workerSalary=manger.getWorkerSalary();
        this->WorkplaceId=manger.getWorkplaceId();
        this->Salary=manger.getSalary();
        for (const auto &item : manger.Crow)
        {
            this->addEmployee(item);
        }

        return *this;
    }

    Manager::Manager(const Manager &manger)  : Citizen(manger) {
        this->workerSalary=manger.getWorkerSalary();
        this->WorkplaceId=manger.getWorkplaceId();
        this->Salary=manger.getSalary();
        for (const auto &item : manger.Crow)
        {
            this->addEmployee(item);
        }

    }

}