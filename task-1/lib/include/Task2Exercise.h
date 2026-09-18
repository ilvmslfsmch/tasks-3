#pragma once

#include "Exercise.h"

/**
 * @brief класс Task2Exercise абстрактного класса Exercise
 */
class Task2Exercise : public Exercise {
	public:
		/**
		 * @brief Конструктор
		 * @param src - ссылка на матрицу
		 * @param gen - ссылка на генератор
		 */
		Task2Exercise(Matrix& src, Generator& gen);

		/**
		 * @brief Перегруженный деструктор
		 */
		~Task2Exercise() override = default;

		/**
		 * @brief Решение задачи
		 * @return Решённую задачу (изменённый массив)
		 */
		Matrix solve() override;
};
