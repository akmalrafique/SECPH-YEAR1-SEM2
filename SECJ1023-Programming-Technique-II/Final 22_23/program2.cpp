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
    int numVehicles;
    Vehicle* vehicle[5];//array of vehicle pointer stated by the question
    public:
    Garage(){
        numVehicles=0;
    }
    void addVehicle(Vehicle* v){
        if(numVehicles>=5){
            throw runtime_error("the maximum number of vehicles has been reached!!");
        }
        vehicle[numVehicles++]=v;
    }

    void displayInfo(){
        cout<<"***** Garage details*****"<<endl;
        for(int i =0;i<numVehicles;++i){
            cout<<i+1<<".";
            vehicle[i]->displayDetails();
            //Since displayDetails() is virtual in Vehicle,C++ checks the actual object, not just the pointer type.
            //ex vehicle[0] is a car object,so it call the car displayDetails()            
        }
    }
};

int main(){
    Garage myGarage;
    try{
        myGarage.addVehicle(new Car("Toyota",2015,4));
        myGarage.addVehicle(new Car("BMW", 2019, 2));
        myGarage.addVehicle(new Motorcycle("Honda", 2020, "Sport"));
        myGarage.addVehicle(new Car("Nissan", 2018, 5));
        myGarage.addVehicle(new Motorcycle("Harley-Davidson", 2017, "Cruiser"));

        myGarage.displayInfo();
    }
    catch(const runtime_error& e){
        cout << "An error occurred: "<<e.what()<<endl;
    }
    return 0;
}