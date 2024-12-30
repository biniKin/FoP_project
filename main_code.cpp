#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//creating constant variable
const int MAX_PRODUCTS = 100;

//creating an array
int productIDs[MAX_PRODUCTS];
string productNames[MAX_PRODUCTS];
string productCategories[MAX_PRODUCTS];
double productPrices[MAX_PRODUCTS];
int productQuantities[MAX_PRODUCTS];

//product counter
int productCount = 0;

//function to add products
void addProduct(int id, string name, string category, double price, int quantity) {
    for (int i = 0; i < productCount; i++) {
        if (productIDs[i] == id) {
            cout << "ID already exists." << endl;
            return;
        }
    }

    if (productCount < MAX_PRODUCTS) {
        productIDs[productCount] = id;
        productNames[productCount] = name;
        productCategories[productCount] = category;
        productPrices[productCount] = price;
        productQuantities[productCount] = quantity;
        productCount++;
        cout << "Product added successfully." << endl;
    } else {
        cout << "Inventory is full!" << endl;
    }
}

//function to remove products



//function to find products


//function to update products



//function to print all the products
void printProducts() {
    for (int i = 0; i < productCount; i++) {
        cout << "ID: " << productIDs[i] << endl;
        cout << "Name: " << productNames[i] << endl;
        cout << "Category: " << productCategories[i] << endl;
        cout << "Price: $" << productPrices[i] << endl;
        cout << "Quantity: " << productQuantities[i] << endl;
        cout << "------------------------" << endl;
    }
}

//function to save to file


//calling main function
int main(){

}