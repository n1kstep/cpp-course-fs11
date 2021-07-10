#include "../Include/Payment.h"

int Payment::m_amount = 0;

Payment::Payment(const std::string &name, const Money &salary, unsigned int year,
                 float bonus, unsigned int workedDays, unsigned int plannedDays) :
        m_name(name), m_salary(salary), m_year(year),
        m_bonus(bonus), m_workedDays(workedDays), m_plannedDays(plannedDays) {
    m_amount++;
}

Payment::~Payment() {
    m_amount--;
}

int Payment::get_amount() const {
    return m_amount;
}

unsigned int Payment::count_experience() const {
    return 2021 - m_year;
}

Money Payment::count_accrued() {
    m_accrued = m_salary * ((float) m_workedDays / (float) m_plannedDays) + m_salary * m_bonus;
    return m_accrued;
}

Money Payment::count_withheld() {
    m_withheld = m_accrued * (m_tax + float(0.01));
    return m_withheld;
}

Money Payment::count_sum() const {
    return m_accrued - m_withheld;
}

std::ostream &operator<<(std::ostream &out, const Payment &p) {
    out << "Name: " << p.m_name << std::endl;
    out << "Salary: " << p.m_salary << std::endl;
    out << "Year: " << p.m_year << std::endl;
    out << "Bonus: " << p.m_bonus << std::endl;
    out << "Worked days: " << p.m_workedDays << std::endl;
    out << "Planned days: " << p.m_plannedDays << std::endl;
    out << "Accrued sum: " << p.m_accrued << std::endl;
    out << "Withheld sum: " << p.m_withheld << std::endl;
    out << "Sum of payment: " << p.count_sum() << std::endl;
    out << "Amount of objects: " << p.get_amount() << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Payment &p) {
    std::cout << "Name: " << std::endl;
    in >> p.m_name;
    float tmp;
    std::cout << "Salary: " << std::endl;
    in >> tmp;
    p.m_salary = Money(tmp);
    std::cout << "Year: " << std::endl;
    in >> p.m_year;
    std::cout << "Bonus: " << std::endl;
    in >> p.m_bonus;
    std::cout << "Worked days: " << std::endl;
    in >> p.m_workedDays;
    std::cout << "Planned days: " << std::endl;
    in >> p.m_plannedDays;
    return in;
}
