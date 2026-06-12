//? EXERCISE 4: ASSOCIATION

// Programming Technique II

// Member 1's Name: AKMAL RAFIQUE BIN AHMAD RAPHAIE Matric: A25CS0181
// Member 2's Name: MUHAHAMMAD NAJMI SHAHMI BIN MOHD LATPI Matric: A25CS0279

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  4/6/2026    4:14pm          4:43           29
//  _________    ___________   ___________    ________

// Video link:
//   https://drive.google.com/file/d/1UH9akut4wFh8eJoEni4oAckkNcOixNZ-/view?usp=sharing



#include <iostream>
#include <cmath>
using namespace std;

class Term
{
private:
    int coef;
    int exp;

public:
    Term(int c = 0, int e = 0);
    void set(int c, int e);
    int evaluate(int x) const;
    int exponent() const;
    int coefficient() const;
};

class Polynomial
{
private:
    Term terms[100];
    int numTerms;
public:
    Polynomial();
    void input();
    int evaluate(int x) const;
    Term largestTerm() const;
    int degree() const;
};

//----------------------------------------------------------------------------
int main()
{
    Polynomial poly;

    cout << "Enter a polynomial: "<< endl;
    poly.input();

    cout << "\nDegree of Polynomial = " << poly.degree() << endl;

    cout << " x  \t\tPolynomial value" << endl;
    cout << "----\t\t----------------" << endl;

    for (int x = 0; x <= 5; x++)
        cout << x << "  \t\t"<<poly.evaluate(x) << endl;

    cout << endl;

    system("pause");
    return 0;
}

//----------------------------------------------------------------------------
// class Term

// The constructor is given

Term::Term(int c, int e) : coef(c), exp(e) {}

// Implement the other methods
void Term::set(int c, int e) {
    coef=c;
    exp=e;
}
int Term::exponent() const {
    return exp;
}
int Term::coefficient() const {
    return coef;
}
int Term::evaluate(int x) const {
    return coef * pow(x, exp);
}
//----------------------------------------------------------------------------

// class Polynomial implementation (separate from the declaration)

Polynomial::Polynomial(){
    numTerms = 0;
}

void Polynomial::input(){
    cout << "How many terms? => ";
    cin >> numTerms;

    int c,e;
    for(int i = 0;i<numTerms;i++){
        cout << " Enter term #"<< i +1<< " (coef and exp) => ";

        cin >> c >> e;

        terms[i].set(c,e);
    }
}

int Polynomial::evaluate(int x) const{
    int sum = 0;

    for(int i =0; i<numTerms;i++){
        sum += terms[i].evaluate(x);
    }

    return sum;
}
// Implement the constructor and the other methods of the class Polynomial
Term Polynomial::largestTerm() const{
    int largestIndex =0;
    for(int i=1;i<numTerms;i++){
        if(terms[i].exponent()>terms[largestIndex].exponent()){
            largestIndex =i;
        }
    }
    return terms[largestIndex];
}
int Polynomial::degree() const{
    return largestTerm().exponent();
}