#pragma once
#include "Person.h"
#include "Employee.h"
#include "Department.h"
#include "Position.h"
#include <vector>
#include <memory>

/**
 * @brief Класс HRDepartment
 */
class HRDepartment {
	private:
		/**
		 * @brief Массив указателей на сотрудников
		 */
		std::vector<std::unique_ptr<Person>> people;

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
		 * @brief Добавить нового сотрудника
		 * @param person - указатель на сотрудника
		 */
		void addPerson(std::unique_ptr<Person> person);

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
		const std::vector<std::unique_ptr<Person>>& getPeople() const noexcept;

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
