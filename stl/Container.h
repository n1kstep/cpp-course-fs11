#pragma once

#include <initializer_list>
#include "Iterator.h"
#include "Exceptions.h"

template<class DataType>
class ListIterator;

template<class DataType>
struct Node {
    DataType data;
    Node *next;
    Node *prev;
};

template<class DataType>
class List {
private:
    friend class ListIterator<DataType>;
    Node<DataType> *m_head;
    Node<DataType> *m_tail;
    int m_size;
public:
    using iterator = ListIterator<DataType>;

    List() : m_size(0), m_head(nullptr), m_tail(nullptr) {}

    explicit List(int size, const DataType &elem = DataType()) {
        if (size < 0) {
            throw ContainerException("Size is out of range!");
        }
        m_size = 0;
        m_head = nullptr;
        m_tail = nullptr;
        for (int i = 0; i < size; ++i) {
            pushBack(elem);
        }
    }

    template <class IterType>
    List(iterator beg, IterType end) {
        m_size = 0;
        m_head = nullptr;
        m_tail = nullptr;
        for (auto iter = beg(); iter != end; ++iter) {
            pushBack(*iter);
        }
    }

    List(const std::initializer_list<DataType> &lst) {
        m_size = 0;
        m_head = nullptr;
        m_tail = nullptr;
        for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
            pushBack(*iter);
        }
    }

    List(const List &d) {
        for (auto iter = d.begin(); iter != d.end(); ++iter) {
            pushBack(*iter);
        }
    }

    List(List &&d) noexcept: m_size(d.m_size), m_head(d.m_head), m_tail(d.m_tail) {
        d.m_size = 0;
        d.m_head = nullptr;
        d.m_tail = nullptr;
    }

    ~List() {
        clear();
    }

    List& operator=(const List &d) {
        if (this != &d) {
            clear();
            for (auto iter = d.begin(); iter != d.end(); ++iter) {
                pushBack(*iter);
            }
        }
        return *this;
    }

    List& operator=(List &&d) noexcept {
        if (this != &d) {
            clear();
            m_size = d.m_size;
            m_head = d.m_head;
            m_tail = d.m_tail;

            d.m_size = 0;
            d.m_head = nullptr;
            d.m_tail = nullptr;
        }
        return *this;
    }

    iterator begin() {
        if ((m_head == nullptr) || (m_tail == nullptr)) {
            throw ContainerException("Container is empty!");
        }
        return iterator(*this, 0);
    }

    iterator end() {
        if ((m_head == nullptr) || (m_tail == nullptr)) {
            throw ContainerException("Container is empty!");
        }
        return iterator(*this, m_size - 1);
    }

    void pushBack(const DataType &elem) {
        if (m_size == 0) {
            m_head = new Node<DataType>;
            m_head->data = elem;
            m_head->prev = nullptr;
            m_tail = m_head;
            m_size++;

            auto tmp = new Node<DataType>;
            tmp->data = DataType();
            tmp->next = nullptr;
            tmp->prev = m_head;
            m_head->next = tmp;
            m_size++;
        } else {
            auto *cur = new Node<DataType>;
            cur->data = elem;
            cur->next = m_tail->next;
            cur->prev = m_tail;
            m_tail->next->prev = cur;
            m_tail->next = cur;
            m_tail = cur;
            m_size++;
        }
    }

    void popBack() {
        if (m_size == 0) {
            throw ContainerException("Container is empty!");
        }
        if (m_size == 2) {
            delete m_head->next;
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
            m_size = 0;
        } else if (m_size > 2) {
            Node<DataType> *cur = m_tail;
            m_tail = m_tail->prev;
            m_tail->next = cur->next;
            cur->next->prev = m_tail;
            delete cur;
            m_size--;
        }
    }

    void pushFront(const DataType &elem) {
        if (m_size == 0) {
            m_head = new Node<DataType>;
            m_head->data = elem;
            m_head->prev = nullptr;
            m_tail = m_head;
            m_size++;

            auto tmp = new Node<DataType>;
            tmp->data = DataType();
            tmp->next = nullptr;
            tmp->prev = m_head;
            m_head->next = tmp;
            m_size++;
        } else {
            auto *cur = new Node<DataType>;
            m_head->prev = cur;
            cur->data = elem;
            cur->next = m_head;
            cur->prev = nullptr;
            m_head = cur;
            m_size++;
        }
    }

    void popFront() {
        if (m_size == 0) {
            throw ContainerException("Container is empty!");
        }
        if (m_size == 2) {
            delete m_head->next;
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
            m_size = 0;
        } else if (m_size > 2) {
            Node<DataType> *cur = m_head;
            m_head = m_head->next;
            m_head->prev = nullptr;
            delete cur;
            m_size--;
        }
    }

    iterator insert(iterator pos, const DataType &elem) {
        if (pos == begin()) {
            pushFront(elem);
            return begin();
        }
        else if (pos == end()) {
            pushBack(elem);
            return end();
        }
        else {
            auto* tmp = new Node<DataType>{elem, pos.m_ptr, pos.m_ptr->prev};
            tmp->next->prev = tmp;
            tmp->prev->next = tmp;
            ++m_size;
            return pos--;
        }
    }

    template <class IterType>
    iterator insert(IterType pos, IterType beg, IterType end) {
        iterator res = pos;
        for (; beg != end; ++beg) {
            if (res == pos)
                res = insert(pos, *beg);
            else
                insert(pos, *beg);
        }
        return res;
    }

    iterator erase(iterator pos) {
        if (pos == begin()) {
            popFront();
            return begin();
        }
        else if (pos == end()) {
            popBack();
            return end();
        }
        else {
            auto res = pos + 1;
            pos.m_ptr->next->prev = pos.m_ptr->prev;
            pos.m_ptr->prev->next = pos.m_ptr->next;
            delete pos.m_ptr;
            --m_size;
            return res;
        }
    }

    void resize(int num) {
        if (num > m_size) {
            for (int i = m_size; i < num; ++i) {
                pushBack(DataType());
            }
        }
        else {
            for (int i = num; i < m_size; ++i) {
                popBack();
            }
        }
    }

    bool empty() const {
        return m_size == 0;
    }

    int size() const {
        return m_size;
    }

    void clear() {
        while (m_head != nullptr) {
            Node<DataType> *cur = m_head;
            m_head = m_head->next;
            delete cur;
        }
        m_size = 0;
        m_head = nullptr;
        m_tail = nullptr;
    }
};
