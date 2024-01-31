#include "customer.h"
int Customer::id = 1;
void Customer::EnterCustomerDetails() {
    cout << "*~~~~~Customer " << customerid + 1 << endl;
    cout << "Enter customer name: ";
    cin >> name;
    cout << "Enter customer address: ";
    cin >> address;
    cout << "Enter customer phone number : ";
   
    while (!(cin >> phonenumber))
    {
        cout << "Error>>phone number must be a number  " ;
        cin.clear();
        cin.ignore(123, '\n');
    }
}

      void Customer::printDetails() {
        cout << "Name: " << name << " ||Address: " << address << " ||Phone number: " << phonenumber << " ||Customer Id: " << customerid +1<< endl;

    }
     void Customer::setFactory(Factory* f) {
        factory = f;
    }

     Customer Customer::operator*() {
        return *this;
    }

    unsigned int Customer::getProductId() {
        return productId;
    }

     void Customer::demandOrderAfterCompleted(Product p) {
        product = p;
    }

     int Customer::customerId() {
        return customerid;
    }
     
Product Customer::demandOrders() {
    return  product.AddProduct();
}

string Customer::getAddress() {
    return address;
}

Product Customer::getProduct() {
    return product;
}

