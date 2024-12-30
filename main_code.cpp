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


//function to remove products
void removeProduct(int id) {
    bool found = false;
    for (int i = 0; i < productCount; i++) {
        if (productIDs[i] == id) {
            for (int j = i; j < productCount - 1; j++) {
                productIDs[j] = productIDs[j + 1];
                productNames[j] = productNames[j + 1];
                productCategories[j] = productCategories[j + 1];
                productPrices[j] = productPrices[j + 1];
                productQuantities[j] = productQuantities[j + 1];
            }
            productCount--;
            found = true;
            cout << "Product removed successfully." << endl;
            break;
        }
    }

    if (!found) {
        cout << "ID does not exist." << endl;
    }
}


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