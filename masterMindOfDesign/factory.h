#pragma once
#include <limits> 
#include<algorithm>
#include"customer.h"
#include"operation.h"
class Shipping;
class Factory {
public:
    Factory();
    void addCustomer();
    Customer* getCustomer();
    void mangingProducts();
    Product* returnProduct(unsigned int productId);
    Product* removeProduct();
    void addProducts();
    void display();
    bool checkInventory(Product* product);
    bool isEmpty();
    virtual  void arrangeOperations()=0;
    void displayCompletedProducts();
    void displayAllCustomers();
   
private :  
    vector<Product*>resultedProducts;
    vector<Customer*> customers;
    //Shipping* shipping;
    int numberOfProducts;
    string location;   
    int numberOfCustomers;
    int numberOfOperations;
protected:
    Container/*SpaceEfficientlinkedList*/ <Product*>factory;
    Operation op;
};

class laptopFactory:public Factory {//number of operations depend on product type
public:
    void arrangeOperations()override {
        cout << "\n*============Factory operations=======================* " << endl;
       
        op.NumOfOperation() = 2;
        cout << "Number of operations are " << op.NumOfOperation()<<" for laptop factory"<<endl;
        factory.defineSize(op.NumOfOperation());

    }
};
class SMARTPHONE :public Factory {
    void arrangeOperations()override {
        cout << "\n*============Factory operations=======================* " << endl;
        op.NumOfOperation() = 5;
        cout << "Number of operations are " << op.NumOfOperation()<<" for smart phone factory" << endl;
        factory.defineSize(op.NumOfOperation());

    }
};

class  TABLET :public Factory {
    void arrangeOperations()override {
        cout << "\n*============Factory operations=======================* " << endl;
        op.NumOfOperation() = 3;
        cout << "Number of operations are " << op.NumOfOperation()<<" for tablet factory "<<endl;
        factory.defineSize(op.NumOfOperation());

    }
};
