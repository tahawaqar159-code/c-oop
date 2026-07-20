# include <iostream >
# include <string >
using namespace std;    

class product {
    int productId;
    string productName;
    int price ;

public:
    product () {
        productId = 0;
        productName = "";
        price = 0;
    }
    product ( int id ,string name, int p) {
        productId = id;
        productName = name;
        price = p;
    }   
          
    void displayProduct() {
        cout << "Product ID   : " << productId << endl;
        cout << "Product Name : " << productName << endl;
        cout << "Price        : $" << price << endl;
    }
    void addProduct() {
        cout << "\nEnter Product ID: ";
        cin >> productId;

        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, productName);

        cout << "Enter Price: $";
        cin >> price;
    }

};

int main (){
    product p1;
    p1.addProduct ();
    p1.displayProduct();


}