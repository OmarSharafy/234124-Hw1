//
// Created by HP-WIN10 on 25/12/2021.
//

#ifndef MANAGER_H
#define MANAGER_H

#include "Citizen.h"
#include "Employee.h"
#include <list>

namespace mtm {

    class Manager : public Citizen {

    private:
        int Salary;
        int workerSalary;
        std::list<Employee*> Crow;
        unsigned int WorkplaceId;
        std::list<Employee *>::iterator it_manger;

    public:
        friend class City;
        friend class Workplace;

        static bool compareCitizens(mtm::Citizen* c1, mtm::Citizen* c2)
        {
            if (c1->getId()<c2->getId())
                return true;
            else
                return false;
        }


        Manager(unsigned int id, const std::string &name, const std::string &familyName, unsigned int birthYear);

        void addEmployee( Employee* employee);

        void removeEmployee( unsigned int employeeId);

        void removeEmployees();

        int getSalary()  const override;

        void setSalary( int salary) override;

        Manager* clone() const override;

        void printShort(std::ostream &os)  override;

        void  printLong(std::ostream &os) override;

        unsigned int getWorkplaceId() const;

        void setWorkplaceId( int unsigned workplaceId);

        int getWorkerSalary() const;

        void setWorkerSalary( int Salary);

        Manager(const Manager& manger) ;

        Manager& operator=(const Manager& );

        bool hasWorker(unsigned int);

         ~Manager() override =default;
        // std::ostream printShort(std::ostream &os) const override;

        // std::ostream printLong(std::ostream &os) const override;

    };

}
#endif //MANAGER_H
