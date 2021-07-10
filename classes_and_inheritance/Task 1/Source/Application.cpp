#include "../Include/Application.h"

void Application::runMoney() {
    bool flag = true;
    Money x;
    Money y;
    Money z;
    int b;
    do {
        std::cout << "1-money + money\n"
                     "2-money - money\n"
                     "3-money / money\n"
                     "4-money / number\n"
                     "5-money * number\n"
                     "6-Compare\n"
                     "7-Return" << std::endl;
        std::cin >> b;
        switch (b) {
            case 1: {
                std::cin >> x;
                std::cin >> y;
                z = x + y;
                std::cout << x << " + " << y << " = " << z << std::endl;
                break;
            }
            case 2: {
                std::cin >> x;
                std::cin >> y;
                z = x - y;
                std::cout << x << " - " << y << " = " << z << std::endl;
                break;
            }
            case 3: {
                std::cin >> x;
                std::cin >> y;
                z = x / y;
                std::cout << x << " / " << y << " = " << z << std::endl;
                break;
            }
            case 4: {
                std::cin >> x;
                float num;
                std::cout << "Enter number" << std::endl;
                std::cin >> num;
                z = x / num;
                std::cout << x << " / " << num << " = " << z << std::endl;
                break;
            }
            case 5: {
                std::cin >> x;
                float num;
                std::cout << "Enter number" << std::endl;
                std::cin >> num;
                z = x * num;
                std::cout << x << " * " << num << " = " << z << std::endl;
                break;
            }
            case 6: {
                std::cin >> x;
                std::cin >> y;
                if (x > y) {
                    std::cout << "x > y" << std::endl;
                } else if (x == y) {
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
}

void Application::runPayment() {
    bool flag = true;
    Payment x;
    int b;
    do {
        std::cout << "1-Enter object\n"
                     "2-Count accrued sum\n"
                     "3-Count withheld sum\n"
                     "4-Count sum\n"
                     "5-Count experience\n"
                     "6-Output object\n"
                     "7-Return" << std::endl;
        std::cin >> b;
        switch (b) {
            case 1: {
                std::cin >> x;
                break;
            }
            case 2: {
                std::cout << x.count_accrued() << std::endl;
                break;
            }
            case 3: {
                std::cout << x.count_withheld() << std::endl;
                break;
            }
            case 4: {
                std::cout << x.count_sum() << std::endl;
                break;
            }
            case 5: {
                std::cout << x.count_experience() << std::endl;
                break;
            }
            case 6: {
                std::cout << x << std::endl;
                break;
            }
            default: {
                flag = false;
                break;
            }
        }
    } while (flag);
}

void Application::run() {
    bool flag = true;
    do {
        std::cout << "1-Test Money\n"
                     "2-Test Payment\n"
                     "3-Return" << std::endl;
        int a;
        std::cin >> a;
        switch (a) {
            case 1: {
                runMoney();
                break;
            }
            case 2: {
                runPayment();
                break;
            }
            default: {
                flag = false;
                break;
            }
        }
    } while (flag);
}
