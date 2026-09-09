#include <iostream>
#pragma once

class Matrix {
private:
	size_t rows;
	size_t columns;
public:
	Matrix() = default;

	Matrix (const int rows = 0, const int columns = 0);

	Matrix (const Matrix& other);

	Matrix (Matrix&& other);

	~Matrix();

	Matrix& operator= (const Matrix& other);

	Matrix& operator= (Matrix&& other);

	size_t getRows() const;

	size_t getColumns() const;

	friend std::ostream& operator<< (std::ostream& os, const Martix& M);

	friend std::istream& operator>> (std::istream& is, const Matrix& M);

	bool operator== (const Matrix& other) const;

	bool operator!= (const Matrix& other) const;

	//
};
