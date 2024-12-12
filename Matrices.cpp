#include "Matrices.h"
namespace Matrices
{
	Matrix::Matrix(int _rows, int _cols)
	{
		rows = _rows;
		cols = _cols;

		a.resize(rows);
		for (int i = 0; i < rows; ++i)
		{
			a[i].resize(cols);
		}
	}
	///Add each corresponding element.
	///usage:  c = a + b;
	Matrix operator+(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			throw runtime_error("Error: Dimension must agree");
		}
		Matrix c(a.getRows(), a.getCols());
		for (int i = 0; i < a.getRows(); ++i)
		{
			for (int j = 0; j < a.getCols(); ++j)
			{
				c(i, j) = a(i, j) + b(i, j);
			}
		}
		return c;
	}

	///Matrix multiply.  See description.
	///usage:  c = a * b;
	Matrix operator*(const Matrix& a, const Matrix& b)
	{
		if (a.getCols() != b.getRows())
		{
			throw runtime_error("Error: dimensions must agree");
		}
		Matrix c(a.getRows(), b.getCols());
		for (int i = 0; i < a.getRows(); ++i)
		{
			for (int j = 0; j < b.getCols(); ++j)
			{
				c(i, j) = 0;
				for (int k = 0; k < a.getCols(); ++k)
				{
					c(i, j) += a(i, k) * b(k, j);
				}
			}
		}
		return c;
	}

	///Matrix comparison.  See description.
	///usage:  a == b
	bool operator==(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			return false;
		}
		for (int i = 0; i < a.getRows(); ++i)
		{
			for (int j = 0; j < a.getCols(); ++j)
			{
				if (abs(a(i, j) - b(i, j)) >= 0.001)
				{
					return false;
				}
			}
		}
		return true;
	}

	///Matrix comparison.  See description.
	///usage:  a != b
	bool operator!=(const Matrix& a, const Matrix& b)
	{
		return !(a == b);
	}

	///Output matrix.
	///Separate columns by ' ' and rows by '\n'
	ostream& operator<<(ostream& os, const Matrix& a)
	{
		for (int i = 0; i < a.getRows(); ++i)
		{
			for (int j = 0; j < a.getCols(); ++j)
			{
				os << setw(10) << a(i, j) << " ";
			}
			os << endl;
		}
		return os;
	}
	TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols)
	{
		for (int j = 0; j < nCols; j++)
		{
			a[0][j] = xShift;
			a[1][j] = yShift;
		}

	}
	ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2)
	{
		a[0][0] = scale;
		a[0][1] = 0;
		a[1][0] = 0;
		a[1][1] = scale;
	}
	RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2)
	{
		a[0][0] = cos(theta);
		a[0][1] = -sin(theta);
		a[1][0] = sin(theta);
		a[1][1] = cos(theta);
	}
}