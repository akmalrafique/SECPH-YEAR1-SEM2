#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//? class Course is fully given
class Course
{
private:
    string name;
    int credit;

public:
    Course(string _name = "", int _credit = 1) : name(_name), credit(_credit) {}
    string getName() const { return name; }
    void setName(string value) { name = value; }
    int getCredit() const { return credit; }
    void setCredit(int value) { credit = value; }
    void print() const
    {
        cout << "Course: " << name << "   Credit=" << credit << endl;
    }
};

//? the class Student is partially given
class Student
{
private:
    string name, matric;
    vector<Course *> courses;

public:
    Student(string _name = "", string _matric = "") : name(_name), matric(_matric) {}
    string getName() const { return name; }
    void setName(string value) { name = value; }
    void setMatric(string value) { matric = value; }

    //! Task 1
    void enrollToCourse(Course *c) {}

    //! Task 2
    int getEnrolledCount() const {}

    //! Task 3
    int getTotalCredit() const {}

    //! Task 4
    void printCourses() const {}
    void printSummary() const
    {
        cout << "Name:" << name << endl;
        cout << "Matric:" << matric << matric << endl;
        cout << "Number of courses enrolled:" << getEnrolledCount() << endl;
        cout << "Total credit carried:" << getTotalCredit() << endl;
    }
};

int main()
{
    //! Task 5: create list of courses using vector


    //! Task6: create the list of students using map and enroll the student to the courses.

    //! Task7: Search for a student and display its information


    system("pause"); //! remove this line if you are using DevC++
    return 0;
}