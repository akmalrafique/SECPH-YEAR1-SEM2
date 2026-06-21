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
    virtual void input();
    virtual void display();
    virtual int readUserInput();
};








































    system("pause"); 
    return 0;
}