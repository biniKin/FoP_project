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
void saveInventoryToFile(string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < productCount; i++) {
            file << "ID: " << productIDs[i] << "," << "Name: " << productNames[i] << "," << "Categorie: " << productCategories[i] << "," << "Price: " << productPrices[i] << "," << "Quan: " << productQuantities[i] << endl;
        }
        file.close();
        cout << "Inventory saved to file." << endl;
    } else {
        cout << "Error: Could not open file." << endl;
    }
}

//calling main function
int main(){

}