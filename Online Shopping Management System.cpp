#include <iostream>
#include <string>
using namespace std;

class Product {
    int productId;
    string productName;
    int price;

public:
    Product() {
        productId = 0;
        productName = "";
        price = 0;
    }

    Product(int id, string name, int p) {
        productId = id;
        productName = name;
        price = p;
    }

    void addProduct() {
        cout << "\nEnter Product ID : ";
        cin >> productId;

        cin.ignore();

        cout << "Enter Product Name : ";
        getline(cin, productName);

        cout << "Enter Product Price : ";
        cin >> price;
    }

    void displayProduct() {
        cout << "\n--------------------------\n";
        cout << "Product ID   : " << productId << endl;
        cout << "Product Name : " << productName << endl;
        cout << "Price        : $" << price << endl;
    }

    int getID() {
        return productId;
    }

    int getPrice() {
        return price;
    }

    string getName() {
        return productName;
    }
};

class Admin {
public:
    void addProducts(Product products[], int &count) {
        if (count >= 20) {
            cout << "Product List Full!\n";
            return;
        }

        products[count].addProduct();
        count++;

        cout << "\nProduct Added Successfully.\n";
    }

    void displayProducts(Product products[], int count) {
        if (count == 0) {
            cout << "\nNo Products Available.\n";
            return;
        }

        cout << "\n===== PRODUCT LIST =====\n";

        for (int i = 0; i < count; i++) {
            products[i].displayProduct();
        }
    }
};

class ShoppingCart {
    Product cart[20];
    int cartCount;

public:
    ShoppingCart() {
        cartCount = 0;
    }

    void addToCart(Product products[], int productCount) {
        int id;
        cout << "\nEnter Product ID : ";
        cin >> id;

        for (int i = 0; i < productCount; i++) {
            if (products[i].getID() == id) {
                cart[cartCount] = products[i];
                cartCount++;

                cout << "Product Added To Cart.\n";
                return;
            }
        }

        cout << "Product Not Found.\n";
    }

    void viewCart() {
        if (cartCount == 0) {
            cout << "\nCart is Empty.\n";
            return;
        }

        int total = 0;

        cout << "\n======= YOUR CART =======\n";

        for (int i = 0; i < cartCount; i++) {
            cart[i].displayProduct();
            total += cart[i].getPrice();
        }

        cout << "\nTotal Bill : $" << total << endl;
    }
};

class Customer {
    string name;

public:
    void registerCustomer() {
        cin.ignore();

        cout << "\nEnter Customer Name : ";
        getline(cin, name);

        cout << "Welcome " << name << "!\n";
    }
};

int main() {

    Product products[20];

    Admin admin;

    Customer customer;

    ShoppingCart cart;

    int productCount = 0;

    int choice;

    do {
        cout << " ONLINE SHOPPING SYSTEM\n";
        cout << "1. Register Customer\n";
        cout << "2. Add Product (Admin)\n";
        cout << "3. View Products\n";
        cout << "4. Add Product To Cart\n";
        cout << "5. View Cart\n";
        cout << "6. Exit\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice) {

        case 1:
            customer.registerCustomer();
            break;

        case 2:
            admin.addProducts(products, productCount);
            break;

        case 3:
            admin.displayProducts(products, productCount);
            break;

        case 4:
            cart.addToCart(products, productCount);
            break;

        case 5:
            cart.viewCart();
            break;

        case 6:
            cout << "\nThank You For Using The System.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}