#include "Task 2/Include/Decimal.h"
#include "Exceptions.h"

Decimal::Decimal(int size) : Array(size)
{}

Decimal::Decimal(int size, const unsigned char *arr) : Array(size, arr)
{}

int to_int(int size, const unsigned char *arr) {
    int tmp = 1;
    int num = 0;
    for (int i = 0; i < size; i++) {
        num += tmp * (arr[i] - '0');
        tmp *= 10;
    }
    return num;
}

void Decimal::sum(const Array *a, Array *res) {
    const Decimal *d = dynamic_cast<const Decimal *>(a);
    if (d == nullptr)
        throw BadCastException("Cannot cast Array* to Decimal*");
    Decimal *d_res = dynamic_cast<Decimal *>(res);
    if (d_res == nullptr)
        throw BadCastException("Cannot cast Array* to Decimal*");
    
    int num_1 = to_int(m_size, m_arr);
    int num_2 = to_int(d->m_size, d->m_arr);
    int sum = num_1 + num_2;
    int tmp = sum;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 10;
        cnt++;
    }
    d_res->m_size = cnt;
    for (int i = 0; i < d_res->m_size; i++) {
        d_res->m_arr[i] = (sum % 10) + '0';
        sum /= 10;
    }
}

Decimal Decimal::operator-(const Decimal &d) {
    Decimal res;
    int num_1 = to_int(m_size, m_arr);
    int num_2 = to_int(d.m_size, d.m_arr);
    int sub = num_1 - num_2;
    int tmp = sub;
    if (sub < 0)
        throw NegativeNumberException("Invalid difference < 0");
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 10;
        cnt++;
    }
    res.m_size = cnt;
    for (int i = 0; i < res.m_size; i++) {
        res.m_arr[i] = (sub % 10) + '0';
        sub /= 10;
    }
    return res;
}

Decimal Decimal::operator*(const Decimal &d) {
    Decimal res;
    int num_1 = to_int(m_size, m_arr);
    int num_2 = to_int(d.m_size, d.m_arr);
    int mul = num_1 * num_2;
    int tmp = mul;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 10;
        cnt++;
    }
    res.m_size = cnt;
    for (int i = 0; i < res.m_size; i++) {
        res.m_arr[i] = (mul % 10) + '0';
        mul /= 10;
    }
    return res;
}

Decimal Decimal::operator/(const Decimal &d) {
    Decimal result;
    Decimal res;
    int num_1 = to_int(m_size, m_arr);
    int num_2 = to_int(d.m_size, d.m_arr);
    if (num_2 == 0)
        throw DivisionByZeroException("Invalid division by 0");
    int div = num_1 / num_2;
    int tmp = div;
    int cnt = 0;
    while (tmp != 0) {
        tmp /= 10;
        cnt++;
    }
    res.m_size = cnt;
    for (int i = 0; i < res.m_size; i++) {
        res.m_arr[i] = (div % 10) + '0';
        div /= 10;
    }
    return res;
}

std::ostream &operator<<(std::ostream &out, const Decimal &d) {
    out << '(';
    for (int i = 0; i < d.m_size; i++)
        if (i == d.m_size - 1)
            out << d[i] << ')';
        else
            out << d[d.m_size - 1 - i] << ", ";
    return out;
}

std::istream &operator>>(std::istream &in, Decimal &d) {
    std::cout << "Enter size:" << std::endl;
    in >> d.m_size;
    std::cout << "Enter elements:" << std::endl;
    for (int i = 0; i < d.m_size; i++) {
        in >> d[d.m_size - 1 - i];
    }
    return in;
}

bool Decimal::operator>(const Decimal &d) {
    if (m_size != d.m_size)
        return m_size > d.m_size;
    else
        for (int i = m_size - 1; i >= 0; --i)
            if (m_arr[i] != d[i])
                return m_arr[i] > d[i];
    return false;
}

bool Decimal::operator<(const Decimal &d) {
    if (m_size != d.m_size)
        return m_size < d.m_size;
    else
        for (int i = m_size - 1; i >= 0; --i)
            if (m_arr[i] != d[i])
                return m_arr[i] < d[i];
    return false;
}

bool Decimal::operator==(const Decimal &d) {
    if (m_size != d.m_size)
        return false;
    else
        for (int i = m_size - 1; i >= 0; --i)
            if (m_arr[i] != d[i])
                return false;
    return true;
}

bool Decimal::operator>=(const Decimal &d) {
    return (*this > d) | (*this == d);
}

bool Decimal::operator<=(const Decimal &d) {
    return (*this < d) | (*this == d);
}