#pragma once
#include "Person.h"
#include "Employee.h"
#include "Department.h"
#include "Position.h"
#include <vector>

/**
 * @brief Класс HRDepartment
 */
class HRDepartment {
	private:
		/**
		 * @brief Массив указателей на сотрудников
		 */
		std::vector<Person*> people;

		/**
		 * @brief Массив департаментов
		 */
		std::vector<Department> departments;

		/**
		 * @brief Массив должностей
		 */
		std::vector<Position> positions;
	public:

		/**
		* @brief Конструктор по умолчанию
		*/
		HRDepartment() = default;

		/**
		 * @brief Деструктор
		 */
		~HRDepartment();

		/**
		* @brief Запрет копирования
		* @note Запреты нужны, так как класс владеет Person через сырые указатели
		* @note Копирование (явное/неявное) приведёт к двойному удалению
		* @note Дальше по той же причине.
		*/
		HRDepartment(const HRDepartment&) = delete;

		/**
		* @brief Запрет присваивания копированием
		*/
		HRDepartment& operator=(const HRDepartment&) = delete;

		/**
		* @brief Запрет перемещения
		* @note Для единообразия: раз не копируем, то и не перемешаем
		*/
		HRDepartment(HRDepartment&&) = delete;

		/**
		* @brief Запрет присваивания перемещением
		*/
		HRDepartment& operator=(HRDepartment&&) = delete;

		/**
		 * @brief Добавить нового сотрудника
		 * @param person - указатель на сотрудника
		 */
		void addPerson(Person* person);

		/**
		 * @brief Добавить отдел
		 * @param department - отдел
		 */
		void addDepartment(const Department& department);

		/**
		 * @brief Добавить должность
		 * @param position - должность
		 */
		void addPosition(const Position& position);

		/**
		 * @brief Получить список сотрудников в отделе
		 * @return ссылку на массив сотрудников
		 */
		const std::vector<Person*>& getPeople() const noexcept;

		/**
		 * @brief Вывести всех сотрудников
		 */
		void printAll() const;

		/**
		 * @brief Вывести сотрудников по должности
		 * @param positionTitle - должность
		 */
		void printByPosition(const std::string& positionTitle) const;

		/**
		 * @brief Вывести сотрудников по ставке
		 * @param rate - ставка
		 */
		void printByRate(const double rate) const;

		/**
		 * @brief Вывести сотрудников с детьми
		 */
		void printWithChildren() const;

		/**
		 * @brief Вывести пенсионеров
		 */
		void printPensioners() const;

		/**
		 * @brief вывести инвалидов
		 */
		void printDisabled() const;

		/**
		 * @brief Вывести сотрудников в отпуске
		 */
		void printOnVacation() const;

		/**
		 * @brief Вывести сотрудников в декрете
		 */
		void printOnMaternityLeave() const;

		/**
		 * @brief Вывести должности
		 */
		void printPositionInfo() const;

		/**
		 * @brief Вывести прерыдущие места работы сотрудника
		 */
		void printPreviousWorkplaces() const;

		/**
		 * @brief Поиск по ФИО
		 * @param fullName - ФИО сотрудника
		 */
		void printByFullName(const std::string& fullName) const;

		/**
		 * @brief Вывести детей сотрудника
		 * @param parentId - ID сотрудника
		 */
		void printChildrenOf(const int parentId) const;
};
