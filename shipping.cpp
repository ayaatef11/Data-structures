#include "shipping.h"

Shipping::Shipping() : factory(nullptr), customer(nullptr) {}
void Shipping::setFactory(Factory* f) {
    factory = f;
}

void Shipping::setCustomer() {
    customer=factory->getCustomer();   
}

void Shipping::shipOrder() {
    if (factory == nullptr || customer == nullptr) throw runtime_error("invalid assignment");
   unsigned int ii= customer->getProductId();
    Product* product = factory->returnProduct(ii);
    if (product == nullptr)throw runtime_error("product isn't available");
    productName = product->getName();
    shippingAddress = customer->getAddress();
    string date;
    cout << "\nEnter delivering date: ";
    cin >> date;
    deliveryDate = date;
    product->setStatus("shipped");
    customer->demandOrderAfterCompleted(*product);
}

void Shipping::getShippingDetails() {
    if (productName.empty() || shippingAddress.empty() || deliveryDate.empty())  throw runtime_error("No shipping details available.");
    cout << "Order " << productName << " shipped to: " << shippingAddress 
        << " with delivery date: " << deliveryDate << endl;
}