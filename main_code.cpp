#include <iostream>
#include <string>
#include <fstream>


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
void findProduct(int id) {
    for (int i = 0; i < productCount; i++) {
        if (productIDs[i] == id) {
            cout << "ID: " << productIDs[i] << endl;
            cout << "Name: " << productNames[i] << endl;
            cout << "Category: " << productCategories[i] << endl;
            cout << "Price: $" << productPrices[i] << endl;
            cout << "Quantity: " << productQuantities[i] << endl;
            return;
        }
    }
    cout << "Product not found." << endl;
}

//function to update products
void updateProduct(int id, string name, string category, double price, int quantity) {
    for (int i = 0; i < productCount; i++) {
        if (productIDs[i] == id) {
            productNames[i] = name;
            productCategories[i] = category;
            productPrices[i] = price;
            productQuantities[i] = quantity;
            cout << "Product updated successfully." << endl;
            return;
        }
    }
    cout << "ID does not exist." << endl;
}


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
    string username;
    int password;
    int trial = 3;
    string correctUserName = "admin";
    int correctPassword = 123;
    cout << "Login" << endl;

    while(trial > 0){

        cout << "Enter username: " ;
        cin >> username;
        cout << "Enter password: " ;
        cin >> password;
        if(username == correctUserName && password == correctPassword){
            cout << "LogIn successfully!" << endl;
            break;
        }
        else{
            cout << "Wrong password or username. You left with "<< trial - 1 << " trials." << endl;
        }
        trial -= 1;
        if(trial == 0){
            exit(0);
        }

    }

    // main menu
    char choice;
    do {
        cout << "1. Add a product" << endl;
        cout << "2. Remove a product" << endl;
        cout << "3. Find a product" << endl;
        cout << "4. Update a product" << endl;
        cout << "5. View all products" << endl;
        cout << "6. Save inventory to file" << endl;
        cout << "Q. Quit" << endl;
        cin >> choice;
        
        // switch statement to handle user choice
        switch (choice) {
        case '1': {
            int id, quantity;
            string name, category;
            double price;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Category: ";
            cin >> category;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> quantity;
            addProduct(id, name, category, price, quantity);
            break;
        }
        case '2': {
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;
            removeProduct(id);
            break;
        }
        case '3': {
            int id;
            cout << "Enter ID to find: ";
            cin >> id;
            findProduct(id);
            break;
        }
        case '4': {
            int id, quantity;
            string name, category;
            double price;
            cout << "Enter ID to update: ";
            cin >> id;
            cout << "Enter new Name: ";
            cin >> name;
            cout << "Enter new Category: ";
            cin >> category;
            cout << "Enter new Price: ";
            cin >> price;
            cout << "Enter new Quantity: ";
            cin >> quantity;
            updateProduct(id, name, category, price, quantity);
            break;
        }
        case '5':
            printProducts();
            break;
        case '6':
            saveInventoryToFile("inventory.csv");
            break;
        case 'Q':
        case 'q':
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (true);

    return 0;
}
