//
// Created by HP-WIN10 on 30/12/2021.
//

#include "City.h"

namespace mtm {

    bool compareWorkPlaces(const mtm::Workplace& c1, const mtm::Workplace& c2)
    {
        if (c1.getId()<c2.getId())
            return true;
        else
            return false;
    }
          

    bool compareFaculties(const Faculty<Condition>& c1, const Faculty<Condition>& c2)
    {
        if (c1.getId()<c2.getId())
            return true;
        else
            return false;
    }
    mtm::City::City(const std::string &cityName) : CityName(cityName), Employees() , Mangers() , work() , Faculties() {}


    void City::addEmployee(const unsigned int id, const std::string& first, const std::string& last,
                           const unsigned int birth)
    {
        if(isCitizen(id))
        {
            throw CitizenAlreadyExists();
        }
        Employee* e1 = new Employee(id, first, last, birth);
        this->Citizens.push_front(e1);
        this->Citizens.sort(Manager::compareCitizens);
        this->Employees.push_front(e1);
        this->Employees.sort(Manager::compareCitizens);
    }

 void City
    ::addManager(const unsigned int id, const std::string& first, const std::string& last, const unsigned int birth) {
        if(isCitizen(id))
        {
            throw CitizenAlreadyExists();
        }
        Manager* e1 = new Manager(id, first, last, birth);
        this->Citizens.push_front(e1);
        this->Citizens.sort(Manager::compareCitizens);
        this->Mangers.push_front(e1);
        this->Mangers.sort(Manager::compareCitizens);

    }


    void
    City::createWorkplace(unsigned int id, std::string name, int employ_salary,  int manger_salary) {
        for ( work_it= this->work.begin();work_it!= this->work.end(); work_it++) {
            if (work_it.operator*().getId()==id)
            {
                throw WorkplaceAlreadyExists();
            }
        }
        Workplace  NewWorkPlace = Workplace(id, std::move(name), employ_salary, manger_salary);
        this->work.push_front(NewWorkPlace);
        this->work.sort(compareWorkPlaces);
    }

    void City::addFaculty(const unsigned int id, const Skill &teached_Skill, const unsigned int score,
                          Condition *facultyCondtion) {
        for (const auto &item : this->Faculties)
        {
            if (item.getId()==id)
            {
                throw FacultyAlreadyExists();
            }
        }
        Faculty<Condition> faculty1 =  Faculty<Condition>(id,teached_Skill,score,facultyCondtion);
        this->Faculties.push_front(faculty1);
        this->Faculties.sort(compareFaculties);
    }

    void City::hireManagerAtWorkplace(unsigned int mangerId, unsigned int WorkId) {
        for ( Manger_it= this->Mangers.begin();Manger_it!= this->Mangers.end(); Manger_it++) {
            if (Manger_it.operator*()->getId()==mangerId)
            {
                break;
            }
        }
        if (Manger_it== this->Mangers.end())
        {
            throw ManagerDoesNotExist();
        }
        for ( work_it= this->work.begin();work_it!= this->work.end(); work_it++) {
            if (work_it->getId()==WorkId)
            {
                break;
            }
        }
        if (work_it== this->work.end())
        {
            throw WorkplaceDoesNotExist();
        }

        work_it->hireManager(*Manger_it);
    }

    void City::teachAtFaculty(unsigned int id_worker, unsigned int id_faculty) {
        for (it_Faculties= this->Faculties.begin();it_Faculties != this->Faculties.end() ; it_Faculties++)
        {
            if (it_Faculties->getId()==id_faculty)
            {
                break;
            }
        }
        if (it_Faculties == this->Faculties.end())
        {
            throw FacultyDoesNotExist();
        }

        for (Employee_it= this->Employees.begin();Employee_it != this->Employees.end() ; Employee_it++)
        {
            if (Employee_it.operator*()->getId()==id_worker)
            {
                break;
            }
        }
        if (Employee_it == this->Employees.end())
        {
            throw EmployeeDoesNotExist();
        }

        it_Faculties->teach(*Employee_it);

    }

    void City::fireEmployeeAtWorkplace(unsigned int workerId, unsigned int mangerId, unsigned int workplaceId) {

        if (!isCitizen(workerId))
        {
            throw EmployeeDoesNotExist();
        }

        if (!isCitizen(mangerId))
        {
            throw ManagerDoesNotExist();
        }
        for ( work_it= this->work.begin();work_it!= this->work.end(); work_it++) {
            if (work_it->getId()==workplaceId)
            {
                break;
            }
        }
        if (work_it== this->work.end())
        {
            throw WorkplaceDoesNotExist();
        }
        work_it->fireEmployee(workerId,mangerId);
    }

    void City::fireManagerAtWorkplace(unsigned int mangerId, unsigned int workId) {
        if (!isCitizen(mangerId))
        {
            throw ManagerDoesNotExist();
        }
        for ( work_it= this->work.begin();work_it!= this->work.end(); work_it++) {
            if (work_it->getId()==workId)
            {
                break;
            }
        }
        if (work_it== this->work.end())
        {
            throw WorkplaceDoesNotExist();
        }
        work_it->fireManager(mangerId);
        for (const auto &item : this->Mangers)
        {
            if(item->getId()==mangerId)
            {
                item->removeEmployees();
                break;
            }
        }

    }


    int City::getAllAboveSalary(std::ostream &os, int wage) {
        int count=0;
        for (const auto &item : this->Citizens)
        {
            if(item->getSalary()>=wage)
            {
                item->printShort(os);
                count++;
            }
        }
        return count;

    }

    void City::printAllEmployeesWithSkill(std::ostream &os, unsigned int SkillId) {

        for (const auto &item : this->Employees)
        {
            if(item->hasSkill(SkillId))
            {
                item->printShort(os);
            }
        }
    }

    bool City::isWorkingInTheSameWorkplace(unsigned int worker1, unsigned int worker2) {

        if ( !isCitizen(worker1) )
        {
            throw EmployeeDoesNotExist();
        }

        if (!isCitizen(worker2))
        {
            throw EmployeeDoesNotExist();

        }
        for(Employee* it : this->Employees)
        {
            if (it->getId()==worker1)
            {
                for(Employee* it2 : this->Employees)
                {
                    if (it2->getId()==worker2)
                    {
                        for (const auto &item : it->Workplaces)
                        {
                            for (const auto &item2 : it2->Workplaces)
                            {
                                if(item==item2)
                                    return true;
                            }
                        }
                    }
                }
            }
        }


        return false;
    }


    City::City(const City &OldCity) {
        for ( Employee* item : OldCity.Employees)
        {
            this->addEmployee(item->getId(),item->getFirstName(),item->getLastName(),item->getBirthYear());
        }
        for ( Manager* item : OldCity.Mangers)
        {
            this->addManager(item->getId(),item->getFirstName(),item->getLastName(),item->getBirthYear());
        }

        for ( Employee* item : this->Employees)
        {
            for ( Employee* item2 : OldCity.Employees)
            {
                if (item->getId()==item2->getId())
                {
                    *item = *item2;
                    break;
                }
            }
        }

        for ( Manager* item : this->Mangers)
        {
            for ( Manager* item2 : OldCity.Mangers)
            {
                if (item->getId()==item2->getId())
                {
                    *item = *item2;
                    break;
                }
            }
        }
        for ( Manager* item : this->Mangers)
        {
            for (Employee* newWorker : this->Employees)
            {
                if (item->hasWorker(newWorker->getId()))
                {
                    item->removeEmployee(newWorker->getId());
                    item->addEmployee(newWorker);
                }
            }
        }
        for (const auto &item : OldCity.work)
        {
            createWorkplace(item.getId(),item.getName(),item.getWorkersSalary(),item.getManagersSalary());
        }


        for ( auto item : this->work) {
            for (Workplace oldWork: OldCity.work) {

                if(oldWork.getId()==item.getId()) {
                    for (const auto &item2: this->Mangers) {
                        if (oldWork.MangerIsWorking(item2->getId())) {
                            item.Mangers.remove(item2);
                            item2->setSalary(0);
                            item.hireManager(item2);
                            for (const auto &item3 : item2->Crow)
                            {
                                item3->setSalary(-(item.getWorkersSalary()));
                            }
                        }
                    }
                    break;
                }

            }
        }

        for (const auto &item : OldCity.Faculties)
        {
            this->addFaculty(item.getId(),item.getSkill(),item.getAddedPoints(),item.getFacultyCondtion());
        }

    }

    bool City::isCitizen(unsigned int id) {
        for (const auto &item : this->Citizens)
        {
            if(item->getId()==id)
            {
                return true;
            }
        }
        return false;
    }

    City &City::operator=(const City &OldCity) {
        if (this == &OldCity)
        {
            return *this;
        }

        this->CityName=OldCity.CityName;

        this->Employees.clear();
        this->Mangers.clear();
        this->work.clear();
        this->Faculties.clear();

        for ( Employee* item : OldCity.Employees)
        {
            this->addEmployee(item->getId(),item->getFirstName(),item->getLastName(),item->getBirthYear());
        }
        for ( Manager* item : OldCity.Mangers)
        {
            this->addManager(item->getId(),item->getFirstName(),item->getLastName(),item->getBirthYear());
        }

        for ( Employee* item : this->Employees)
        {
            for ( Employee* item2 : OldCity.Employees)
            {
                if (item->getId()==item2->getId())
                {
                    *item = *item2;
                    break;
                }
            }
        }

        for ( Manager* item : this->Mangers)
        {
            for ( Manager* item2 : OldCity.Mangers)
            {
                if (item->getId()==item2->getId())
                {
                    item = item2;
                    break;
                }
            }
        }
        for ( Manager* item : this->Mangers)
        {
            for (Employee* newWorker : this->Employees)
            {
                if (item->hasWorker(newWorker->getId()))
                {
                    item->removeEmployee(newWorker->getId());
                    item->addEmployee(newWorker);
                }
            }
        }
        for (const auto &item : OldCity.work)
        {
            createWorkplace(item.getId(),item.getName(),item.getWorkersSalary(),item.getManagersSalary());
        }


        for ( auto item : this->work) {
            for (Workplace oldWork: OldCity.work) {

                if(oldWork.getId()==item.getId()) {
                    for (const auto &item2: this->Mangers) {
                        if (oldWork.MangerIsWorking(item2->getId())) {
                            item.Mangers.remove(item2);
                            item2->setSalary(0);
                            item.hireManager(item2);
                            for (const auto &item3 : item2->Crow)
                            {
                                item3->setSalary(-(item.getWorkersSalary()));
                            }
                        }
                    }
                    break;
                }

            }
        }

        for (const auto &item : OldCity.Faculties)
        {
            this->addFaculty(item.getId(),item.getSkill(),item.getAddedPoints(),item.getFacultyCondtion());
        }

        return *this;
    }

    City::~City() {
        for (const auto &item : this->Citizens)
        {
            delete item;
        }
    }


}

