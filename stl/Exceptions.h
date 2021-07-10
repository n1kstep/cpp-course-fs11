#pragma once

#include <string>
#include <exception>

class ContainerException: public std::exception {
private:
    std::string error;
public:
    ContainerException(const std::string& error) noexcept : error("ContainerException: " + error) {}
    const char* what() const noexcept override {
        return error.c_str();
    }
};

class IteratorException : public std::exception {
private:
    std::string error;
public:
    IteratorException(const std::string& error) noexcept : error("IteratorException: " + error) {}
    const char* what() const noexcept override {
        return error.c_str();
    }
};
