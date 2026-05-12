#include<iostream>
#include<string>
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
int main(){
    Line lines[3];





    return 0;
}