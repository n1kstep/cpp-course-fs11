#ifndef HOMEWORK_C___DECIMAL_H
#define HOMEWORK_C___DECIMAL_H

#include "Integer.h"

class Decimal : public Integer {
public:
    Decimal() = default;
    explicit Decimal(int size);
    Decimal(int size, const unsigned int* arr);

    void sum(const Integer* ob, Integer* res) override;
    void sub(const Integer* ob, Integer* res) override;
    void mul(const Integer* ob, Integer* res) override;
    void div(const Integer* ob, Integer* res) override;

    void get_number() override;
    void set_number() override;
};


#endif //HOMEWORK_C___DECIMAL_H
