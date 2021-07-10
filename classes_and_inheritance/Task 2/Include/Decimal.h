#ifndef CLASSES_AND_INHERITANCE_DECIMAL_H
#define CLASSES_AND_INHERITANCE_DECIMAL_H

#include "Array.h"

class Decimal : public Array {
public:
    Decimal() = default;
    explicit Decimal(int size);
    Decimal(int size, const unsigned char *arr);

    void sum(const Array* a, Array* res) override;

    Decimal operator-(const Decimal &d1);
    Decimal operator*(const Decimal &d1);
    Decimal operator/(const Decimal &d1);

    friend std::ostream& operator<<(std::ostream& out, const Decimal& d);
    friend std::istream& operator>>(std::istream& in, Decimal& d);

    bool operator>(const Decimal &d);
    bool operator<(const Decimal &d);
    bool operator==(const Decimal &d);
    bool operator>=(const Decimal &d);
    bool operator<=(const Decimal &d);
};


#endif //CLASSES_AND_INHERITANCE_DECIMAL_H
