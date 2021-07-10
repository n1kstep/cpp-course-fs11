#pragma once
#include "Vector.h"
#include "Exception.h"


class CSLRMatrix
{
private:
	double* m_adiag;
	double* m_altr;
	double* m_autr;
	int* m_jptr;
	int* m_iptr;
	int m_size;
	int m_nzero;
public:
	CSLRMatrix(int size);
	CSLRMatrix(double* adiag, double* altr, double* autr, int* jptr, int* iptr, int size, int nzero);
	CSLRMatrix(const CSLRMatrix& matrix);
	~CSLRMatrix();

	int size()
	{
		return m_size;
	};
	int size() const
	{
		return m_size;
	};
	int nzeros()
	{
		return m_nzero;
	};
	int nzeros() const
	{
		return m_nzero;
	};

	friend CSLRMatrix operator*(const CSLRMatrix& matrix1, const double a);
	friend CSLRMatrix operator*(const double a, const CSLRMatrix& matrix1);

	friend Vector operator*(const CSLRMatrix& matrix1, const Vector& vector);
	friend Vector operator*(const Vector& vector, const CSLRMatrix& matrix1);

	CSLRMatrix& operator=(const CSLRMatrix& matrix);

	friend std::ostream& operator<<(std::ostream& out, const CSLRMatrix& matrix);
	friend std::istream& operator>>(std::istream& in, CSLRMatrix& matrix);
};