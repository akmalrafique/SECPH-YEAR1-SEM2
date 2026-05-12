#include<iostream>
#include<string>
using namespace std;
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
    void updateCGPA(){
        cgpa=((gpa*cred)+(cgpa*ccred))/(cred+ccred);
    }
    void readInput(){
        cout<<"Name:";
        cin.ignore();
        getline(cin,name);
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
        updateCGPA();
    }
    bool operator==(const Student& right)const{
        return(this->getStatus()==right.getStatus());
    }
    friend void dispInfo(const Student &temp);
    friend ostream& operator<<(ostream& output,const Student& right);
};

void dispInfo(const Student &temp){
int year;
string program;
if(temp.matric.substr(1,2)=="16"){
    year=4;
}
if(temp.matric.substr(1,2)=="17"){
    year=3;
}
if(temp.matric.substr(1,2)=="18"){
    year=2;
}
if(temp.matric.substr(1,2)=="19"){
    year=1;
}
if(temp.matric.substr(3,2)=="CS"){
    program="Computer Science";
}
else if(temp.matric.substr(3,2)=="EC"){
    program="Engineering Computing";
}
else
program="Non Computing Program ";
cout<<"You are in year "<<year<<"in "<<program<<endl;
}
ostream& operator<<(ostream& output,const Student& right){
    output<<"Hello "<<right.name<<endl;
    dispInfo(right);
    output<<"Your matric number is "<<right.matric<<endl;
    output<<"Your current CGPA is"<<right.cgpa<<endl;
    output<<"Your status is "<<right.getStatus()<<endl;
    if(right.cgpa>=3.67){
        output<<"CONGRATULATIONS. You are awarded DEANs LIST"<<endl;
    }
    return output;
}
int main(){
    Student p1,p2("Hashim Abu","A17CS1234",4.0,18);
    p1.readInput();
    cout<<p1;
    cout<<p2;
    if(p1==p2){
        cout<<"**Note: "<<p1.getName()<<"and"<<p2.getName()<<" have "<<p1.getStatus()<<endl;
    }
    else{
        cout<<"**Note: "<<p1.getName()<<"and"<<p2.getName()<<" have different status."<<endl;
    }

}
