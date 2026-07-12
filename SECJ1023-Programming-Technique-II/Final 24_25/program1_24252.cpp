// NAME: AKMAL RAFIQUE BIN AHMAD RAPHAIE
// MATRIC NO.:A25CS0181
// SECTION:02

// SECJ1023 PROGRAMMING TECHNIQUE 2
// FINAL EXAM (PRACTICAL) 2024/2025-02
// QUESTION 1 (a-f)

/*
(a)(i)	Developer and Employee: 
Relationship: Inheritance

(a)(ii)	Manager and Team:
Relationship: no relationship

(a)(iii) Company and Employee: 
Relationship: composition

(a)(iv)	Team and Employee: 
Relationship: aggregation
*/

#include <iostream>
using namespace std;

// Base class - Partially given
class Employee {
public:
    // (b)(i) virtual void work() const
    virtual void work() const{
        cout<< "employee working";
    }
    // (b)(ii) virtual ~Employee()
    virtual ~Employee(){};

};

// Derived classes - Fully given
class Developer : public Employee {
public:
    void work() const {
        cout << "Developer writing code\n";
    }
};

// Derived classes - Fully given
class Manager : public Employee {
public:
    void work() const {
        cout << "Manager in meeting\n";
    }
};

// Company owns its employees (1:1 relationship) - Partially given
class Company {
private:
    Employee* employee;  
public:
    // (c)(i) Company(Employee *)
    Company(Employee* emp){
        employee= emp;
    }
    // (c)(ii) ~Company()
    ~Company(){delete employee;}

    // (c)(iii) void dailyOperation() const
    void dailyOperation() const{
        cout<<"company operation: ";
        employee->work();
    
    }

};

// Team uses employees - Partially given
class Team {
private:
    Employee* members[3];  // Fixed-size array
    int count = 0;
public:
    // (d)(i) void addMember(Employee *)
    void addMember(Employee* employ ){
        if(count<3){
            members[count++]=employ;
        }
    }
    // (d)(ii) void teamMeeting() const
    void teamMeeting()const{
        for(int i=0;i<count;i++){
            members[i]->work();
        }
    }
};

// main() - Partially given
int main() {

    // Relationship 1
    Employee* employees[2];
    employees[0] = new Developer();
    employees[1] = new Manager();

    for (int i = 0; i < 2; i++) {
        // (e)(i) invokes the work() function for each Employee in the array
        employees[i]->work();
    }

    // Relationship 2
    // (e)(ii) create Company object and pass the dynamically allocated Developer object
    Company cpn(new Developer());
    // (e)(ii) invokes the dailyOperation() function
    cpn.dailyOperation();

    // Relationship 3
    Team projectTeam;
    // (e)(iii) invoke the addMember() function and pass the dynamically allocated Developer object 
    projectTeam.addMember(new Developer());
    projectTeam.addMember(new Manager());
    projectTeam.teamMeeting();
    // (e)(iii) invoke the addMember() function and pass the dynamically allocated Manager object

    // (e)(iii) invoke the teamMeeting() function
    

    // destroy objects
    for (int i = 0; i < 2; i++) {
        delete employees[i];
    }

	system("pause"); //! remove this line if you are using DevC++
    return 0;
}

// (f) Ensure your program produces exactly the following output, without any compilation or runtime errors:
//			Developer writing code
//			Manager in meeting
//			Company operation: Developer writing code
//			Developer writing code
//			Manager in meeting