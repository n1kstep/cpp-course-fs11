#ifndef HOMEWORK_C___APPLICATION_H
#define HOMEWORK_C___APPLICATION_H

#include "Integer.h"
#include "Decimal.h"
#include "Binary.h"
#include <iostream>

class Application {
    Integer* x;
    Integer* y;
    Integer* z;
public:
    void run();
    void runDecimal();
    void runBinary();
};

#endif //HOMEWORK_C___APPLICATION_H