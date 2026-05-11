#include<iostream>

class Student{
    private:
    string name;
    string matric;
    double gpa;
    double cgpa;
    int cred;
    int ccred;
    string conf;
    public:
    Student( string n = "", string mn= "",double CGPA = 0,int c = 0){
        name =n;
        matric=mn;
        cgpa=CGPA;
        ccred=c;
        gpa=0.0;
        cred=0;
        updateCGPA();
    }
    string getName()const{
        return name;
        }
    string getStatus()const{
        if(cgpa<1.7){
            return "Fail Status";
        }
        if(cgpa>1.7 && cgpa <2.0){
            return "Probation Status";
        }
        else
        return "Good Status";
    }
    void updateCGPA(double cg){
        cgpa=((gpa*cred)+(cg*ccred))/(cred+ccred);
    }
    void readInput(){
        cout<<"Name:";
        cin>>name;
        cout<<"Matric Number:";
        cin>>matric;
        cout<<"CGPA:";
        cin>>cgpa;
        cout<<"Total Credit:";
        cin>>ccred;
        cout<<"GPA:";
        cin>>gpa;
        cout<<"Credit earned this semester:";
        cin>>cred;
        updateCGPA(cgpa);
    }
    bool operator==(const Student& right)const{
        return(this->getStatus()==right.getStatus());
    }
    friend void dispInfo();
};

void dispInfo(){
    cout<<"Hello, "<<p1.name<<endl;
    cout<<"You are in year "<<    <<"in "<<
}
using namespace std;
int main(){

}
