// Programming Technique II (SECSJ1023)
// Semester 2, 2021/2022

// Final Exam (Practical - Question 2)

// Student's Name:AKMAL RAFIQUE BIN AHMAD RAPHAIE
// Matric Number:A25CS0181
// Location:K11 KTR

/*  PROVIDED SAMPLE
#include <iostream>
using namespace std;

#define PI 3.14
#define CUBOID 1
#define SPHERE 2

class ThreeDimensionalObject {
  private:
    double width, length, height; // attributes for cuboid
    double radius;                // attribute for sphere

  public:
    double cuboidVolume() const { return width * length * height; }
    double sphereVolume() const { return (4.0 / 3.0) * PI * radius * radius * radius; }

    void inputCuboid() {
        cout << "Enter the dimensions, width, length and height => ";
        cin >> width >> length >> height;
    }

    void inputSphere() {
        cout << "Enter the radius => ";
        cin >> radius;
    }

    void displayCuboid() const {
        cout << endl << "Cuboid dimensions: " << width << " x " << length << " x " << height << endl;
    }

    void displaySphere() const {
        cout << endl << "Sphere's radius: " << radius << endl;
    }
};

int readUserInput() {
    int input;
    cout << "Enter the type of object 1: Cuboid, 2: Sphere => ";
    cin >> input;
    return input;
}

int main() {
    // Testing the class
    ThreeDimensionalObject object;
    int objectType;
    objectType = readUserInput();

    if (objectType == CUBOID) {
        object.inputCuboid();
        object.displayCuboid();
        cout << "Volume: " << object.cuboidVolume() << endl;
    }
    else if (objectType == SPHERE) {
        object.inputSphere();
        object.displaySphere();
        cout << "Volume: " << object.sphereVolume() << endl;
    }
    else {
        cout << endl << "Invalid input" << endl;
    }

    system("pause"); 
    return 0;
}
*/
#include <iostream>
using namespace std;

#define PI 3.14
#define CUBOID 1
#define SPHERE 2

class ThreeDimensionalObject {
    public:
    virtual void input() =0;
    virtual void display() =0;
    virtual double volume() =0;
    ~virtual ThreeDimensionalObject();
};

class Cuboid : public ThreeDimensionalObject {
    private:
    double width, length, height;
    public:
    void input () override{
        cout << "Enter the dimensions, width, length and height => ";
        cin >> width >> length >> height;
    }
    void display () override{
        cout << endl << "Cuboid dimensions: " << width << " x " << length << " x " << height << endl;
    }
    double volume () override{
        return width * length * height;
    } 
};
class Sphere : public ThreeDimensionalObject{
    private:
    double radius;
    public:
    void input () override{
        cout << "Enter the radius => ";
        cin >> radius;
    }
    void display () override{
        cout << endl << "Sphere's radius: " << radius << endl;
    }
    double volume () const override {
        return (4.0 / 3.0) * PI * radius * radius * radius;
    }
};
int main(){
    ThreeDimensionalObject* obj = nullptr;
    int input;
    cout << "Enter the type of object 1: Cuboid, 2: Sphere => ";
    cin >> input;    
    if(input==CUBOID){
        obj = new Cuboid();
        obj->input();
        obj->display();
        cout << "Volume: "obj->volume();
    }
    else if(input==SPHERE){
        obj = new Sphere();
        obj->input();
        obj->display();
        cout << "Volume: "obj->volume();

    }
    else{
        cout << endl << "Invalid input" << endl;
    }


    system("pause");
    return 0;
}




































