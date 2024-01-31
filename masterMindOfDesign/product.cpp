#include "product.h"

string convertFromEnumToString(ProductType y) {
    if (y == ProductType::LAPTOP)return "laptop";
    else if (y == ProductType::SMARTPHONE)return "smart phone";
    return "tablet";
}
void Product::addOrder() {
    char c;
    string op;
    cout << "Enter order components" << endl;
    do {
        cin >> op;
        pushStep(op);
        cout << "Do you want to add more(y/n): ";
        cin >> c;
    } while (c == 'y');

}

Product Product::AddProduct() {
    cout << "*~~~~~Product " << productid + 1 << endl;
    cout << "Enter order name: ";
    cin >> name;
    addOrder();
    cout << "Enter quantity: ";
    
    while (!(cin >> quantity))
    {
        cout << "Error>>quantity must be a number ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout << "Enter order type: ";
    int n;
    cout << "\nEnter 0 for laptop,1 for smart phone,2 for tablet : ";   
    while (!(cin >> n))
    {
        cout << "Error>>you must add a number ";
        cin.clear();
        cin.ignore(123, '\n');
    }
   
    switch (n) {
    case 0:
        type = ProductType::LAPTOP;
        break;
    case 1:
        type = ProductType::SMARTPHONE;
        break;
    case 2:
        type = ProductType::TABLET;
        break;
    }
    setType((type));
    return *this;
}

void Product::displayProductDetails() {
    cout << "Name: " << name << "  || " << "Quantity: "
        << quantity << "  || Id: " << productid << "  || Status: "
        << status << "  || Type:" << convertFromEnumToString(type) << "  || Customer id: " << customerId << endl;
}

void Product::setStatus(string s) {
    status = s;
}

string Product::getName() {
    return name;
}

string Product::getStatus() {
    return status;
}

bool Product::isReady() {
    return (status == "completed") ? 1 : 0;
}
Stack& Product::getManifacturingSteps() {
    return manefacturingSteps;
}

string Product::completeStep() {
    return manefacturingSteps.pop();
}

int Product::getId() {
    return productid;
}

ProductType Product::getType() {
    return type;
}

void Product::setType(ProductType p) {
    type = p;
}

bool Product::operator==(Product p) {
    return this->productid == p.productid;
}

int Product::getQuantity() {
    return quantity;
}

void Product::pushStep(string s) {
    manefacturingSteps.push(s);
}

string Product::prepareOrder() {
    string s;
    while (!manefacturingSteps.isEmpty()) {
        s+= "completing order <<" + completeStep() + " >>\n" ;
    }
    return s;
}

void Product::getLastOrder() {
    manefacturingSteps.peek();
}

     bool Product::isEmpty() {
        return manefacturingSteps.isEmpty();
    }
      string Product::display_product_details() {
        return "Name: " + name + "  || " + "Quantity: "
            + to_string(quantity) + "  || Id: " + to_string(productid) + "  || Status: "
            + status + "  || Type:" + convertFromEnumToString(type) + "\n";
    }
      void Product::setCustomerId(int c) {
        customerId = c;
    }
     Product& Product::operator=(const Product& other) {
            //this->manefacturingSteps = other.manefacturingSteps;
            this->productid = other.productid;
            this->name = other.name;
            this->customerId = other.customerId;
            this->quantity = other.quantity;
            this->customer = other.customer; //just a ppinter,don't need to overload operator
            this->type = other.type;
            this->status = other.status;
        return *this;
    }
    
int Product::nextId = 1;


