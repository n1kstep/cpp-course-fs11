#include "Task 2/Include/Octal.h"
#include "Exceptions.h"

Octal::Octal(int size) : Array(size)
{}

Octal::Octal(int size, const unsigned char *arr) : Array(size, arr)
{}

int to_int8(int size, unsigned char *arr) {
    int tmp = 1;
    int num = 0;
    for (int i = 0; i < size; i++) {
        num += tmp * (arr[i] - '0');
        tmp *= 8;
    }
    return num;
}

void Octal::sum(const Array *a, Array *res) {
    const Octal *d = dynamic_cast<const Octal *>(a);
    if (d == nullptr)
        throw BadCastException("Cannot cast Array* to Octal*");
    Octal *d_res = dynamic_cast<Octal *>(res);
    if (d_res == nullptr)
        throw BadCastException("Cannot cast Array* to Octal*");

    int num_1 = to_int8(m_size, m_arr);
    int num_2 = to_int8(d->m_size, d->m_arr);
    int sum = num_1 + num_2;
    int tmp = sum;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 8;
        cnt++;
    }
    d_res->m_size = cnt;
    for (int i = 0; i < d_res->m_size; i++) {
        d_res->m_arr[i] = (sum % 8) + '0';
        sum /= 8;
    }
}

Octal Octal::operator-(const Octal &d) {
    Octal res;
    int num_1 = to_int8(m_size, m_arr);
    int num_2 = to_int8(d.m_size, d.m_arr);
    int sub = num_1 - num_2;
    if (sub < 0)
        throw NegativeNumberException("Invalid difference < 0");
    int tmp = sub;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 8;
        cnt++;
    }
    res.m_size = cnt;
    for (int i = 0; i < res.m_size; i++) {
        res.m_arr[i] = (sub % 8) + '0';
        sub /= 8;
    }
    return res;
}

Octal Octal::operator*(const Octal &d) {
    Octal res;
    int num_1 = to_int8(m_size, m_arr);
    int num_2 = to_int8(d.m_size, d.m_arr);
    int sum = num_1 * num_2;
    int tmp = sum;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 8;
        cnt++;
    }
    res.m_size = cnt;
    for (int i = 0; i < res.m_size; i++) {
        res.m_arr[i] = (sum % 8) + '0';
        sum /= 8;
    }
    return res;
}

Octal Octal::operator/(const Octal &d) {
    Octal result;
    Octal res;
    int num_1 = to_int8(m_size, m_arr);
    int num_2 = to_int8(d.m_size, d.m_arr);
    if (num_2 == 0)
        throw DivisionByZeroException("Invalid division by 0");
    int sum = num_1 / num_2;
    int tmp = sum;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 8;
        cnt++;
    }
    res.m_size = cnt;
    for (int i = 0; i < res.m_size; i++) {
        res.m_arr[i] = (sum % 8) + '0';
        sum /= 8;
    }
    return res;
}

std::ostream &operator<<(std::ostream &out, const Octal &d) {
    out << '(';
    for (int i = 0; i < d.m_size; i++)
        if (i == d.m_size - 1)
            out << d[i] << ')';
        else
            out << d[d.m_size - 1 - i] << ", ";
    return out;
}

std::istream &operator>>(std::istream &in, Octal &d) {
    std::cout << "Enter size:" << std::endl;
    in >> d.m_size;
    std::cout << "Enter elements:" << std::endl;
    for (int i = 0; i < d.m_size; i++) {
        in >> d[d.m_size - 1 - i];
    }
    return in;
}

bool Octal::operator>(const Octal &d) {
    if (m_size != d.m_size)
        return m_size > d.m_size;
    else
        for (int i = m_size - 1; i >= 0; --i)
            if (m_arr[i] != d[i])
                return m_arr[i] > d[i];
    return false;
}

bool Octal::operator<(const Octal &d) {
    if (m_size != d.m_size)
        return m_size < d.m_size;
    else
        for (int i = m_size - 1; i >= 0; --i)
            if (m_arr[i] != d[i])
                return m_arr[i] < d[i];
    return false;
}

bool Octal::operator==(const Octal &d) {
    if (m_size != d.m_size)
        return false;
    else
        for (int i = m_size - 1; i >= 0; --i)
            if (m_arr[i] != d[i])
                return false;
    return true;
}

bool Octal::operator>=(const Octal &d) {
    return (*this > d) | (*this == d);
}

bool Octal::operator<=(const Octal &d) {
    return (*this < d) | (*this == d);
}