// NAME: AKMAL RAFIQUE BIN AHMAD RAPHAIE
// MATRIC NO.:A25CS0181
// SECTION:

// SECJ1023 PROGRAMMING TECHNIQUES 2
// FINAL EXAM (PRACTICAL) 2024/2025-02
// QUESTION 2

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
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
        cout<<"Warranty: "<<warranty<<" month"<<endl<<endl;
    }

};
class ClothingProduct:public Product{
    private:
    string size;
    public:
    ClothingProduct(string n,double p,int q,string s):Product(n,p,q),size(s){}
    void display()const{
        cout<<"Clothing:"<<name<<endl;
        cout<<"Price: RM"<<price<<endl;
        cout<<"Quantity: "<<quantity<<endl;
        cout<<"Size: "<<size<<endl<<endl;        
    }
};
class ShoppingCart{
    public:
    vector<Product* >items;
    void addProduct(Product* item){
        items.push_back(item);
    }
    void displayCart()const{
        for(int i=0;i<items.size();i++){
            items[i]->display();
        }
    }
    double calculateTotal()const{
        double total=0;
        for(int i=0;i<items.size();i++){
            total+=items[i]->calculateTotal();
        }
        return total;
    }

    ~ShoppingCart(){}
};

int main(){
    ShoppingCart cart;
    cart.addProduct(new ElectronicProduct("Smart Watch",120,1,24));
    cart.addProduct(new ClothingProduct("T-Shirt",35,2,"L"));
    cart.displayCart();
    cout<<"Total Amount: RM"<<cart.calculateTotal()<<endl;
    try{
        if(cart.calculateTotal()<100){
            throw runtime_error("LowTotalExecption:");
        }
    }
    catch(runtime_error& e){
        cout<<e.what()<<" Your order must be at least RM100 to proceed.";
    }
    int count = 0;
// Traditional for loop using an index 'i'
for (int i = 0; i < cart.items.size(); i++) {
    // Accessing the element at index 'i' using the pointer 'cart.items[i]'
    if (cart.items[i]->calculateTotal() > 50.0) {
        count++;
    }
}
cout << "Number of products above RM50: " << count << endl;

    system("pause");
}