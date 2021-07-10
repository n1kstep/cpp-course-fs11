#ifndef CLASSES_AND_INHERITANCE_APPLICATION_H
#define CLASSES_AND_INHERITANCE_APPLICATION_H

#include "Array.h"
#include "Decimal.h"
#include "Octal.h"
#include <iostream>

class Application {
    Array* x;
    Array* y;
    Array* z;
public:
    void run();
    void runArray();
    void runDecimal();
    void runOctal();
};


#endif //CLASSES_AND_INHERITANCE_APPLICATION_H
