#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include "Exception.h"


class Vector
{
	int m_size;
	double* m_arr;
public:
	Vector();
	explicit Vector(int size);
	Vector(const Vector& vector);
	~Vector();

	int size() const { return m_size; };
	double length() const;

	friend Vector operator+(const Vector& vector1, const Vector& vector2);
	friend Vector operator-(const Vector& vector1, const Vector& vector2);

	Vector operator-();
	const Vector& operator+() const;
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);

	friend Vector operator*(const Vector& vector1, const double a);
	friend Vector operator*(const double a, const Vector& vector1);
	friend double operator*(const Vector& vector1, const Vector& vector2);

	double& operator[](int i);
	const double& operator[](int i) const;
	Vector& operator=(const Vector& vector);

	friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
	friend std::istream& operator>>(std::istream& in, Vector& vector);
	operator double() const;
};