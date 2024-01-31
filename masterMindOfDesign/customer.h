#pragma once
#include"product.h"
#include<vector>
class Factory;
class Customer {
    Factory* factory;
    int customerid;
    string name;
    string address;
    unsigned int phonenumber;
    unsigned int productId;
    Product product;
    ProductType productType;
    static int id;
    //void purchaseProducts(Factory* factory);
    //string purchase_Products(Factory* factory);
    int numOfProducts;
public:

    Customer() :customerid(id++)
    {
        customerid--;
        numOfProducts = 0;
        factory = nullptr;
    }
    void setFactory(Factory* f);
    void EnterCustomerDetails();
    Product demandOrders();
    string getAddress();
    Product getProduct();
    void printDetails();
    

    Customer operator*();

    friend ostream& operator<<(ostream& os, Customer& s) {
        os << s.name << " ||Address: " << s.address << " ||Phone number: " << s.phonenumber << " ||Customer Id: " << s.customerid+1 << endl;
        
        return os;
    }
    unsigned int getProductId();
    void demandOrderAfterCompleted(Product p);
    int customerId();
};
