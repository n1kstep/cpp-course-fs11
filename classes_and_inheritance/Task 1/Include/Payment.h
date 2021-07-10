#ifndef CLASSES_AND_INHERITANCE_PAYMENT_H
#define CLASSES_AND_INHERITANCE_PAYMENT_H

#include "Money.h"

class Payment {
private:
    std::string m_name;
    Money m_salary;
    unsigned int m_year;
    float m_bonus;
    const float m_tax = 0.13;
    unsigned int m_workedDays;
    unsigned int m_plannedDays;
    Money m_accrued;
    Money m_withheld;
    static int m_amount;
public:
    explicit Payment(const std::string& name = "",
            const Money& salary = Money(),
            unsigned int m_year = 1991,
            float m_bonus = 0,
            unsigned int m_workedDays = 0,
            unsigned int m_plannedDays = 0);
    ~Payment();

    int get_amount() const;
    unsigned int count_experience() const;
    Money count_accrued();
    Money count_withheld();
    Money count_sum() const;

    friend std::ostream &operator<<(std::ostream &out, const Payment &p);
    friend std::istream &operator>>(std::istream &in, Payment &p);
};

#endif //CLASSES_AND_INHERITANCE_PAYMENT_H
