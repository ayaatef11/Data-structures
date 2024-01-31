#pragma once
#include<iostream>
using namespace std;
class Operation {
    int numOfOperations;
public:
    Operation();
    void performOperation();
    int& NumOfOperation();
};