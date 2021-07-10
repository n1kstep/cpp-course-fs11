#include "../Include/Application.h"
#include "../Include/Exceptions.h"

void Application::runDecimal() {
    bool flag = true;

    x = new Decimal;
    y = new Decimal;
    z = new Decimal;

    int b;
    do {
        std::cout << "1-decimal + decimal (overloaded integer)\n"
                     "2-decimal - decimal (overloaded integer)\n"
                     "3-decimal * decimal (overloaded integer)\n"
                     "4-decimal / decimal (overloaded integer)\n"
                     "5-Return" << std::endl;
        std::cin >> b;
        switch (b) {
            case 1: {
                x->set_number();
                y->set_number();
                x->sum(y, z);
                std::cout << "x + y = " << std::endl;
                z->get_number();
                break;
            }
            case 2: {
                x->set_number();
                y->set_number();
                x->sub(y, z);
                std::cout << "x - y = " << std::endl;
                z->get_number();
                break;
            }
            case 3: {
                x->set_number();
                y->set_number();
                x->mul(y, z);
                std::cout << "x * y = " << std::endl;
                z->get_number();
                break;
            }
            case 4: {
                x->set_number();
                y->set_number();
                x->div(y, z);
                std::cout << "x / y = " << std::endl;
                z->get_number();
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

void Application::runBinary() {
    bool flag = true;

    x = new Binary;
    y = new Binary;
    z = new Binary;

    int b;
    do {
        std::cout << "1-binary + binary (overloaded integer)\n"
                     "2-binary - binary (overloaded integer)\n"
                     "3-binary * binary (overloaded integer)\n"
                     "4-binary / binary (overloaded integer)\n"
                     "5-Return" << std::endl;
        std::cin >> b;
        switch (b) {
            case 1: {
                x->set_number();
                y->set_number();
                x->sum(y, z);
                std::cout << "x + y = " << std::endl;
                z->get_number();
                break;
            }
            case 2: {
                x->set_number();
                y->set_number();
                x->sub(y, z);
                std::cout << "x - y = " << std::endl;
                z->get_number();
                break;
            }
            case 3: {
                x->set_number();
                y->set_number();
                x->mul(y, z);
                std::cout << "x * y = " << std::endl;
                z->get_number();
                break;
            }
            case 4: {
                x->set_number();
                y->set_number();
                x->div(y, z);
                std::cout << "x / y = " << std::endl;
                z->get_number();
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
        std::cout << "1-Test Decimal\n"
                     "2-Test Binary\n"
                     "3-Return" << std::endl;
        int a;
        std::cin >> a;
        switch (a) {
            case 1: {
                runDecimal();
                break;
            }
            case 2: {
                runBinary();
                break;
            }
            default: {
                flag = false;
                break;
            }
        }
    } while (flag);
}