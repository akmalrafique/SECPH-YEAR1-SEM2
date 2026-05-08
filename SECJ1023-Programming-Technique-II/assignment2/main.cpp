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
	bool operator<(const Subject& lowsub)const;


};
Subject lower(Subject a, Subject b);
int main()
{
	double ttp = 0.0;
	int ttc =0;
	Subject subjects[MAX_SUBJECT_COUNT];
	int count = readUserInput(subjects);
	

	
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

	for(int i=0;i<count;i++){
		subjects[i].print();
		ttp += (subjects[i].credit()*subjects[i].point());
		ttc += subjects[i].credit();
	}
		

	cout << endl;
	cout << "TOTAL POINT  : " << ttp << endl;
	cout << "TOTAL CREDIT : " << ttc <<endl;
	cout << "GPA          : " << ttp/ttc << endl;

	cout << endl;
	Subject lowsub = subjects[0];
	for(int i=1;i<count;i++){
		lowsub = lower(lowsub,subjects[i]);
	};
	cout << "LOWEST SUBJECT : " << endl;
	lowsub.print();
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
	int num;
	cout << "How many subjects do you want to enter? =>";
	cin >>num;
	if(num>MAX_SUBJECT_COUNT){
		num=MAX_SUBJECT_COUNT;
	}
	for(int i=0;i<num;i++){
		cout<<"Enter info for subject #"<<i+1<<endl;
		cout<<"Subject code =>";
		cin>>subjects[i].code;
		cout<<"Subject name =>";
		cin.ignore();
		getline(cin,subjects[i].name);
		cout<<"Subject score =>";
		cin>>subjects[i].score;
	};
	return num;
}

// Define a regular function that determines the lower subject.
Subject lower(Subject a, Subject b)
{
	if(a<b){
		return a;
	}
	else return b;
}
	double Subject::point() const{
		string g = grade();
		if(g== "A+")
		return 4.0;
		if(g=="A")
		return 4.0;
		if(g=="A-")
		return 3.67;
		if(g=="B+")
		return 3.33;
		if(g=="B")
		return 3.0;
		if(g=="B-")
		return 2.67;
		if(g=="C+")
		return 2.33;
		if(g=="C")
		return 2.0;
		if(g=="C-")
		return 1.67;
		if(g=="D+")
		return 1.33;
		if(g=="D")
		return 1.0;
		if(g=="D-")
		return 0.67;
		else
		return 0.0;
	}
	void Subject:: print( ) const{
		int cred = credit();
		double p = point();
		string g = grade();
		double tt = cred*p;
		cout << left << setw(15) << code;
		cout << left << setw(30) << name;
		cout << left << setw(10) << cred;
		cout << left << setw(10) << score;
		cout << left << setw(10) << g;
		cout << left << setw(10) << p;
		cout << left << setw(10) << tt;
		cout << endl;
	}
	bool Subject::operator<(const Subject& lowsub)const{
		return score<lowsub.score;
	}



