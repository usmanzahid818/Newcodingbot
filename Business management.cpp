#include <iostream>
using namespace std;


const int MAX_PRODUCTS = 100;
const int MAX_NAME_LENGTH = 50;
const int LOW_STOCK_THRESHOLD = 10; 

int productIds[MAX_PRODUCTS];
char productNames[MAX_PRODUCTS][MAX_NAME_LENGTH];
int productQuantities[MAX_PRODUCTS];
int productCount = 0;



void addProduct() {
    if (productCount < MAX_PRODUCTS) {
        cout << "Enter product name: ";
        cin >> productNames[productCount];
        cout << "Enter quantity: ";
        cin >> productQuantities[productCount];
        productIds[productCount] = productCount + 1;
        productCount++;
        cout << "Product added successfully.\n";
    } else {
        cout << "Inventory is full. Cannot add more products.\n";
    }
}

void displayInventory() {
    cout << "Inventory:\n";
    cout << "ID\tName\tQuantity\n";
    for (int i = 0; i < productCount; ++i) {
        cout << productIds[i] << "\t" << productNames[i] << "\t" << productQuantities[i] << "\n";
    }
}

int findProductIndex(int productId) {
    for (int i = 0; i < productCount; ++i) {
        if (productIds[i] == productId) {
            return i;
        }
    }
    return -1;  
}

void updateProductQuantity() {
    int productId, newQuantity;
    cout << "Enter product ID to update quantity: ";
    cin >> productId;

    int index = findProductIndex(productId);

    if (index != -1) {
        cout << "Enter new quantity: ";
        cin >> newQuantity;
        productQuantities[index] = newQuantity;
        cout << "Quantity updated successfully.\n";
    } else {
        cout << "Product not found.\n";
    }
}

void trackStockMovement() {
    int productId, quantityChange;
    cout << "Enter product ID for stock movement: ";
    cin >> productId;

    int index = findProductIndex(productId);

    if (index != -1) {
        cout << "Enter quantity change (+ for addition, - for reduction)";
        cin >> quantityChange;
        productQuantities[index] += quantityChange;
        cout << "Stock movement tracked successfully.\n";
    } else {
        cout << "Product not found.\n";
    }
}

void lowStockAlert() {
    cout << "Low Stock Alert:\n";
    cout << "ID\tName\tQuantity\n";
    for (int i = 0; i < productCount; ++i) {
        if (productQuantities[i] < LOW_STOCK_THRESHOLD) {
            cout << productIds[i] << "\t" << productNames[i] << "\t" << productQuantities[i] << "\n";
        }
    }
}

void salesReporting() {
    int productId, soldQuantity;
    cout << "Enter product ID for sales reporting: ";
    cin >> productId;

    int index = findProductIndex(productId);

    if (index != -1) {
        cout << "Enter quantity sold: ";
        cin >> soldQuantity;

        if (soldQuantity <= productQuantities[index]) {
            productQuantities[index] -= soldQuantity;
            cout << "Sale recorded successfully.\n";
        } else {
            cout << "Not enough stock available for the sale.\n";
        }
    } else {
        cout << "Product not found.\n";
    }
}

void orderManagement() {
    int productId, orderedQuantity;
    cout << "Enter product ID for order management: ";
    cin >> productId;

    int index = findProductIndex(productId);

    if (index != -1) {
        cout << "Enter quantity to order: ";
        cin >> orderedQuantity;

        productQuantities[index] += orderedQuantity;
        cout << "Order placed successfully.\n";
    } else {
        cout << "Product not found\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Display Inventory\n";
        cout << "3. Update Product Quantity\n";
        cout << "4. Track Stock Movement\n";
        cout << "5. Low Stock Alert\n";
        cout << "6. Sales Reporting\n";
        cout << "7. Order Management\n"; 
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateProductQuantity();
                break;
            case 4:
                trackStockMovement();
                break;
            case 5:
                lowStockAlert();
                break;
            case 6:
                salesReporting();
                break;
            case 7:
                orderManagement();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
