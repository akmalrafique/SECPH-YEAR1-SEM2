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


};
void Line:: read(){
    cout<<"Enter the slope (m) and y-intercept of a line (c) =>";
    cin>>m>>c;
}
