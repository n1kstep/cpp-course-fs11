#pragma once
#include <exception>
#include <string>


class OutOfRangeException : public std::exception 
{
	std::string m_err;
public:
	OutOfRangeException();
	virtual const char* what() const throw();
};


class InCompatibleDimException : public std::exception 
{
	std::string m_err;
public:
	InCompatibleDimException(const std::string& str);
	virtual const char* what() const throw();
};
