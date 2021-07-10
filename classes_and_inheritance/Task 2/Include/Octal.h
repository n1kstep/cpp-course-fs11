#ifndef CLASSES_AND_INHERITANCE_OCTAL_H
#define CLASSES_AND_INHERITANCE_OCTAL_H

#include "Array.h"

class Octal : public Array {
public:
    Octal() = default;
    explicit Octal(int size);
    Octal(int size, const unsigned char *arr);

    void sum(const Array* a, Array* res) override;

    Octal operator-(const Octal &d1);
    Octal operator*(const Octal &d1);
    Octal operator/(const Octal &d1);

    friend std::ostream& operator<<(std::ostream& out, const Octal& d);
    friend std::istream& operator>>(std::istream& in, Octal& d);

    bool operator>(const Octal &d);
    bool operator<(const Octal &d);
    bool operator==(const Octal &d);
    bool operator>=(const Octal &d);
    bool operator<=(const Octal &d);
};


#endif //CLASSES_AND_INHERITANCE_OCTAL_H
