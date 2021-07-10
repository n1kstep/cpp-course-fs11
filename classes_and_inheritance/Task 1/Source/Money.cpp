#include "../Include/Money.h"

int Money::m_amount = 0;

Money::Money(float num) {
    m_integral = (int) num;
    m_frac = (unsigned) (num - (float) m_integral) * 100;
    m_amount++;
}

Money::Money(int integral, int frac) : m_integral(integral), m_frac(frac) {
    m_amount++;
}

Money::~Money() {
    m_amount--;
}

int Money::get_amount() const {
    return m_amount;
}

Money operator+(const Money &m1, const Money &m2) {
    Money m3(m1);
    m3.m_frac = (m1.m_frac + m2.m_frac) % 100;
    m3.m_integral += m2.m_integral;
    m3.m_integral += (m1.m_frac + m2.m_frac) / 100;
    return m3;
}

Money operator-(const Money &m1, const Money &m2) {
    Money m3(m1);
    m3.m_integral -= m2.m_integral;
    if (m1.m_frac < m2.m_frac) {
        m3.m_frac = (m1.m_frac + 100) - m2.m_frac;
        m3.m_integral--;
    } else
        m3.m_frac -= m2.m_frac;
    return m3;
}

Money operator*(const Money &m1, float num) {
    Money m2(m1);
    m2.m_frac = (unsigned) ((float) m2.m_frac * num);
    m2.m_frac += (unsigned) ((float) (m2.m_integral) * num - (float) (m2.m_integral * (int) (num)));
    m2.m_integral = (long) ((float) m2.m_integral * num);
    m2.m_integral += m2.m_frac / 100;
    m2.m_frac %= 100;
    return m2;
}

Money operator*(float num, const Money &m1) {
    return m1 * num;
}

Money operator/(const Money &m1, float num) {
    return m1 * (1 / num);
}

float operator/(const Money &m1, const Money &m2) {
    return (float) (m1.m_integral * 100 + m1.m_frac) / (float) (m2.m_integral * 100 + m2.m_frac);
}

std::istream &operator>>(std::istream &in, Money &m) {
    std::cout << "Enter integral part:\n";
    in >> m.m_integral;
    int tmp;
    std::cout << "Enter fractional part:\n";
    in >> tmp;
    m.m_frac = tmp;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Money &m) {
    if (m.m_frac >= 10)
        out << m.m_integral << ',' << (int) m.m_frac;
    else
        out << m.m_integral << ',' << 0 << (int) m.m_frac;
    return out;
}

bool operator>(const Money &m1, const Money &m2) {
    if (m1.m_integral > m2.m_integral)
        return true;
    else if (m1.m_integral == m2.m_integral)
        return m1.m_frac > m2.m_frac;
    else
        return false;
}

bool operator>=(const Money &m1, const Money &m2) {
    if (m1.m_integral >= m2.m_integral)
        return true;
    else if (m1.m_integral == m2.m_integral)
        return m1.m_frac >= m2.m_frac;
    else
        return false;
}

bool operator<(const Money &m1, const Money &m2) {
    if (m1.m_integral < m2.m_integral)
        return true;
    else if (m1.m_integral == m2.m_integral)
        return m1.m_frac < m2.m_frac;
    else
        return false;
}

bool operator<=(const Money &m1, const Money &m2) {
    if (m1.m_integral <= m2.m_integral)
        return true;
    else if (m1.m_integral == m2.m_integral)
        return m1.m_frac <= m2.m_frac;
    else
        return false;
}

bool operator==(const Money &m1, const Money &m2) {
    return (m1.m_integral == m2.m_integral && m1.m_frac == m2.m_frac);
}