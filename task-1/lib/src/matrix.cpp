#include <iostream>
#include <utility>
#include "../include/Matrix.h"

Matrix::Matrix() : rows(0), columns(0), arr(nullptr) {}

Matrix::Matrix(const size_t rows, const size_t columns) : rows(rows), columns(columns), arr(nullptr) {
	if (rows == 0 || columns == 0) {
		return;
	}
	arr = new int* [rows];
	for (size_t i = 0; i < rows; i++) {
		arr[i] = new int [columns]();
	}
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), columns(other.columns), arr(nullptr) {
	if (rows == 0 || columns == 0) {
		return;
	}
	this->arr = new int* [rows];
	for (size_t i = 0; i < rows; i++) {
		this->arr[i] = new int[columns];
		for(size_t j = 0; j < columns; j++) {
			this->arr[i][j] = other.arr[i][j];
		}
	}
}

Matrix::Matrix(Matrix&& other) noexcept : rows(other.rows), columns(other.columns), arr(other.arr) {
	other.rows = 0;
	other.columns = 0;
	other.arr = nullptr;
}

Matrix::~Matrix() {
	if (arr != nullptr) {
		for (size_t i = 0; i < rows; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}
}

Matrix& Matrix::operator=(const Matrix& other){
	if (this == &other) return *this;
	Matrix temp(other);

	std::swap(rows, temp.rows);
	std::swap(columns, temp.columns);
	std::swap(arr, temp.arr);

	return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
	if (this == &other) return *this;
	Matrix temp(std::move(other));

	std::swap(rows, temp.rows);
	std::swap(columns, temp.columns);
	std::swap(arr, temp.arr);

	return *this;
}

size_t Matrix::getRows() const noexcept {return rows};

size_t Matrix::getColumns() const noexcept {return columns};


