// ? EXERCISE 1: INTRODUCTION TO CLASSES AND OBJECTS

// Programming Technique II

// Member 1's Name: Akmal Rafique bin Ahmad Raphaie
// Member 2's Name: Muhammad Najmi Shahmi Bin Mohd Latpi
//
// Section: ___
// Member 1's Name: Akmal Rafique bin Ahmad Raphaie    Location: KTR K11 (i.e. where are you currently located)
// Member 2's Name: Muhammad Najmi Shahmi Bin Mohd Latpi   Location: KTR,K11

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  18/4/26    7:09             7:40          31
//  18/4/26_    7:09            7:40          31

// Video link:
//   https://drive.google.com/file/d/103ObAJMG7Mv_sRGkIrB20dxEY7ASxzw5/view?usp=sharing


#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

class Subject {
    private:
    string name;
    string code;
    double score;

    public:
    Subject() {
        name = "";
        code = "";
        score = 0.0;
    }
    Subject(string newName, string newCode, double newScore){
        name = newName;
        code = newCode;
        score = newScore;
    }
    ~Subject() {}

	void setName(string newName) {name = newName;}
	string getName() const {return name;}

	void setCode(string newCode) { code = newCode;}
	string getCode() const { return code;}

	void setScore(double newScore) { score = newScore;}
	double getScore() const {return score;}

	string getGrade() const {
		if (score >= 90) return "A+";
		if (score >= 80) return "A";
		if (score >= 75) return "A-";
		if (score >= 70) return "B+";
		if (score >= 65) return "B";
		if (score >= 60) return "B-";
		if (score >= 55) return "C+";
		if (score >= 50) return "C";
		if (score >= 45) return "C-";
		if (score >= 40) return "D+";
		if (score >= 35) return "D";
		if (score >= 30) return "D-";
		return "E";

	}
	 double getPointValue () const {
		if (score >= 80) return 4.00;
		if (score >= 75) return 3.67;
		if (score >= 70) return 3.33;
		if (score >= 65) return 3.00;
		if (score >= 60) return 2.67;
		if (score >= 55) return 2.33;
		if (score >= 50) return 2.00;
		if (score >= 45) return 1.67;
		if (score >= 40) return 1.33;
		if (score >= 35) return 1.00;
		if (score >= 30) return 0.67;
		return 0.00;
	 }

double getPointEarned() const {
    int creditHour = code.back() - '0';
    return getPointValue() * creditHour;
}

	
    
};
int main()
{
	Subject mySubject;
	string inputName, inputCode;
	double inputScore;

	cout << "Enter the following data: " << endl;
	cout << "  Subject name => ";
	getline(cin, inputName);
	mySubject.setName(inputName);
	cout << endl;

	cout << "  Subject code => ";
	cin >> inputCode;
	mySubject.setCode(inputCode);
	cout << endl;

	cout << "  Score earned => ";
	cin >> inputScore;
	mySubject.setScore(inputScore);
	cout << endl;

	cout << endl
		 << endl;

	cout << "THE RESULT" << endl
		 << endl;

	cout << "Subject Code : "<<mySubject.getCode() << endl;
	cout << "Subject Name : "<<mySubject.getName() << endl;
    int creditHour = mySubject.getCode().back()- '0';

	cout << "Credit Hour  : "<<creditHour << endl;
	cout << "Score Earned : " <<mySubject.getScore()<< endl;
	cout << "Grade Earned : " <<mySubject.getGrade()<< endl;
    cout<<fixed<<setprecision(2);

	cout << "Grade Point  : "<< mySubject.getPointValue() << endl;
	cout << "Point Earned : " << (int)mySubject.getPointEarned()<< endl;
	cout << endl;

	system("pause");

	return 0;
}
