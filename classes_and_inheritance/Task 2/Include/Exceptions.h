#ifndef CLASSES_AND_INHERITANCE_EXCEPTIONS_H
#define CLASSES_AND_INHERITANCE_EXCEPTIONS_H

#include <exception>
#include <string>
#include <utility>

class OutOfRangeException : public std::exception
{
    std::string m_err;
public:
    OutOfRangeException(const std::string& err)
    : m_err(std::move(err))
    {}
    const char* what() const noexcept override {
        return m_err.c_str();
    }
};

class IncompatibleDimException : public std::exception
{
    std::string m_err;
public:
    IncompatibleDimException(const std::string& err)
    : m_err(std::move(err))
    {}
    const char* what() const noexcept override {
        return m_err.c_str();
    }
};

class DivisionByZeroException : public std::exception
{
    std::string m_err;
public:
    DivisionByZeroException(const std::string& err)
    : m_err(std::move(err))
    {}
    const char* what() const noexcept override {
        return m_err.c_str();
    }
};

class NegativeNumberException : public std::exception
{
    std::string m_err;
public:
    NegativeNumberException(const std::string& err)
    : m_err(std::move(err))
    {}
    const char* what() const noexcept override {
        return m_err.c_str();
    }
};

class BadCastException : public std::exception
{
    std::string m_err;
public:
    BadCastException(const std::string& err)
    : m_err(std::move(err))
    {}
    const char* what() const noexcept override {
        return m_err.c_str();
    }
};


#endif //CLASSES_AND_INHERITANCE_EXCEPTIONS_H
