#include"factory.h"


Factory::Factory() {
    numberOfOperations = 0;
    numberOfProducts = 0;
    numberOfCustomers = 0;
    resultedProducts.reserve(10);
}

void Factory::addCustomer() {
    Customer* c = new Customer();
    c->EnterCustomerDetails();
    c->setFactory(this);
    customers.push_back(c);
    numberOfCustomers++;
    cout << "Customer added successfully^^^^Customer id is " << c->customerId()+1;
}

Customer* Factory::getCustomer() {
    cout << "\n*===========================Customer Details=================================*" << endl;
    size_t id = 0;
    cout << "Enter customer id: ";
    while (!(cin >> id))
    {
        cout << "Error>>customer id must be a number  ";
        cin.clear();
        cin.ignore(123, '\n');
    }

    return customers[id - 1];
    return nullptr;
}

void Factory::mangingProducts() {
    cout << "\n*====================managing products==================*\n";

    int a = factory.Size();
    int b = factory.numNodes();
    for (int i = 0; i < a + b - 1; i++) {
        factory.moveToNextNode();
    }
    resultedProducts = factory.preparedElements();
   
    cout << "Products managed successfully" << endl;
}

Product* Factory::returnProduct(unsigned int productId) {
    if (factory.isEmpty()) {
        cout << "The factory is Empty" << endl;
        return nullptr;
    }

    unsigned int c = productId/* - 1*/;
    Product* p = resultedProducts.at(c);
    auto it = resultedProducts.begin() +c;
    resultedProducts.erase(it);
    return p;
}

void Factory::addProducts() {
    cout << "\n*====================Adding products=======================*\n";
    int customerId;
    cout << "Enter customer id to add them a product : ";
    while (!(cin >> customerId))
    {
        cout << "Error>>customer id must be a number in range ("<< numberOfCustomers<<") ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    Product* p = new Product(customers[customerId - 1]->demandOrders());
    p->setCustomerId(customerId);
    p->setStatus("inProduction");
    if (p != nullptr) {
        factory.push(p);
        numberOfProducts++;
    }
    else throw runtime_error("product not added");
    cout << "product Added successfully" << endl;
}

Product* Factory::removeProduct() {
    numberOfProducts--;
    return factory.pop();
    
}

bool Factory::checkInventory(Product* product) {
    return !factory.search(product);
}

void Factory::display() {
    factory.display();
}


void Factory::displayAllCustomers() {
       for (auto i : customers)cout << *i;
   }

    void Factory::displayCompletedProducts() {
       for (auto i : resultedProducts) {
           i->prepareOrder();
           i->setStatus("completed");
           cout << *i << endl;
       }
   }

    bool Factory::isEmpty() {
       return !numberOfProducts;
   }