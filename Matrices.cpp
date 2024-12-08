#include "Matrices.h"
namespace Matrices 
{
	Matrix::Matrix(int _rows, int _cols)
	{
		this->rows = 0;
		this->cols = 0;

		vector<vector<double>> a;
	}
	///Add each corresponding element.
	///usage:  c = a + b;
	Matrix operator+(const Matrix& a, const Matrix& b)
	{

		return a + b;
	}

	///Matrix multiply.  See description.
	///usage:  c = a * b;
	Matrix operator*(const Matrix& a, const Matrix& b)
	{
		return a * b;
	}

	///Matrix comparison.  See description.
	///usage:  a == b
	bool operator==(const Matrix& a, const Matrix& b)
	{
		return a == b;
	}

	///Matrix comparison.  See description.
	///usage:  a != b
	bool operator!=(const Matrix& a, const Matrix& b)
	{
		return a != b;
	}

	///Output matrix.
	///Separate columns by ' ' and rows by '\n'
	ostream& Matrices::operator<<(ostream& os, const Matrix& a)
	{
		return os << " " << a;
	}
	TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols)
	{

	}
	ScalingMatrix::ScalingMatrix(double scale)
	{

	}
	RotationMatrix::RotationMatrix(double theta)
	{

	}
}