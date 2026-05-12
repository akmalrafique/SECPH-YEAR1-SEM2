/*
	SBT 2 sample answer
	Programming Technique 2
	Sem 2 - 2018/2019
*/
#include <iostream>
#include <string>
using namespace std;

#define MAX_COURSE_COUNT	3

class Name																							// 1 Mark  - Class declaration
{
	string _firstname;																				// 1 Mark  - Attribute declaration
	string _lastname;																				// 1 Mark  - Attribute declaration
public:
	Name(string firstname, string lastname) : _firstname(firstname), _lastname(lastname) {}			// 5 Marks  - Constructor prototype (3) + initialization (2)
	friend ostream& operator<< (ostream& o, Name& n)												// 5 Marks	- operator<< overloading (3)
	{
		o << n._firstname << " " << n._lastname;													//			   + name output (1)
		return o;																					//		       + return ostream (1)
	}
};

class Course																						// 1 Mark  - Class declaration
{
	string _code;																					// 1 Mark  - Attribute declaration
	string _name;																					// 1 Mark  - Attribute declaration
public:
	Course() : _code(""), _name("") {}																// 3 Marks  - Constructor prototype (1) + initialization (2)
	Course(string code, string name) : _code(code), _name(name) {}									// 5 Marks  - Constructor prototype (3) + initialization (2)
	string getCode() { return _code; }																// 2 Marks  - function declaration (1) + implementation (1)
	string getName() { return _name; }																// 2 Marks  - function declaration (1) + implementation (1)
};

class Student																						// 1 Mark  - Class declaration
{
	Name _name;																						// 1 Mark  - Attribute declaration
	Course _course[MAX_COURSE_COUNT];																// 1 Mark  - Attribute declaration
public:
	Student(Name name, Course* course) : _name(name)												// 5 Marks  - Constructor prototype (3) + initialization/implementation (2)
	{
		if (course != 0)
			_course[0] = *course;
	}
	bool addCourse(Course* course)																	// 6 Marks  - function declaration (1) 
	{
		if (course == 0) return false;																

		bool add_ok = false;
		for (int i = 0; i < MAX_COURSE_COUNT; i++)
		{
			if (_course[i].getCode() == course->getCode()) return false;							//			  + code not allowing existing subject (2)
			if (_course[i].getCode() == string(""))													//			  + code check if full/not full (1)
			{
				_course[i] = *course;																//			  + code to add subject (1)
				add_ok = true;
				break;
			}
		}

		return add_ok;																				//			  + return bool (1)
	}
	string getRegisteredCourses()																	// 5 Marks  - function declaration (1) 
	{
		string output = "";
		for (int i = 0; i < MAX_COURSE_COUNT; i++)
		{
			if (_course[i].getCode() != string(""))													//			  + code to get all subject (2)
			{
				output += _course[i].getName() + " ";
			}
		}
		if (output == string("")) output = "None";													//			  + code for None (1)
		return output;																				//			  + return string (1)
	}
	friend ostream& operator<< (ostream& o, Student& s)												// 3 Marks	- operator<< overloading
	{
		o << s._name << " registered courses: " << s.getRegisteredCourses();						// 1 Mark	- name output
		return o;																					// 1 Mark	- return ostream
	}
};

int main()
{
	Course available_courses[] = {	{ "0101", "Cryptography"},										// 5 Marks  - array/separate declaration of 5 subjects
									{ "0234", "Programming" },
									{ "1234", "Calculus" },
									{ "2356", "History" },
									{ "3658", "Geography" }	};

	Student s(Name("John", "Doe"), 0);																// 3 Marks  - student class, name initialization, null course
	cout << s << endl;																				// 1 Mark  - display student

	s.addCourse(&available_courses[0]);																// 1 Mark  - register course
	s.addCourse(&available_courses[1]);																// 1 Mark  - register course
	cout << s << endl;																				// 1 Mark  - display student

	if (s.addCourse(&available_courses[1]))															// 2 Marks  - register existing course(1) + check return value (1)
	{
		cout << "Registration successful" << endl;													// 1 Mark  - display success message
	}
	else
	{
		cout << "Registration failed" << endl;														// 1 Mark  - display failure message
	}

	s.addCourse(&available_courses[2]);																// 1 Mark  - register course
	cout << s << endl;																				// 1 Mark  - display student


	return 0;
}