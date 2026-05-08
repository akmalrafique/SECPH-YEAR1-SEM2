// ? EXERCISE 2: CLASS AND OBJECT MANIPULATIONS

/// Programming Technique II

// Member 1's Name: _____________
// Member 2's Name: _____________
//
// Section: ___
// Member 1's Name: _____________    Location: ____________ (i.e. where are you currently located)
// Member 2's Name: _____________    Location: ____________

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________

// Video link:
//   _________

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_SUBJECT_COUNT 10

class Subject
{
private:
	string name;
	string code;
	int score;

public:
	Subject();
	int credit() const;
	string grade() const;
	double point() const;
	void print() const;
	friend int readUserInput(Subject subjects[]);

};

int main()
{
	int num;
	cout << "how many subject do you want to enter";
	cin>>num;
	for(int i=0;i<num;i++){

	}
	Subject subjects[]
	cout << endl
		 << endl
		 << "THE RESULT"
		 << endl
		 << endl;

	// Print the output table header
	cout << left << setw(15) << "Subject Code";
	cout << left << setw(30) << "Subject Name";
	cout << left << setw(10) << "Credit";
	cout << left << setw(10) << "Score";
	cout << left << setw(10) << "Grade";
	cout << left << setw(10) << "Point";
	cout << left << setw(10) << "Sub Total";
	cout << endl
		 << endl;

	cout << endl;
	cout << "TOTAL POINT  : " << endl;
	cout << "TOTAL CREDIT : " << endl;
	cout << "GPA          : " << setprecision(3) << endl;

	cout << endl;
	cout << "LOWEST SUBJECT : " << endl;
	cout << endl;

	system("pause");

	return 0;
}

// The definition of the default constructor is fully given
Subject::Subject() : name(""), code(""), score(0) {}

// The definition of the getter for the 'credit()' is fully given
int Subject::credit() const { return code[7] - '0'; }

// The definition of the getter for the 'grade()' is fully given
string Subject::grade() const
{
	if (score >= 90)
		return "A+";
	if (score >= 80)
		return "A";
	if (score >= 75)
		return "A-";
	if (score >= 70)
		return "B+";
	if (score >= 65)
		return "B";
	if (score >= 60)
		return "B-";
	if (score >= 55)
		return "C+";
	if (score >= 50)
		return "C";
	if (score >= 45)
		return "C-";
	if (score >= 40)
		return "D+";
	if (score >= 35)
		return "D";
	if (score >= 30)
		return "D-";
	return "E";
}
// Define a regular function that read a list of subjects from user input
int readUserInput(Subject subjects[])
{
}

// Define a regular function that determines the lower subject.
Subject lower(Subject a, Subject b)
{
}
	double Subject::point() const{
		string grade = grade();
		if(grade== "A+")
		return 4.0;
		if(grade=="A")
		return 4.0;
		if(grade=="A-")
		return 3.67;
		if(grade=="B+")
		return 3.33;
		if(grade=="B")
		return 3.0;
		if(grade=="B-")
		return 2.67;
		if(grade=="C+")
		return 2.33;
		if(grade=="C")
		return 2.0;
		if(grade=="C-")
		return 1.67;
		if(grade=="D+")
		return 1.33;
		if(grade=="D")
		return 1.0;
		if(grade=="D-")
		return 0.67;
		if(grade=="E")
		return 0.0;
	}
	void Subject:: print( ) const{
		int cred = credit();
		double point = point();
		string grade = grade();
		double tt = cred*point;
		cout << left << setw(15) << code;
		cout << left << setw(30) << name;
		cout << left << setw(10) << cred;
		cout << left << setw(10) << score;
		cout << left << setw(10) << grade;
		cout << left << setw(10) << point;
		cout << left << setw(10) << tt;
		cout << endl;
	}

