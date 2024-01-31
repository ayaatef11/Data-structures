#include "operation.h"

Operation::Operation()
{
    numOfOperations = 0;
}
void Operation::performOperation() {
    cout << "Performing operation" << endl;
}
int& Operation::NumOfOperation() {
    return numOfOperations;
}

