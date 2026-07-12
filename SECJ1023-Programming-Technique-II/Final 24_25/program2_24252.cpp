// NAME: AKMAL RAFIQUE BIN AHMAD RAPHAIE
// MATRIC NO.:A25CS0181
// SECTION:

// SECJ1023 PROGRAMMING TECHNIQUES 2
// FINAL EXAM (PRACTICAL) 2024/2025-02
// QUESTION 2

#include<iostream>
#include<string>
using namespace std;

class Product{
    protected:
    string name;
    double price;
    int quantity;
    public:
    Product(string n,double p,int q):name(n),price(p),quantity(q){}
    virtual void display()const =0;
    virtual double calculateTotal() const{
        return price*quantity;
    }
    virtual ~Product(){};
};
class ElectronicProduct:public Product{
    private:
    int warranty;
    public:
    ElectronicProduct(string n,double p,int q,int w):Product(n,p,q),warranty(w){}
    void display()const{
        cout<<"Electronic:"<<name<<endl;
        cout<<"Price: RM"<<price<<endl;
        cout<<"Quantity: "<<quantity<<endl;
        cout<<"Warranty: "<<warranty<<endl;
    }

};
class ClothingProduct:public Product{
    private:
    string size;
    public:
    ClothingProduct(string n,double p,int q,int s):Product(n,p,q),size(s){}
    void display()const{
        cout<<"Clothing:"<<name<<endl;
        cout<<"Price: RM"<<price<<endl;
        cout<<"Quantity: "<<quantity<<endl;
        cout<<"Warranty: "<<warranty<<endl;        
    }
};