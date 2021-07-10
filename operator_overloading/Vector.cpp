#include "Vector.h"


Vector::Vector() : m_size(0), m_arr(nullptr)
{};


Vector::Vector(int size) : m_size(size)
{
	m_arr = new double[size];
	for (int i = 0; i < size; i++)
		m_arr[i] = 0;
}


Vector::Vector(const Vector& vector) : m_size(vector.m_size)
{
	m_arr = new double[vector.m_size];
	for (int i = 0; i < vector.m_size; i++)
		m_arr[i] = vector.m_arr[i];
}


Vector::~Vector()
{
	delete[] m_arr;
}


double Vector::length() const
{
	double sum = 0;
	for (int i = 0; i < m_size; i++)
		sum += m_arr[i] * m_arr[i];
	return sqrt(sum);
}


Vector operator+(const Vector& vector1, const Vector& vector2)
{
	if (vector1.m_size != vector2.m_size)
		throw InCompatibleDimException("Vectors");
	Vector vector3(vector1);
	for (int i = 0; i < vector1.m_size; i++)
		vector3.m_arr[i] += vector2.m_arr[i];
	return vector3;
}


Vector operator-(const Vector& vector1, const Vector& vector2)
{
	if (vector1.m_size != vector2.m_size)
		throw InCompatibleDimException("Vectors");
	Vector vector3(vector1);
	for (int i = 0; i < vector1.m_size; i++)
		vector3.m_arr[i] -= vector2.m_arr[i];
	return vector3;
}


Vector Vector::operator-()
{
	return *this * (-1.);
}


const Vector& Vector::operator+() const
{
	return *this;
}


Vector& Vector::operator+=(const Vector& vector)
{
	if (vector.m_size != this->m_size)
		throw InCompatibleDimException("Vectors");
	for (int i = 0; i < m_size; i++)
		m_arr[i] += vector.m_arr[i];
	return *this;
}


Vector& Vector::operator-=(const Vector& vector) 
{
	if (vector.m_size != this->m_size)
		throw InCompatibleDimException("Vectors");
	for (int i = 0; i < m_size; i++)
		m_arr[i] -= vector.m_arr[i];
	return *this;
}


Vector operator*(const Vector& vector1, const double a)
{
	Vector vector2(vector1);
	for (int i = 0; i < vector1.m_size; i++)
		vector2.m_arr[i] *= a;
	return vector2;
}


Vector operator*(const double a, const Vector& vector1) 
{
	return vector1 * a;
}


double operator*(const Vector& vector1, const Vector& vector2)
{
	if (vector1.m_size != vector2.m_size)
		throw InCompatibleDimException("Vectors");
	double x = 0;
	for (int i = 0; i < vector1.m_size; i++)
		x += vector1.m_arr[i] * vector2.m_arr[i];
	return x;
}


const double& Vector::operator[](int i) const
{
	if (i < 0 || i > m_size)
		throw OutOfRangeException();
	return m_arr[i];
}


double& Vector::operator[](int i)
{
	if (i < 0 || i > m_size)
		throw OutOfRangeException();
	return m_arr[i];
}


Vector& Vector::operator=(const Vector& vector) 
{
	if (this == &vector)
		return *this;
	if (m_size != vector.m_size)
	{
		delete[] m_arr;
		m_arr = new double[vector.m_size];
		m_size = vector.m_size;
	}
	for (int i = 0; i < m_size; i++) {
		m_arr[i] = vector.m_arr[i];
	}
	return *this;
}


std::ostream& operator<<(std::ostream& out, const Vector& vector)
{
	out << '(';
	for (int i = 0; i < vector.m_size; i++)
		if (i == vector.m_size - 1)
			out << vector.m_arr[i];
		else
			out << vector.m_arr[i] << ", ";
	out << ')';
	return out;
}


std::istream& operator>>(std::istream& in, Vector& vector)
{
	if (vector.m_size == 0)
	{
		in >> vector.m_size;
		vector.m_arr = new double[vector.m_size];
	}
	for (int i = 0; i < vector.m_size; i++)
		in >> vector.m_arr[i];
	return in;
}


Vector::operator double() const
{
	return this->length();
}