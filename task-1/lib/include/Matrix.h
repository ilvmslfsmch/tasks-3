#include <iostream>
#pragma once

/**
 * @brief Класс Matrix(массив)
 */
class Matrix {

private:

	/**
	 * @brief количество строк в массиве
	 */
	size_t rows;

	/**
	 * @brief количество столбцов в массиве
	 */
	size_t columns;

	/**
	 * @brief указатель на массив
	 */
	 int** arr;
public:

	/**
	 * @brief Конструктор матрицы
	 * @param row - количество строк матрицы
	 * @param columns - количество столбцов матрицы
	 * @param arr - указатель на массив
	 */
	Matrix (int** arr, const size_t row, const size_t columns);

	/**
	 * @brief Конструктор копирования
	 * @param other - ссылка на другую матрицу
	 */
	Matrix (const Matrix& other);

	/**
	 * @brief конструктор перемещения
	 * @param other - ссылка на другую (временную) матрицу
	 */
	Matrix (Matrix&& other);

	/**
	 * @brief Деструктор
	 */
	~Matrix();

	/**
	 * @brief оператор присваивания копированием
	 * @param other - ссылка на другую матрицу
	 * @return ссылку на скопированную матрицу
	 */
	Matrix& operator= (const Matrix& other);

	/**
	 * @brief оператор присваивания перемещением
	 * @param other - ссылка на другую (временную) матрицу
	 * @return ссылку на перемещенную матрицу
	 */
	Matrix& operator= (Matrix&& other);

	/**
	 * @brief перегрузка оператора сдвига слево
	 * @param os - поток вывода
	 * @param M - ссылка на матрицу M
	 * @return перегруженный поток вывода
	 */
	friend std::ostream& operator<< (std::ostream& os, const Martix& M);

	/**
	 * @brief перегрузка оператора сдвига вправо
	 * @param is - поток ввода
	 * @param M - ссылка на матрицу M
	 * @return перегруженный поток ввода
	 */
	friend std::istream& operator>> (std::istream& is, const Matrix& M);

	/**
	 * @brief оператор "равно"
	 * @param other - ссылка на другую матрицу
	 * @return 1 - если матрицы равны, иначе 0
	 */
	bool operator== (const Matrix& other) const;

	/**
	 * @brief оператор "не равно"
	 * @param other - ссылка на другую матрицу
	 * @return 1 - если матрицы не равны, иначе 0
	 */
	bool operator!= (const Matrix& other) const;
};
