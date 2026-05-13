#include<iostream>
#include<string>
#include<cstring>
#define currentyear 2020
using namespace std;
class Person{
    private:
    string name;
    string ic;
    double height;
    double weight;
    int act;
    double bmr;
    double calorie;
    public:
    Person(string n="",double h=0.0,double w=0.0,int al=0){
        name =n;
        height = h;
        weight =w;
        act=al;
    }
    string getName(){
        return name;
    }
    string getGender(){
        int x =stoi((ic.substr(11,1)));
        if(x%2==0){
            return "Female";
        }
            return "Male";
    }
    int getAge(){
        int birth,age;
        birth = stoi(ic.substr(0,2));
        if(birth<20){
            age=birth+2000;
        }
        else{
            age=birth+1900;
        }
        age=currentyear-age;
        return age;
    }
    void calcCalorie(string g,int a){
        if(g=="Male"){
            bmr=(weight*10)+(6.25*height)-(5*a)+5;
        }
        if(g=="Female"){
            bmr=(weight*10)+(6.25*height)-(5*a)-161;
        }
        if(act==1){
            calorie=bmr*1.2;
        }
        else if(act==2){
            calorie=bmr*1.375;

        }
        else if(act==3){
            calorie=bmr*1.55;

        }else if(act==4){
            calorie=bmr*1.725;

        }else if(act==5){
            calorie=bmr*1.9;

        }
    }
    void readInput(){
        cout<<"\nname:";
        getline(cin,name);
        cout<<"NRIC Number (without hyphen'-'):";
        cin>>ic;
        cout<<"Height (in meter):";
        cin>>height;
        cout<<"Weight (in kg):";
        cin>>weight;
        cout<<"Choose the activity level: 1-Sedentary, 2-Lightly Active, 3-Moderately Active, 4-Very Active, 5-Extra Active "<<endl;
        cout<<"Activity level (1 - 5):";
        cin>>act;
        string gender = getGender();
        int age = getAge();
        calcCalorie(gender,age);
        }
    bool operator==(const Person& right)const{

        return this->act==right.act;
    }
    friend void dispInfo();
    friend ostream& operator<<(ostream& output,const Person& right);
};

void dispInfo(Person s){
    cout<<"Your gender is "<<s.getGender()<<endl;
    cout<<"Your age is "<<s.getAge()<<" year old"<<endl;
}
ostream& operator<<(ostream& output,const Person& right){
    output<<"Hello, "<<right.name<<endl;
    dispInfo(right);
    output<<"your height is"<<right.height<<endl;
    output<<"Your weight is "<<right.weight<<endl;
    output<<"your bmr is "<<right.bmr<<endl;
    output<<"Your calorie based on activity level is "<<right.calorie<<"kcal/day"<<endl;
    return output;
}
int main(){
    Person p1,p2("alisha hashim",150,50,2);
    cout<<"Calorie Calculator \n<<< Input >>> ";
    p1.readInput();
    cout<<"<<<output>>>"<<endl;
    cout<<p1;
    if(p1==p2){
    cout<<p1.getName()<<"and "<<p2.getName()<<"have same activity level";
    }
    else{
        cout<<p1.getName()<<"and "<<p2.getName()<<"have diffrent activity level";
    }
}