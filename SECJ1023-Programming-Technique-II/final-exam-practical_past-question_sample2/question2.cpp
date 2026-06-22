

// a)i) Student and Address-> indirect composition,students inherits from Person class,person class has composition relationship with adress
//indicates with solid black diamond.because student "is a" person,the student inherently own an Adress whose is strictly bound to it.
//ii)Student and Advisor->aggregation realtionship,student HAS AN advisor,inidcates by hollow diamond.its a weak relationship where
//advisor can exist independantly even if object student is destroyed
//iii)Advisor and Person->the relationship is inheritance(generalization).indicated by the open triangle arrow pointing from Advisor to the Person base class.
//advisor "is a "specific type of person which inherits its attribute and method.
//b) Yes, structurally, an advisor can conceptually have more than one student under them.
//Justification: In an aggregation relationship, multiple Student objects can contain a pointer or reference to the exact same Advisor object. However,
//it is important to note that based on this specific UML diagram, the Advisor class itself does not contain a list or array to track those students internally.
//c)No, it is not possible to properly define an Advisor::getStudent() method without modifying the current design.
//Justification: The diagram illustrates a unidirectional association from Student to Advisor. The Advisor class lacks any attribute 
//(such as an array or a vector of pointers) that links back to the Student objects. To make this possible, a bidirectional relationship
// would need to be established in the UML.it should have like
// UML Attribute Notation: * - studentList: Student*[MAX] and  - studentCount: int orrrr  Student* student;
//
//
//
//
#include<iostream>
using namespace std;

class Address{
    private:
    string city;
    public:
    Address(string c = " "):city(c){}
    void setCity(string c){
        city=c;
    }
    string getCity(){
        return city;
    }

};
class Person{
    private:
    string name;
    public:
    Person(){}
    getName(){}
    getAddress(){}


};
class Student : public Person{
    private:
    string program;
    public:
    Student(){}
    setAdvisor(){}
    getAdvisor(){}
    getCity(){}
    getAdvisorName(){}
    getAdvisorCity(){}



};
class Advisor : public Person{
    private:
    string faculty;
    public:
    Advisor(){}
    getFaculty(){}
};