#pragma once
#include"factory.h"
class Shipping {
    Factory* factory;
    Customer* customer;
    string productName;
    string shippingAddress;
    string deliveryDate;

public:
    Shipping();

    void setFactory(Factory* f);

    void setCustomer();

    void shipOrder();

    void getShippingDetails();
};

