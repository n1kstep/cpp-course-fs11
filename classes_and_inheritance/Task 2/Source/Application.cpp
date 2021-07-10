#include "../Include/Application.h"
#include "Exceptions.h"

void Application::runArray() {
    bool flag = true;
    int b;
    x = new Array;
    y = new Array;
    z = new Array;
    do {
        std::cout << "1-array + array\n"
                     "2-array[i]\n"
                     "3-get size\n"
                     "4-Return" << std::endl;
        std::cin >> b;
        switch (b) {
            case 1: {
                std::cin >> *x;
                std::cin >> *y;
                x->sum(y, z);
                std::cout << *x << " + " << *y << " = " << *z << std::endl;
                break;
            }
            case 2: {
                std::cin >> *x;
                int ind;
                std::cout << "Enter index:" << std::endl;
                std::cin >> ind;
                std::cout << "array[" << ind << "] = " << (*x)[ind] << std::endl;
                break;
            }
            case 3: {
                std::cin >> *x;
                std::cout << "Size: " << x->get_size() << std::endl;
                break;
            }
            default: {
                flag = false;
                break;
            }
        }
    } while (flag);
    delete x;
    delete y;
    delete z;
}

void Application::runDecimal() {
    bool flag = true;
    
    x = new Decimal;
    y = new Decimal;
    z = new Decimal;
    
    int b;
    do {
        std::cout << "1-array + array (overloaded)\n"
                     "2-decimal - decimal\n"
                     "3-decimal * decimal\n"
                     "4-decimal / decimal\n"
                     "5-Compare\n"
                     "6-Return" << std::endl;
        std::cin >> b;
        switch (b) {
            case 1: {
                std::cin >> *x;
                std::cin >> *y;

                x->sum(y, z);
                std::cout << *x << " + " << *y << " = " << *z << std::endl;
                break;
            }
            case 2: {
                std::cin >> *x;
                std::cin >> *y;

                Decimal *d_x = dynamic_cast<Decimal *>(x);
                if (d_x == nullptr)
                    throw BadCastException("Cannot cast Array* to Decimal*");
                Decimal *d_y = dynamic_cast<Decimal *>(y);
                if (d_y == nullptr)
                    throw BadCastException("Cannot cast Array* to Decimal*");
                Decimal *d_z = dynamic_cast<Decimal *>(z);
                if (d_z == nullptr)
                    throw BadCastException("Cannot cast Array* to Decimal*");

                *d_z = *d_x - *d_y;
                std::cout << *d_x << " - " << *d_y << " = " << *d_z << std::endl;
                break;
            }
            case 3: {
                std::cin >> *x;
                std::cin >> *y;

                Decimal *d_x = dynamic_cast<Decimal *>(x);
                if (d_x == nullptr)
                    throw BadCastException("Cannot cast Array* to Decimal*");
                Decimal *d_y = dynamic_cast<Decimal *>(y);
                if (d_y == nullptr)
                    throw BadCastException("Cannot cast Array* to Decimal*");
                Decimal *d_z = dynamic_cast<Decimal *>(z);
                if (d_z == nullptr)
                    throw BadCastException("Cannot cast Array* to Decimal*");

                *d_z = *d_x * *d_y;
                std::cout << *d_x << " * " << *d_y << " = " << *d_z << std::endl;
                break;
            }
            case 4: {
                std::cin >> *x;
                std::cin >> *y;

                Decimal *d_x = dynamic_cast<Decimal *>(x);
                if (d_x == nullptr)
                    throw BadCastException("Cannot cast Array* to Decimal*");
                Decimal *d_y = dynamic_cast<Decimal *>(y);
                if (d_y == nullptr)
                    throw BadCastException("Cannot cast Array* to Decimal*");
                Decimal *d_z = dynamic_cast<Decimal *>(z);
                if (d_z == nullptr)
                    throw BadCastException("Cannot cast Array* to Decimal*");

                *d_z = *d_x / *d_y;
                std::cout << *d_x << " / " << *d_y << " = " << *d_z << std::endl;
                break;
            }
            case 5: {
                std::cin >> *x;
                std::cin >> *y;

                Decimal *d_x = dynamic_cast<Decimal *>(x);
                if (d_x == nullptr)
                    throw BadCastException("Cannot cast Array* to Decimal*");
                Decimal *d_y = dynamic_cast<Decimal *>(y);
                if (d_y == nullptr)
                    throw BadCastException("Cannot cast Array* to Decimal*");

                if (*d_x > *d_y) {
                    std::cout << "x > y" << std::endl;
                } else if (*d_x == *d_y) {
                    std::cout << "x = y" << std::endl;
                } else {
                    std::cout << "x < y" << std::endl;
                }
                break;
            }
            default: {
                flag = false;
                break;
            }
        }
    } while (flag);
    delete x;
    delete y;
    delete z;
}

void Application::runOctal() {
    bool flag = true;
    x = new Octal;
    y = new Octal;
    z = new Octal;
    int b;
    do {
        std::cout << "1-array + array (overloaded)\n"
                     "2-decimal - decimal\n"
                     "3-decimal * decimal\n"
                     "4-decimal / decimal\n"
                     "5-Compare\n"
                     "6-Return" << std::endl;
        std::cin >> b;
        switch (b) {
            case 1: {
                std::cin >> *x;
                std::cin >> *y;

                x->sum(y, z);
                std::cout << *x << " + " << *y << " = " << *z << std::endl;
                break;
            }
            case 2: {
                std::cin >> *x;
                std::cin >> *y;

                Octal *d_x = dynamic_cast<Octal *>(x);
                if (d_x == nullptr)
                    throw BadCastException("Cannot cast Array* to Octal*");
                Octal *d_y = dynamic_cast<Octal *>(y);
                if (d_y == nullptr)
                    throw BadCastException("Cannot cast Array* to Octal*");
                Octal *d_z = dynamic_cast<Octal *>(z);
                if (d_z == nullptr)
                    throw BadCastException("Cannot cast Array* to Octal*");
                
                *d_z = *d_x - *d_y;
                std::cout << *d_x << " - " << *d_y << " = " << *d_z << std::endl;
                break;
            }
            case 3: {
                std::cin >> *x;
                std::cin >> *y;

                Octal *d_x = dynamic_cast<Octal *>(x);
                if (d_x == nullptr)
                    throw BadCastException("Cannot cast Array* to Octal*");
                Octal *d_y = dynamic_cast<Octal *>(y);
                if (d_y == nullptr)
                    throw BadCastException("Cannot cast Array* to Octal*");
                Octal *d_z = dynamic_cast<Octal *>(z);
                if (d_z == nullptr)
                    throw BadCastException("Cannot cast Array* to Octal*");

                *d_z = *d_x * *d_y;
                std::cout << *d_x << " * " << *d_y << " = " << *d_z << std::endl;
                break;
            }
            case 4: {
                std::cin >> *x;
                std::cin >> *y;

                Octal *d_x = dynamic_cast<Octal *>(x);
                if (d_x == nullptr)
                    throw BadCastException("Cannot cast Array* to Octal*");
                Octal *d_y = dynamic_cast<Octal *>(y);
                if (d_y == nullptr)
                    throw BadCastException("Cannot cast Array* to Octal*");
                Octal *d_z = dynamic_cast<Octal *>(z);
                if (d_z == nullptr)
                    throw BadCastException("Cannot cast Array* to Octal*");

                *d_z = *d_x / *d_y;
                std::cout << *d_x << " / " << *d_y << " = " << *d_z << std::endl;
                break;
            }
            case 5: {
                std::cin >> *x;
                std::cin >> *y;

                Octal *d_x = dynamic_cast<Octal *>(x);
                if (d_x == nullptr)
                    throw BadCastException("Cannot cast Array* to Octal*");
                Octal *d_y = dynamic_cast<Octal *>(y);
                if (d_y == nullptr)
                    throw BadCastException("Cannot cast Array* to Octal*");
                
                if (*d_x > *d_y) {
                    std::cout << "x > y" << std::endl;
                } else if (*d_x == *d_y) {
                    std::cout << "x = y" << std::endl;
                } else {
                    std::cout << "x < y" << std::endl;
                }
                break;
            }
            default: {
                flag = false;
                break;
            }
        }
    } while (flag);
    delete x;
    delete y;
    delete z;
}

void Application::run() {
    bool flag = true;
    do {
        std::cout << "1-Test Array (virtual methods)\n"
                     "2-Test Decimal\n"
                     "3-Test Octal\n"
                     "4-Return" << std::endl;
        int a;
        std::cin >> a;
        switch (a) {
            case 1: {
                runArray();
                break;
            }
            case 2: {
                runDecimal();
                break;
            }
            case 3: {
                runOctal();
                break;
            }
            default: {
                flag = false;
                break;
            }
        }
    } while (flag);
}
