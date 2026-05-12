#include<iostream>
#include<string>
#include <cstring>
using namespace std;
class Line{
    private:
    int m;
    int c;
    public:
    Line(int M=0,int C =0){
        m=M;
        c=C;
    }
    void read();
    Line operator-(const Line& right)const;
    bool operator!=(const Line& right)const;
    string toString();
    friend void printLines(Line lines[]);
};
void Line:: read(){
    cout<<"Enter the slope (m) and y-intercept of a line (c) =>";
    cin>>m>>c;
}
Line Line::operator-(const Line& right)const{
    Line line3;
    line3.m=this->m - right.m;
    line3.c=this->c - right.c;
    return line3;
}
bool Line:: operator!=(const Line& right)const{
    if(this->m * right.m ==-1){
        return true;
    }
        else{
            return false;
        }
}
string Line::toString(){
    string equation="y=";
    if(m==1){
        equation+="x +";
    }
    else if(m==-1){
        equation+="-x ";
    }
    else{
        equation+=to_string(m)+"x ";
    }
    if(c<0){
        equation+="-"+to_string(c);
    }
    else if(c==0){
        equation+="";
    }
    else{
        equation+="+"+to_string(c);
    }
    return equation;
}
void printLines(Line lines[])
{
	cout << endl;
	for (int i = 0; i < 3; i++){
        cout<<"line "<<i+1<<"slope(m) = "<<lines[i].m<<" , y-intercept(c) = "<<lines[i].c<<",equation: "<<lines[i].toString()<<endl;
	}
	cout << endl;
}
int main(){
    Line lines[3];





    return 0;
}