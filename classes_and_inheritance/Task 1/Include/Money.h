#ifndef CLASSES_AND_INHERITANCE_MONEY_H
#define CLASSES_AND_INHERITANCE_MONEY_H

#include "iostream"

class Money {
private:
    static int m_amount;
    long m_integral;
    unsigned char m_frac;
public:
    explicit Money(float num);
    explicit Money(int integral = 0, int frac = 0);
    ~Money();
    int get_amount() const;

    friend Money operator+(const Money& m1, const Money& m2);
    friend Money operator-(const Money& m1, const Money& m2);
    friend Money operator*(const Money& m1, float num);
    friend Money operator*(float num, const Money& f1);
    friend Money operator/(const Money& m1, float num);
    friend float operator/(const Money& m1, const Money& m2);

    friend std::istream& operator>>(std::istream& in, Money& m);
    friend std::ostream& operator<<(std::ostream& out, const Money& m);

    friend bool operator>(const Money &m1, const Money &m2);
    friend bool operator>=(const Money &m1, const Money &m2);
    friend bool operator<(const Money &m1, const Money &m2);
    friend bool operator<=(const Money &m1, const Money &m2);
    friend bool operator==(const Money &m1, const Money &m2);
};


#endif //CLASSES_AND_INHERITANCE_MONEY_H
