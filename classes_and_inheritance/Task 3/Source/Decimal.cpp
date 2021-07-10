#include "../Include/Decimal.h"
#include "../Include/Exceptions.h"
#include "iostream"

Decimal::Decimal(int size)
        : Integer(size)
{}

Decimal::Decimal(int size, const unsigned int *arr)
        : Integer(size, arr)
{}

void Decimal::sum(const Integer *ob, Integer *res) {
    int tmp = 1;
    int num_1 = 0;
    for (int i = 0; i < m_size; i++) {
        num_1 += tmp * (int) m_arr[i];
        tmp *= 10;
    }
    tmp = 1;
    int num_2 = 0;
    for (int i = 0; i < ob->get_size(); i++) {
        num_2 += tmp * (int) (*ob)[i];
        tmp *= 10;
    }
    int sum = num_1 + num_2;
    tmp = sum;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 10;
        cnt++;
    }
    res->set_size(cnt);
    for (int i = 0; i < res->get_size(); i++) {
        (*res)[i] = (sum % 10);
        sum /= 10;
    }
}

void Decimal::sub(const Integer *ob, Integer *res) {
    int tmp = 1;
    int num_1 = 0;
    for (int i = 0; i < m_size; i++) {
        num_1 += tmp * (int) m_arr[i];
        tmp *= 10;
    }
    tmp = 1;
    int num_2 = 0;
    for (int i = 0; i < ob->get_size(); i++) {
        num_2 += tmp * (int) (*ob)[i];
        tmp *= 10;
    }
    int sub = num_1 - num_2;
    tmp = sub;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 10;
        cnt++;
    }
    res->set_size(cnt);
    for (int i = 0; i < res->get_size(); i++) {
        (*res)[i] = (sub % 10);
        sub /= 10;
    }
}

void Decimal::mul(const Integer *ob, Integer *res) {
    int tmp = 1;
    int num_1 = 0;
    for (int i = 0; i < m_size; i++) {
        num_1 += tmp * (int) m_arr[i];
        tmp *= 10;
    }
    tmp = 1;
    int num_2 = 0;
    for (int i = 0; i < ob->get_size(); i++) {
        num_2 += tmp * (int) (*ob)[i];
        tmp *= 10;
    }
    int mul = num_1 * num_2;
    tmp = mul;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 10;
        cnt++;
    }
    res->set_size(cnt);
    for (int i = 0; i < res->get_size(); i++) {
        (*res)[i] = (mul % 10);
        mul /= 10;
    }
}

void Decimal::div(const Integer *ob, Integer *res) {
    int tmp = 1;
    int num_1 = 0;
    for (int i = 0; i < m_size; i++) {
        num_1 += tmp * (int) m_arr[i];
        tmp *= 10;
    }
    tmp = 1;
    int num_2 = 0;
    for (int i = 0; i < ob->get_size(); i++) {
        num_2 += tmp * (int) (*ob)[i];
        tmp *= 10;
    }
    if (num_2 == 0)
        throw DivisionByZeroException("Invalid division by 0");
    int div = num_1 / num_2;
    tmp = div;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 10;
        cnt++;
    }
    res->set_size(cnt);
    for (int i = 0; i < res->get_size(); i++) {
        (*res)[i] = (div % 10);
        div /= 10;
    }
}

void Decimal::get_number() {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_arr[m_size - 1 - i] << ' ';
    }
    std::cout << std::endl;
}

void Decimal::set_number() {
    std::cout << "Enter size:" << std::endl;
    std::cin >> m_size;
    delete[] m_arr;
    m_arr = new unsigned int[m_size];
    std::cout << "Enter elements:" << std::endl;
    for (int i = 0; i < m_size; i++) {
        std::cin >> m_arr[m_size - 1 - i];
    }
}