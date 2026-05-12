#include<iostream>
#define max 3
using namespace std;
class Name{
    private:
    string _firstname;
    string _lastname;
    public:
    Name(string firstname,string lastname):_firstname(firstname),_lastname(lastname){};
    friend ostream& operator<<(ostream& c,Name& n){

    }
};
class Student{
    private:
    Name _name;
    Course _course[max];
    public:
    Student(Name name,Course* course){};
    bool addCourse(Course* course){

    }
    string getRegisteredCourses(){
        string result="";
        for(int i=0;i<max;i++){
            if(_course[i].getCode()!=""){
                result+=_course[i].getName()+"\n";
            }
        }
        return result;
    }
    friend ostream& operator<<(ostream& output,Student& s){
        output<<s._name<<"Registered Courses: "<<s.getRegisteredCourses()

    }
};
class Course{
    private:
    string _code;
    string _name;
    public:
    Course(string code,string name){
        _code=code;
        _name=name;
    }
    string getCode(){
        return _code;


    }
    string getName(){
        return _name;

    }
};
int main(){
    Course course[5]={Course("0101","Cryptography"),Course("0234","Programming"),Course("1234","Calculus"),Course("2356","History"),Course("3658","Geography ")};
    Name name("Nassaie","Norris");
    Student student(name,0);
    cout<<student;
    course[0]=Course("0101","Cryptography");
    course[1]=Course("0234","Programming");
    
}