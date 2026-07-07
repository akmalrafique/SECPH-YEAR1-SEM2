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
    //courses is a vector that stores Course pointers.

public:
    Student(string _name = "", string _matric = "") : name(_name), matric(_matric) {}
    string getName() const { return name; }
    void setName(string value) { name = value; }
    void setMatric(string value) { matric = value; }

    //! Task 1
    void enrollToCourse(Course *c) {
        courses.push_back(c);
        //push_back means add an item at the the end of the vector
    }

    //! Task 2
    int getEnrolledCount() const {
        return courses.size();
        //size() Returns the size or the number of elements
    }

    //! Task 3
    int getTotalCredit() const {
        int total = 0;
        for(size_t i=0;i<courses.size();++i){
            //size_t is unsign integer,can also use int but it will trigger a warning
            total+=courses[i]->getCredit();
        }
        return total;
    }

    //! Task 4
    void printCourses() const {
        for(int i=0;i<courses.size();++i){
            courses[i]->print();
        }
    }
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