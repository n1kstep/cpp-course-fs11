#include "../Include/Binary.h"
#include "../Include/Exceptions.h"
#include "iostream"

Binary::Binary(int size)
        : Integer(size)
{}

Binary::Binary(int size, const unsigned int *arr)
        : Integer(size, arr)
{}

void Binary::sum(const Integer *ob, Integer *res) {
    int tmp = 1;
    int num_1 = 0;
    for (int i = 0; i < m_size; i++) {
        num_1 += tmp * (int) m_arr[i];
        tmp *= 2;
    }
    tmp = 1;
    int num_2 = 0;
    for (int i = 0; i < ob->get_size(); i++) {
        num_2 += tmp * (int) (*ob)[i];
        tmp *= 2;
    }
    int sum = num_1 + num_2;
    tmp = sum;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 2;
        cnt++;
    }
    res->set_size(cnt);
    for (int i = 0; i < res->get_size(); i++) {
        (*res)[i] = (sum % 2);
        sum /= 2;
    }
}

void Binary::sub(const Integer *ob, Integer *res) {
    int tmp = 1;
    int num_1 = 0;
    for (int i = 0; i < m_size; i++) {
        num_1 += tmp * (int) m_arr[i];
        tmp *= 2;
    }
    tmp = 1;
    int num_2 = 0;
    for (int i = 0; i < ob->get_size(); i++) {
        num_2 += tmp * (int) (*ob)[i];
        tmp *= 2;
    }
    int sub = num_1 - num_2;
    tmp = sub;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 2;
        cnt++;
    }
    res->set_size(cnt);
    for (int i = 0; i < res->get_size(); i++) {
        (*res)[i] = (sub % 2);
        sub /= 2;
    }
}

void Binary::mul(const Integer *ob, Integer *res) {
    int tmp = 1;
    int num_1 = 0;
    for (int i = 0; i < m_size; i++) {
        num_1 += tmp * (int) m_arr[i];
        tmp *= 2;
    }
    tmp = 1;
    int num_2 = 0;
    for (int i = 0; i < ob->get_size(); i++) {
        num_2 += tmp * (int) (*ob)[i];
        tmp *= 2;
    }
    int mul = num_1 * num_2;
    tmp = mul;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 2;
        cnt++;
    }
    res->set_size(cnt);
    for (int i = 0; i < res->get_size(); i++) {
        (*res)[i] = (mul % 2);
        mul /= 2;
    }
}

void Binary::div(const Integer *ob, Integer *res) {
    int tmp = 1;
    int num_1 = 0;
    for (int i = 0; i < m_size; i++) {
        num_1 += tmp * (int) m_arr[i];
        tmp *= 2;
    }
    tmp = 1;
    int num_2 = 0;
    for (int i = 0; i < ob->get_size(); i++) {
        num_2 += tmp * (int) (*ob)[i];
        tmp *= 2;
    }
    if (num_2 == 0)
        throw DivisionByZeroException("Invalid division by 0");
    int div = num_1 / num_2;
    tmp = div;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 2;
        cnt++;
    }
    res->set_size(cnt);
    for (int i = 0; i < res->get_size(); i++) {
        (*res)[i] = (div % 2);
        div /= 2;
    }
}

void Binary::get_number() {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_arr[m_size - 1 - i] << ' ';
    }
    std::cout << std::endl;
}

void Binary::set_number() {
    std::cout << "Enter size:" << std::endl;
    std::cin >> m_size;
    delete[] m_arr;
    m_arr = new unsigned int[m_size];
    std::cout << "Enter elements:" << std::endl;
    for (int i = 0; i < m_size; i++) {
        std::cin >> m_arr[m_size - 1 - i];
    }
}
