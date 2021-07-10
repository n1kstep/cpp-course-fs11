#include "Task 2/Include/Array.h"
#include "Exceptions.h"

Array::Array(int size) {
    if (size < 0 || size > 100)
        throw OutOfRangeException("Invalid size of Array");
    m_size = size;
    m_arr = new unsigned char[max_size];
    for (int i = 0; i < max_size; i++)
        m_arr[i] = 0;
}

Array::Array(int size, const unsigned char *arr) {
    if (size < 0 || size > 100)
        throw OutOfRangeException("Invalid size of Array");
    m_size = size;
    m_arr = new unsigned char[max_size];
    for (int i = size; i < max_size; i++)
        m_arr[i] = 0;
    for (int i = 0; i < size; i++)
        m_arr[i] = arr[m_size - 1 - i] + '0';
}


Array::Array(const Array &a) : Array(a.m_size) {
    for (int i = 0; i < a.m_size; ++i)
        m_arr[i] = a[i];
}

Array::~Array() {
    delete[] m_arr;
}

Array& Array::operator=(const Array& ob)
{
    if (this == &ob)
        return *this;
    if (m_size != ob.m_size)
    {
        delete[] m_arr;
        m_arr = new unsigned char[ob.m_size];
        m_size = ob.m_size;
    }
    for (int i = 0; i < m_size; i++) {
        m_arr[i] = ob.m_arr[i];
    }
    return *this;
}

unsigned char &Array::operator[](int i) {
    if (i >= 0 & i < m_size)
        return m_arr[i];
    else
        throw OutOfRangeException("Invalid index");
}

const unsigned char &Array::operator[](int i) const {
    if (i >= 0 & i < m_size)
        return m_arr[i];
    else
        throw OutOfRangeException("Invalid index");
}

void Array::sum(const Array *a, Array *res) {
    if (m_size != a->m_size)
        throw IncompatibleDimException("Arrays have different size");
    res->m_size = m_size;
    for (int i = 0; i < a->m_size; i++) {
        int e = a->m_arr[i] - '0' + m_arr[i] - '0';
        res->m_arr[i] = e + '0';
    }
}

std::ostream &operator<<(std::ostream &out, const Array &a) {
    out << '(';
    for (int i = 0; i < a.m_size; i++)
        if (i == a.m_size - 1)
            out << (int) a[a.m_size - 1 - i] - 48 << ')';
        else
            out << (int) a[a.m_size - 1 - i] - 48 << ", ";
    return out;
}

std::istream &operator>>(std::istream &in, Array &a) {
    std::cout << "Enter size:" << std::endl;
    in >> a.m_size;
    std::cout << "Enter elements:" << std::endl;
    for (int i = 0; i < a.m_size; i++) {
        in >> a[a.m_size - 1 - i];
    }
    return in;
}

unsigned int Array::get_size() const {
    return m_size;
}