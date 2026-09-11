#pragma once
#include <iosfwd>
#include <string>

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
	  * @brief Конструктор по умолчанию
	  */
	 Matrix();

	 /**
	  * @brief Конструктор матрицы rows * columns, заполненой нулями (создание матрицы из размеров)
	  * @param rows - количество строк массива
	  * @param columns - количество столбцов массива
	  */
	 Matrix(const size_t r, const size_t c);

	/**
	 * @brief Конструктор матрицы из уже готовых данных
	 * @param row - количество строк матрицы
	 * @param columns - количество столбцов матрицы
	 * @param arr - указатель на массив
	 */
//	Matrix (int** arr, const size_t rows, const size_t columns);

	/**
	 * @brief Конструктор копирования
	 * @param other - ссылка на другую матрицу
	 */
	Matrix (const Matrix& other);

	/**
	 * @brief конструктор перемещения
	 * @param other - ссылка на другую (временную) матрицу
	 */
	Matrix (Matrix&& other) noexcept;

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
	Matrix& operator= (Matrix&& other) noexcept;

	/**
	 * @brief перегрузка оператора сдвига слево
	 * @param os - поток вывода
	 * @param M - ссылка на матрицу M
	 * @return перегруженный поток вывода
	 */
	friend std::ostream& operator<< (std::ostream& os, const Matrix& M);

	/**
	 * @brief перегрузка оператора сдвига вправо
	 * @param is - поток ввода
	 * @param M - ссылка на матрицу M
	 * @return перегруженный поток ввода
	 */
	friend std::istream& operator>> (std::istream& is, Matrix& M);

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

	/**
	 * @brief Вывести содержимое вектора в строку
	 * @return Содержимое строки
	 */
	std::string toString() const;

	/**
	 * @brief Получить указатель на строку по индексу (только чтение)
	 * @param index - номер элемента
	 * @return элемент по индексу
	 */
	const int* operator[] (const size_t index) const;

	/**
	 * @brief получить указатель на строку по индексу
	 * @param index - номер элемента
	 * @return элемент по индексу
	 */
	int* operator[] (size_t index);

	/**
	 * @brief Функция получение количества строк массива
	 * @return число строк
	 */
	size_t getRows() const noexcept;

	/**
	 * @brief Функция получения количества столбцов массива
	 * @return чисто столбцов
	 */
	size_t getColumns() const noexcept;
};
