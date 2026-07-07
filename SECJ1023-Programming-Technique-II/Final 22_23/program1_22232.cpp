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
    //this vector scores adress instead of object
    //courses is a vector that stores Course pointers.
    //this acts as a personal list,to keep track of only the course that specific student has enrolled in
    //each student ahve diffrent list
    

public:
    Student(string _name = "", string _matric = "") : name(_name), matric(_matric) {}
    string getName() const { return name; }
    void setName(string value) { name = value; }
    void setMatric(string value) { matric = value; } 
    string getMatric() const { return matric; }//tmbah sendiri ke?
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
    vector<Course*> courses;
    //this is like a database
    //this hold every courses the uni offer,this is used to grab the course to enrol a student
    courses.push_back(new Course("Programming Technique I",3));//course 1
    //this create a new Course object in memory
    // "new" return the memory adress of the object
    //without new, the object exxist only until it goes out of scope
    //so basically this create an object first, but because of the vector use pointer instead of object,it will only accept ADRESS 
    //then later the new is the reason this object become memory adress and does not dissapear when it goes out of scope, then this memory
    // adress is store at the vector
    courses.push_back(new Course("Programming Technique II", 3));     // Course 2
    courses.push_back(new Course("Operating Systems", 3));            // Course 3
    courses.push_back(new Course("Web Programming", 3));              // Course 4
    courses.push_back(new Course("Digital Logic", 3));                // Course 5
    courses.push_back(new Course("Object-Oriented Programming", 4));  // Course 6
    courses.push_back(new Course("Application Development", 4));      // Course 7
    courses.push_back(new Course("Final Year Project I", 2));         // Course 8
    courses.push_back(new Course("Software Engineering", 3));         // Course 9
    courses.push_back(new Course("Graduate Success Attributes", 2));  // Course 10



    //! Task6: create the list of students using map and enroll the student to the courses.
    map<string,Student*>studentMap;
    //creating a map callep studentMap
    //string is the key(matric unmber)
    //student* is the value(actual student object)
    //telling the computer when give matric nunmber, give back the full student information

    Student* s1= new Student("Mario Max","A16EC4041");
    //new Student create student object in heap,new return the adress adn stores insisde Student* s1
    Student* s5=new Student("Anna Mull","A19EC4002");
    Student* s10 = new Student("Jimmy Changa", "A18EC4044");
    Student* s2 = new Student("Wilma Mumduya", "A16EC4045"); //this is the student from example   

    studentMap[s1->getMatric()] =s1;
    //"Take matric number (...) as the key, and store the pointer to (...) Student object as the value in the map."
    studentMap[s5->getMatric()]=s5;
    studentMap[s10->getMatric()]=s10;
    studentMap[s2->getMatric()] = s2;

    //enroll student to course based on the given file
    s1->enrollToCourse(courses[0]);//programing tech 1
    //courses[0] is the vector that we used to store course info
    s1->enrollToCourse(courses[4]); // Digital Logic
    //course[4] IS A ADRESS SO NO NEED "&"
    s1->enrollToCourse(courses[9]); // Grad Success Attr
    s1->enrollToCourse(courses[0]); // Duplicate as per example


    s5->enrollToCourse(courses[1]); // Prog Tech II
    s5->enrollToCourse(courses[2]); // Operating Sys
    s5->enrollToCourse(courses[4]); // Digital Logic
    s5->enrollToCourse(courses[3]); // Web Prog
    s5->enrollToCourse(courses[8]); // Software Eng

    s10->enrollToCourse(courses[3]); // Web Prog
    s10->enrollToCourse(courses[5]); // OOP
    s10->enrollToCourse(courses[6]); // App Dev
    s10->enrollToCourse(courses[7]); // FYP I
    s10->enrollToCourse(courses[1]); // Prog Tech II
    //! Task7: Search for a student and display its information
    string inputMatric;
    cout<<"enter the matric number=> ";
    cin>> inputMatric;
    //inputMatric check to see if input a "key" or not
    if(studentMap.count(inputMatric)){
        //count() check wheteher a key exist inside the map (1-key exist ,0-not exist)
        cout<<"information of found student"<<endl;
        cout<"============================="<<endl;
        studentMap[inputMatric]->printSummary();
        //studentMap[inputMatric] return student pointer like(anna maybe) then -> go to the object
    }

    system("pause"); //! remove this line if you are using DevC++
    return 0;
}