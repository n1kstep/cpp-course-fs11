#pragma once

#include "Container.h"
#include "Exceptions.h"

template<class DataType>
struct Node;

template<class DataType>
class List;

template<class DataType>
class ListIterator {
private:
    friend class List<DataType>;
    Node<DataType> *m_ptr;
public:
    ListIterator(const List<DataType> &d, int ind) {
        if ((ind > d.m_size) || (ind < 0))
            throw IteratorException("Index is out of range!");
        m_ptr = d.m_head;
        for (int i = 0; i < ind; ++i) {
            m_ptr = m_ptr->next;
        }
    }

    ListIterator(const ListIterator &di) :
            m_ptr(di.m_ptr) {}

    ListIterator<DataType> &operator++() {
        if (m_ptr == nullptr)
            throw IteratorException("Invalid operation ++ with nullptr!");
        m_ptr = m_ptr->next;
        return *this;
    }

    ListIterator<DataType> &operator--() {
        if (m_ptr == nullptr)
            throw IteratorException("Invalid operation -- with nullptr!");
        m_ptr = m_ptr->prev;
        return *this;
    }

    ListIterator<DataType> operator++(int) {
        if (m_ptr == nullptr)
            throw IteratorException("Invalid operation ++ with nullptr!");
        auto cur(*this);
        m_ptr = m_ptr->next;
        return cur;
    }

    ListIterator<DataType> operator--(int) {
        if (m_ptr == nullptr)
            throw IteratorException("Invalid operation -- with nullptr!");
        auto cur(*this);
        m_ptr = m_ptr->prev;
        return cur;
    }

    DataType &operator*() const noexcept {
        if (m_ptr == nullptr)
            throw IteratorException("Invalid operation * with nullptr!");
        return m_ptr->data;
    }

    ListIterator<DataType> &operator=(const ListIterator &d) {
        if (this != &d) {
            m_ptr = d.m_ptr;
        }
        return *this;
    }

    bool operator==(const ListIterator<DataType> &d) const noexcept {
        return m_ptr == d.m_ptr;
    }

    bool operator!=(const ListIterator<DataType> &d) const noexcept {
        return m_ptr != d.m_ptr;
    }

    DataType *operator->() const noexcept {
        return &m_ptr->data;
    }
};
