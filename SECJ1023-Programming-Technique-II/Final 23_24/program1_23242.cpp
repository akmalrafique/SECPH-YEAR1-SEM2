// Programming Technique II (SECSJ1023)
// Semester 2, 2023/2024

// Final Exam (Practical - Question 1)

// Student's Name:AKMAL RAFIQUE BIN AHMAD RAPHAIE
// Matric Number:.....................


#include <iostream>
#include <string>
#include<vector>
#include<map>
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
    Course(string c="") {
        code=c;
        lecturer=nullptr;
    }

    // ! Task f(ii) - setLecturer
    void setLecturer(Lecturer* lect){
        lecturer=lect;
    }

    // ! Task f(iii) - hasLecturer

    bool hasLecturer()const{

        return lecturer!=nullptr;
    }


    // ! Task f(iv) - getLecturerName
    string getLecturername(){
        if(hasLecturer()){
        return lecturer->getName();//so we have lecturer pointer here,and lecturer also
        //inherit from person so it can access it.
        }
        return "";
        //this if statement is important because if lecturer object is empty or nullptr
        //(the lecturer->getName() will derefference a null pointer which cause crash)
    }
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
    /*Course courses[count];

    courses[0].setCode("SECJ1013");
    courses[1].setCode("SECJ1023");
    courses[2].setCode("SECJ3623");
    courses[3].setCode("SECV3032");*/
    vector <Course> courses;
    courses.push_back(Course("SECJ1013"));
    //push_back() only accept  object and Course("SECJ1013") is an object
    courses.push_back(Course("SECJ1023"));
    courses.push_back(Course("SECJ3623"));
    courses.push_back(Course("SECV3032"));

    for (int i = 0; i < courses.size(); i++)
        cout << courses[i].getCode() << " " << courseCodeToName(courses[i].getCode()) << endl;
//courses[i].getCode() need tht getcode() becuse courses[i] is an object 
    system("pause"); //! remove this line if you are using DevC++
    return 0;
};


//!Task h: rewrite the method using map
string courseCodeToName(string code)
{

/*
    if (code == "SECJ1013")
        return "Programming Technique I";
 
    if (code == "SECJ1023")
        return "Programming Technique II";
 
    if (code == "SECJ3623")
        return "Mobile Application Programming";
 
    return "";*/
    map <string,string> courseMap;
    courseMap["SECJ1013"]="PROGRAMMING TECHNIQUE 1";
    courseMap["SECJ1023"]="PROGRAMMING TECHNIQUE 2";
    courseMap["SECJ3623"]="MOBILE APPLICATION PROGRAMMING";

    return courseMap[code];
    //return the subject name based on the given code that function accept
}