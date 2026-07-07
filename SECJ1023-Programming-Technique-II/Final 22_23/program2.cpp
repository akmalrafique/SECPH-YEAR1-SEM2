#include<iostream>
using namespace std;

class Vehicle{
    protected:
    string brand;
    int year;
    public:
    Vehicle(string b,int y):brand(b),year(y){}
    virtual void displayDetails(){}
    virtual double calculateTax()=0;
};
class Motorcycle:public Vehicle{
    private:
    string type;
    public:
    Motorcycle(string b,int y,string t):s



};