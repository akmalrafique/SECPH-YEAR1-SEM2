// Programming Technique II

//? EXERCISE 3: STRING MANIPULATIONS
//? file: custom_string.cpp

//!----------------------------------------------------------------------------------------
//! This is the only file that you will need to modify in this exercise.
//! And, submit only this file.
//! This file is the implementation for the class CustomString.
//!----------------------------------------------------------------------------------------


/// Programming Technique II

// Member 1's Name: AKMAL RAFIQUE BIN AHMAD RAPHAIE
// Member 2's Name: Muhammad Najmi Shahmi Bin Mohd Latpi
//
// Section: 2
// Member 1's Name: AKMAL RAFIQUE BIN AHMAD RAPHAIE    Location: KTR K11 (i.e. where are you currently located)
// Member 2's Name: Muhammad Najmi Shahmi Bin Mohd Latpi    Location: KTR K11 (i.e. where are you currently located)

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  9/5/2026    5.58           6.23              25
//  9/5/2026    5.58           6.23                

// Video link:  
//   https://drive.google.com/drive/folders/1_408YcsvD0YHvzvb573KMVI5VFV5vBQw?usp=sharing


#include <iostream>
#include <string>
using namespace std;

#include "custom_string.hpp"

//?----------------------------------------------------------------------------------------
//? The following methods are fully given: a constructor, getData() and setData()
//?----------------------------------------------------------------------------------------

CustomString::CustomString(const string &_data) : data(_data) {}
string CustomString::getData() const { return data; }
void CustomString::setData(const string &_data) { data = _data; }

//! Task 1: Complete the implementation of the following mutator methods:
//!        (a) pushFront()
//!        (b) pushBack()
//!        (c) pop()
//!        (d) popFront()
//!        (e) popBack()

void CustomString::pushFront(const string &s)
{
    data.insert(0,s);
}

void CustomString::pushBack(const string &s)
{
    data.append(s);
}

string CustomString::pop(int index, int count)
{
    string extracted = data.substr(index, count);
    data.erase(index, count );
    return extracted;
}

string CustomString::popFront(int count)
{
    return pop(0, count);
}

string CustomString::popBack(int count)
{
    int startIndex = data.length() - count;

    return pop(startIndex, count);
}

//! Task 2: Complete the implementation of the following overloaded operators:
//!        (a) operator !
//!        (b) operator *

CustomString CustomString::operator!() const
{
    string reversed_data = "";
    for(int i = data.length() -1 ;i>=0;i--){
        reversed_data += data[i];
    }
    return CustomString(reversed_data);
}

CustomString CustomString::operator*(int count) const
{
    string repeated_data = "";
    for(int i =0; i < count; i++){
        repeated_data += data;
    }
    return CustomString(repeated_data);
}

//! Task 3: Complete the implementation of the following conversion methods:
//!        (a) toDouble()
//!        (b) toUpper()

double CustomString::toDouble() const
{
    return stod(data);
}

CustomString CustomString::toUpper() const
{
    string upper_data = data;

    for (int i =0; i < upper_data.length(); i++){
        upper_data[i] = toupper(upper_data[i]);
    }
    return CustomString(upper_data);
}