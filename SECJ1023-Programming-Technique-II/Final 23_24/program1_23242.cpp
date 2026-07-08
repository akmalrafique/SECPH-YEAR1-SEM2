// Programming Technique II (SECSJ1023)
// Semester 2, 2023/2024

// Final Exam (Practical - Question 1)

// Student's Name:.....................
// Matric Number:.....................


#include <iostream>
#include <string>
using namespace std;

class Department
{
private:
    string name;
    string faculty;

public:
    Department() { name = faculty = ""; }
 
    string getName() const { return name; }
    void setName(string n) { name = n; }
    string getFaculty() const { return faculty; }
    void setFaculty(string f) { faculty = f; }
};


class Person
{
protected:
    string name;
    Department department;
public:
    string getName() const { return name; }
 
    // ! Task d(i) - constructor
    Person(string n="", string d="", string f=""):name(n){
        department.setName(d);
        department.setFaculty(f);
    }
    //! Task d(ii) - getDepartment
    Department getDepartment()const{

        return department;
    }
};


class Lecturer:public Person
{
private:
    string position;

public:

    string getPosition() const { return position; }


    // ! Task e(i) - constructor
    Lecturer(string n, string d, string f, string p):Person(n,d,f){
        position=p;
    }
    // ! Task e(ii) - getFaculty
    string getFaculty(){

        return getDepartment().getFaculty();
    }
};


class Course
{
private:
    string code;
    Lecturer* lecturer;


public:
    void setCode(string c) { code = c; }
    string getCode() const { return code; }

    // ! Task f(i) - constructor
    Course(string c="") {}

    // ! Task f(ii) - setLecturer
    

    // ! Task f(iii) - hasLecturer
    


    // ! Task f(iv) - getLecturerName
};


class TeachingAssistant:public Person
{
protected:
    int maxHour;
    Course* course;

public:
    double getMaxClaim() const { return maxHour * 8.0; }

    TeachingAssistant(string n) {
    	name=n;
        maxHour=80 ;
    }
};


string courseCodeToName(string code);


int main()
{
    //!Task g: rewrite the main function using vector instead of regular array, including iteration
    const int count=4;
    Course courses[count];

    courses[0].setCode("SECJ1013");
    courses[1].setCode("SECJ1023");
    courses[2].setCode("SECJ3623");
    courses[3].setCode("SECV3032");

    for (int i = 0; i < count; i++)
        cout << courses[i].getCode() << " " << courseCodeToName(courses[i].getCode()) << endl;

    system("pause"); //! remove this line if you are using DevC++
    return 0;
};


//!Task h: rewrite the method using map
string courseCodeToName(string code)
{

    if (code == "SECJ1013")
        return "Programming Technique I";
 
    if (code == "SECJ1023")
        return "Programming Technique II";
 
    if (code == "SECJ3623")
        return "Mobile Application Programming";
 
    return "";
}