#include "Exception.h"
#include <iostream>
#include <string>


OutOfRangeException::OutOfRangeException()
	: m_err("Error: Index is out of Vector's size.\n")
{}


const char* OutOfRangeException::what() const throw()
{
	return m_err.c_str();
}


InCompatibleDimException::InCompatibleDimException(const std::string& str)
	: m_err("Error: " + str + " have different sizes.\n")
{}


const char* InCompatibleDimException::what() const throw()
{
	return m_err.c_str();
}
