#ifndef CLASSES_AND_INHERITANCE_ARRAY_H
#define CLASSES_AND_INHERITANCE_ARRAY_H

#include <iostream>

class Array {
protected:
    unsigned char *m_arr;
    int m_size;
    const static int max_size = 100;
public:
    explicit Array(int size = 0);
    Array(int size, const unsigned char* arr);
    Array(const Array &a);
    virtual ~Array();
    Array& operator=(const Array& ob);

    unsigned char &operator[](int i);
    const unsigned char &operator[](int i) const;

    virtual void sum(const Array* a, Array* res);

    friend std::ostream& operator<<(std::ostream& out, const Array& a);
    friend std::istream& operator>>(std::istream& in, Array& a);

    unsigned int get_size() const;
};


#endif //CLASSES_AND_INHERITANCE_ARRAY_H
