#pragma once
#include<string>
#include"dataStructure.h"
class Customer;
enum ProductType {
    LAPTOP, SMARTPHONE, TABLET
};

string convertFromEnumToString(ProductType y);
class Product {
private:
    Stack manefacturingSteps;
    int productid;
    static int nextId;
    string name;
    int customerId;
    int quantity;
    Customer* customer;
    ProductType type;
    
    string status;
    void addOrder();
    void pushStep(string s);
public:

    Product() :productid(nextId++) {
        quantity = 0;
        productid--;
        status = "Raw materials";
    }
    bool isEmpty();
    string completeStep();
    Product AddProduct();
    void displayProductDetails();
    void setStatus(string s);
    string getName();
    string getStatus();
    bool isReady();
    Stack& getManifacturingSteps();
    int getId();
    ProductType getType();
    void setType(ProductType p);
    bool operator==(Product);
    int getQuantity();
    string prepareOrder();
    void getLastOrder();
    string display_product_details();
    friend ostream& operator<<(ostream& os, const Product& s) {
        os << "Name: " << s.name << "  || " << "Quantity: "
            << s.quantity << "  || Id: " << s.productid+1 << "  || Status: "
            << s.status << "  || Type:" << convertFromEnumToString(s.type) << endl;
        return os;
    }
    void setCustomerId(int c);

    Product& operator=(const Product& other);
    
};


