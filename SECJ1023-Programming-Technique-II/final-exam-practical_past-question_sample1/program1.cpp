// Programming Technique II (SECSJ1023)
// Semester 2, 2021/2022

// Final Exam (Practical - Question 1)

// Student's Name:.....................
// Matric Number:.....................
// Location:..................... (e.g. area and state name if in malaysia, or country name if outside Malaysia)

#include <iostream>
#include <string>
using namespace std;

class Owner {
  private:
    string name;
    string mobileNumber;

  public:
    Owner();
    string getName() const;
    void setName(string name);
    string getMobileNumber() const;
    void setMobileNumber(string mobile);
};

class Car {
  private:
    string plateNumber;
    string model;

  public:
    Car();
    string getPlateNumber() const;
    void setPlateNumber(string);
    string getModel() const;
    void setModel(string);
};

class CarForSale : public Car {
  private:
    double price;

  public:
    CarForSale();
    double getPrice() const;
    void setPrice(double _price);
    string getOwnerName() const;
};

class CarForRent : public Car {
  private:
    double rentalRate;
    Owner *carOwner;

  public:
    CarForRent();
    double getRentalRate() const;
    void setRentalRate(double _rate);
    void setCarOwner(Owner *owner);
    string getOwnerMobileNumber() const;
};

int main() {
    return 0;
}

//--------------------------------------------------------------------------------------------
// Definition of the class Owner

Owner::Owner() { name = mobileNumber = ""; }

string Owner::getName() const { return name; }

void Owner::setName(string value) { name = value; }

string Owner::getMobileNumber() const { return mobileNumber; }

void Owner::setMobileNumber(string mobile) { mobileNumber = mobile; }

//--------------------------------------------------------------------------------------------
// Definition of the class Car

Car::Car() { plateNumber = model = ""; }

string Car::getPlateNumber() const { return plateNumber; }

void Car::setPlateNumber(string value) { plateNumber = value; }

string Car::getModel() const { return model; }

void Car::setModel(string value) { model = value; }

//--------------------------------------------------------------------------------------------
// Definition of the class CarForSale

CarForSale::CarForSale() : Car() { price = 0; }

double CarForSale::getPrice() const { return price; }

void CarForSale::setPrice(double value) { price = value; }

string CarForSale::getOwnerName() const {
    //! This is part of the question
}

//--------------------------------------------------------------------------------------------
// Definition of the class CarForRent

CarForRent::CarForRent(): Car() {
    rentalRate = 0.0;
    carOwner = nullptr;
}

double CarForRent::getRentalRate() const { return rentalRate; }

void CarForRent::setRentalRate(double value) { rentalRate = value; }

void CarForRent::setCarOwner(Owner *value) { carOwner = value; }

string CarForRent::getOwnerMobileNumber() const {
    //! This is part of the question
    if (carOwner == nullptr) return "";  //4 marks
    return carOwner->getMobileNumber();  // 3 marks
}
