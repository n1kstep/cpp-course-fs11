#ifndef HOMEWORK_C___BINARY_H
#define HOMEWORK_C___BINARY_H

#include "Integer.h"

class Binary : public Integer {
public:
    Binary() = default;
    explicit Binary(int size);
    Binary(int size, const unsigned int* arr);

    void sum(const Integer* ob, Integer* res) override;
    void sub(const Integer* ob, Integer* res) override;
    void mul(const Integer* ob, Integer* res) override;
    void div(const Integer* ob, Integer* res) override;

    void get_number() override;
    void set_number() override;
};


#endif //HOMEWORK_C___BINARY_H
