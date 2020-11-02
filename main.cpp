#include <iostream>
#include "utilities/LinkedList.h"
#include "test.h"

#include "interface/MainInterface.h"

int main() {
    unitTest();
    MainInterface interface;
    interface.runSimulation();
    return 0;
}
