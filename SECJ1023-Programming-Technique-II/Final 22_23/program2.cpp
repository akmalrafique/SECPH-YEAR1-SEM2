#include<iostream>
using namespace std;

class Vehicle{
    protected:
    string brand;
    int year;
    public:
    Vehicle(string b,int y):brand(b),year(y){}
    virtual void displayDetails(){
        cout<<"Brand: "<<brand<<endl;
        cout<<"Year: "<<year<<endl;
    }
    virtual double calculateTax()=0;
};
class Motorcycle:public Vehicle{
    private:
    string type;
    public:
    Motorcycle(string b,int y,string t):Vehicle(b,y){
        type = t;
    }
    void displayDetails(){
        cout<<"Motorcycle details:"<<endl;
        Vehicle::displayDetails();//this jump to the parent displaydetail() adn return back
        cout<<"Type: "<<type<<endl;
        cout<<"Tax : "<<calculateTax()<<endl;
    }
    double calculateTax(){
        return 50.0;
    }
};
class Car:public Vehicle{
    private:
    int numDoors;
    public:
    Car(string b,int y,int n):Vehicle(b,y){
        numDoors=n;
    }
    void displayDetails(){
        cout<<"Car details:"<<endl;
        Vehicle::displayDetails();
        cout<<"number of doors: "<<numDoors<<endl;
        cout<<"tax: "<<calculateTax()<<endl;
    }
    double calculateTax(){
        return 100+(numDoors*50);
    }
};
class Garage{
    private:
    int numVehicle;
    Vehicle* vehicle[5];
    public:
    Garage(){
    }
    void addVehicle(Vehicle* v){
        vehicle=v;
    }
    void displayInfo(){}
};