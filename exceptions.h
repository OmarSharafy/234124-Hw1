//
// Created by 97250 on 27/12/2021.
//

#ifndef UNTITLED2_EXCEPTIONS_H
#define UNTITLED2_EXCEPTIONS_H
#include <stdexcept>
namespace mtm{
    class Exception: public std::exception{} ;


    /* *********Skills Exceptions************** */

    /* in case we added negative points skills to the employee */
    class NegativePoints : public Exception{};


    /* *********Employee Exceptions************** */

    /* in case the skill we wanted to add is already learned by the employee */
    class SkillAlreadyLearned : public Exception{};
    /* in case the skill we wanted to add cannot be learned by employee */
    class CanNotLearnSkill : public Exception{};
    /* in case the employee has not learned the skill */
    class DidNotLearnSkill : public Exception{};


    /* *********Manager Exceptions************** */

    /* in case the employee we wanted to hire is already hired */
    class EmployeeAlreadyHired : public Exception{};
    /* in case the employee is not hired, so we can't do anything with him */
    class EmployeeIsNotHired : public Exception{};

    
    /* *********Workplace Exceptions************** */

    /* in case the employee is not selected to do things with */
    class EmployeeNotSelected : public Exception{};
    /* in case the manager is not hired, so we can't do anything with him */
    class ManagerIsNotHired : public Exception{};
    /* in case the manager we want to add can't be hired  */
    class CanNotHireManager : public Exception{};
    /* in case the manager we wanted to hire is already hired */
    class ManagerAlreadyHired : public Exception{};


    /* *********Faculty Exceptions************** */

    /* in case the employee is not accepted to do things with */
    class EmployeeNotAccepted : public Exception{};

    
    /* *********City Exceptions************** */

    /* in case the citizen is already exists, and we can't add him again  */
    class CitizenAlreadyExists :public Exception{};
    /* in case the faculty is not existed to do things with  */
    class FacultyDoesNotExist : public Exception{};
    /* in case the faculty is already exists, and we can't add it again  */
    class FacultyAlreadyExists: public Exception{};
    /* in case the workplace is already exists, and we can't add it again  */
    class WorkplaceAlreadyExists : public Exception{};
    /* in case the workplace is not existed to do things with  */
    class WorkplaceDoesNotExist : public Exception{};
    /* in case the employee is not existed to do things with  */
    class EmployeeDoesNotExist : public Exception{};
    /* in case the manager is not existed to do things with  */
    class ManagerDoesNotExist : public Exception{};


}
#endif //UNTITLED2_EXCEPTIONS_H
