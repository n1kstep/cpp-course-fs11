#include "Matrix.h"


CSLRMatrix::CSLRMatrix(int size) : 
	m_size(size), 
	m_nzero(0),
	m_adiag(nullptr),
	m_altr(nullptr),
	m_autr(nullptr),
	m_jptr(nullptr),
	m_iptr(nullptr)
{}


CSLRMatrix::CSLRMatrix(double* adiag, double* altr, double* autr, int* jptr, int* iptr, int size, int nzero) :
	m_size(size),
	m_nzero(nzero)
{
	m_adiag = new double[size];
	m_altr = new double[(nzero - size) / 2];
	m_autr = new double[(nzero - size) / 2];
	m_jptr = new int[(nzero - size) / 2];
	m_iptr = new int[size + 1];
	for (int i = 0; i < (nzero - size) / 2; i++)
	{
		m_altr[i] = altr[i];
		m_autr[i] = autr[i];
		m_jptr[i] = jptr[i];
	}
	for (int i = 0; i < size; i++)
		m_adiag[i] = adiag[i];
	for (int i = 0; i < size + 1; i++)
		m_iptr[i] = iptr[i];
}


CSLRMatrix::CSLRMatrix(const CSLRMatrix& matrix):
	m_size(matrix.m_size),
	m_nzero(matrix.m_nzero)
{
	m_adiag = new double[matrix.m_size];
	m_altr = new double[(matrix.m_nzero - matrix.m_size) / 2];
	m_autr = new double[(matrix.m_nzero - matrix.m_size) / 2];
	m_jptr = new int[(matrix.m_nzero - matrix.m_size) / 2];
	m_iptr = new int[matrix.m_size + 1];
	for (int i = 0; i < (matrix.m_nzero - matrix.m_size) / 2; i++)
	{
		m_altr[i] = matrix.m_altr[i];
		m_autr[i] = matrix.m_autr[i];
		m_jptr[i] = matrix.m_jptr[i];
	}
	for (int i = 0; i < matrix.m_size; i++)
		m_adiag[i] = matrix.m_adiag[i];
	for (int i = 0; i < matrix.m_size + 1; i++)
		m_iptr[i] = matrix.m_iptr[i];
}


CSLRMatrix::~CSLRMatrix()
{
	delete[] m_adiag;
	delete[] m_altr;
	delete[] m_autr;
	delete[] m_jptr; 
	delete[] m_iptr;
}


CSLRMatrix operator*(const CSLRMatrix& matrix1, const double a)
{
	CSLRMatrix matrix2(matrix1);
	for (int i = 0; i < (matrix1.m_nzero - matrix1.m_size) / 2; i++)
	{
		matrix2.m_altr[i] *= a;
		matrix2.m_autr[i] *= a;
	}
	for (int i = 0; i < matrix1.m_size; i++)
		matrix2.m_adiag[i] *= a;
	return matrix2;
}


CSLRMatrix operator*(const double a, const CSLRMatrix& matrix1)
{
	return matrix1 * a;
}


Vector operator*(const CSLRMatrix& matrix, const Vector& vector1)
{
	if (vector1.size() != matrix.m_size)
		throw InCompatibleDimException("Vector and CSLRMatrix");
	Vector vector2(vector1);
	for (int i = 1; i < matrix.m_size; i++)
		vector2[i] = vector1[i] * matrix.m_adiag[i];
	for (int i = 1; i < matrix.m_size; i++)
		for (int j = matrix.m_iptr[i]; i < matrix.m_iptr[i + 1] - 1; i++)
		{
			vector2[i] += vector1[matrix.m_jptr[j]] * matrix.m_altr[j];
			vector2[matrix.m_jptr[j]] += vector1[i] * matrix.m_autr[j];
		}
	return vector2;
}


Vector operator*(const Vector& vector1, const CSLRMatrix& matrix)
{
	return matrix * vector1;
}


CSLRMatrix& CSLRMatrix::operator=(const CSLRMatrix& matrix)
{
	if (this == &matrix)
		return *this;
	if (m_size != matrix.m_size)
	{
		delete[] m_adiag;
		delete[] m_altr;
		delete[] m_autr;
		delete[] m_jptr;
		delete[] m_iptr;
		m_size = matrix.m_size;
		m_nzero = matrix.m_nzero;
		m_adiag = new double[matrix.m_size];
		m_altr = new double[(matrix.m_nzero - matrix.m_size) / 2];
		m_autr = new double[(matrix.m_nzero - matrix.m_size) / 2];
		m_jptr = new int[(matrix.m_nzero - matrix.m_size) / 2];
		m_iptr = new int[matrix.m_size + 1];
	}
	m_nzero = matrix.m_nzero;
	for (int i = 0; i < (matrix.m_nzero - matrix.m_size) / 2; i++)
	{
		m_altr[i] = matrix.m_altr[i];
		m_autr[i] = matrix.m_autr[i];
		m_jptr[i] = matrix.m_jptr[i];
	}
	for (int i = 0; i < matrix.m_size; i++)
		m_adiag[i] = matrix.m_adiag[i];
	for (int i = 0; i < matrix.m_size + 1; i++)
		m_iptr[i] = matrix.m_iptr[i];
	return *this;
}

// ¬ыполненное задание на защиту (вывод матрицы без выделени€ пам€ти под нее)
std::ostream& operator<<(std::ostream& out, const CSLRMatrix& matrix)
{
	int cnt, cur;
	bool flag = 0;

	for (int i = 0; i < matrix.m_size; ++i)
	{
		for (int j = 0; j < matrix.m_size; ++j)
		{
			if (i == j)
				out << std::setw(4) << matrix.m_adiag[i];
			if (i < j)
			{
				cnt = matrix.m_iptr[j] - matrix.m_iptr[0];
				cur = matrix.m_iptr[j + 1] - matrix.m_iptr[j];
				flag = 0;
				for (int k = 0; k < cur; ++k)
				{
					if (matrix.m_jptr[cnt + k] == i)
					{
						out << std::setw(4) << matrix.m_altr[cnt + k];
						flag = 1;
					}

				}
				if (flag == 0) 
					out << std::setw(4) << 0;
			}
			if (i > j)
			{
				cnt = matrix.m_iptr[i] - matrix.m_iptr[0];
				cur = matrix.m_iptr[i + 1] - matrix.m_iptr[i];
				flag = 0;
				for (int k = 0; k < cur; ++k)
				{
					if (matrix.m_jptr[cnt + k] == j)
					{
						out << std::setw(4) << matrix.m_autr[cnt + k];
						flag = 1;
					}
				}
				if (flag == 0)
					out << std::setw(4) << 0;
			}
		}
		out << std::endl;
	}
	return out;
}


std::istream& operator>>(std::istream& in, CSLRMatrix& matrix)
{
	std::cout << "size = ";
	in >> matrix.m_size;
	std::cout << "nzero = ";
	in >> matrix.m_nzero;
	delete[] matrix.m_adiag;
	delete[] matrix.m_altr;
	delete[] matrix.m_autr;
	delete[] matrix.m_jptr;
	delete[] matrix.m_iptr;
	matrix.m_adiag = new double[matrix.m_size];
	matrix.m_altr = new double[(matrix.m_nzero - matrix.m_size) / 2];
	matrix.m_autr = new double[(matrix.m_nzero - matrix.m_size) / 2];
	matrix.m_jptr = new int[(matrix.m_nzero - matrix.m_size) / 2];
	matrix.m_iptr = new int[matrix.m_size + 1];
	std::cout << "adiag[] = ";
	for (int i = 0; i < matrix.m_size; i++)
		in >> matrix.m_adiag[i];
	std::cout << "altr[] = ";
	for (int i = 0; i < (matrix.m_nzero - matrix.m_size) / 2; i++)
		in >> matrix.m_altr[i];
	std::cout << "autr[] = ";
	for (int i = 0; i < (matrix.m_nzero - matrix.m_size) / 2; i++)
		in >> matrix.m_autr[i];
	std::cout << "jptr[] = ";
	for (int i = 0; i < (matrix.m_nzero - matrix.m_size) / 2; i++)
		in >> matrix.m_jptr[i];
	std::cout << "iptr[] = ";
	for (int i = 0; i < matrix.m_size + 1; i++)
		in >> matrix.m_iptr[i];
	return in;
}