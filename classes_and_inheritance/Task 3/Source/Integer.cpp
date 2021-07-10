#include "../Include/Integer.h"
#include "../Include/Exceptions.h"

Integer::Integer() : m_size(0), m_arr(nullptr) {}

Integer::Integer(int size) {
    if (size < 0)
        throw OutOfRangeException("Invalid size of Array");
    m_size = size;
    m_arr = new unsigned int[size];
    for (int i = 0; i < size; i++)
        m_arr[i] = 0;
}

Integer::Integer(int size, const unsigned int *arr) {
    if (size < 0)
        throw OutOfRangeException("Invalid size of Array");
    m_size = size;
    m_arr = new unsigned int[size];
    for (int i = 0; i < size; i++)
        m_arr[i] = arr[i];
}

Integer::Integer(const Integer &ob) : m_size(ob.m_size) {
    m_arr = new unsigned int[ob.m_size];
    for (int i = 0; i < ob.m_size; ++i)
        m_arr[i] = ob.m_arr[i];
}

Integer& Integer::operator=(const Integer& ob)
{
    if (this == &ob)
        return *this;
    if (m_size != ob.m_size)
    {
        delete[] m_arr;
        m_arr = new unsigned int[ob.m_size];
        m_size = ob.m_size;
    }
    for (int i = 0; i < m_size; i++) {
        m_arr[i] = ob.m_arr[i];
    }
    return *this;
}

Integer::~Integer() {
    delete[] m_arr;
}
