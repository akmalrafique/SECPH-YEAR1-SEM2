// Programming Technique II (SECSJ1023)
// Semester 2, 2023/2024

// Final Exam (Practical - Question 2)

// Student's Name:AKMAL RAFIQUE BIN AHMAD RAPHAIE
// Matric Number:.....................

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
using namespace std;

class Fooditem{
    protected:
    string name;
    double price;
    int quantity;
    public:
    Fooditem(string n,double p,int q):name(n),price(p),quantity(q){}
    virtual void dispDetails()=0;
    virtual double calcPrice(){

        return price*quantity;
    }
};
class Order{
    private:
    vector<Fooditem*> fooditem;
    public:
    void additem(Fooditem* fi){
            fooditem.push_back(fi);
            }
    void dispOrder(){
        double total=0;
        for(int i=0;i<fooditem.size();++i){
        fooditem[i]->dispDetails();
        total+= fooditem[i]->calcPrice();
    }
    cout<<"total order is price is: rm "<<total<<endl;
}
};
class Pizza:public Fooditem{
    private:
    string size;
    public:
    Pizza(string n,double p,int q,string s):Fooditem(n,p,q){
        size=s;
    }
    void dispDetails(){
        cout<<"pizza - "<<name;
        cout<<"price: "<<price;
        cout<<"quantity: "<<quantity;
        cout<<"size: "<<size;
    }

};
class Burger:public Fooditem{
    private:
    bool isDoublePatty;
    public:
    Burger(string n,double p,int q,bool i):Fooditem(n,p,q){
        isDoublePatty=i;
    }
    void dispDetails(){
        cout<<"burger - "<<name;
        cout<<"price: "<<price;
        cout<<"quantity: "<<quantity;
        cout<<"double patty: "<<isDoublePatty;        
    }
    double calcPrice(){
        if(isDoublePatty!=true){
           return quantity*(price+3.80); 
        }
    }

};
int main(){
    Order myorder;
    Fooditem* item[5];
    item[0]=new Pizza("Super Supreme",52.3,1,"large");
    item[1]=new Burger("cheese burger",14.5,3,false);
    item[2]=new Pizza("hawaiian chicken",19.9,3,"personal");
    item[3]=new Pizza("beef peperoni",40.9,1,"regular");
    item[4]=new Burger("chicken",13.5,2,true);
    for(int i=0;i<5;++i){
        myorder.additem(item[i]);
    }
    myorder.dispOrder();
    for(int i=0;i<5;i++){
        delete item[i];
    }

    return 0;

}
