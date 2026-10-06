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
		 * @brief Массив людей
		 */
		std::vector<Person> people;

		/**
		 * @brief Массив сотрудников
		 */
		std::vector<Employee> employees;

		/**
		 * @brief Массив департаментов
		 */
		std::vector<Department> departments;

		/**
		 * @brief Массив должностей
		 */
		std::vector<Position> positions;

		/**
		 * @brief Проверить наличие человека с данным ID в отделе
		 * @param id - ID человека
		 * @return true, если человек с таким ID уже есть
		 */
		bool containsId(const int id) const;
	public:

		/**
		* @brief Конструктор по умолчанию
		*/
		HRDepartment() = default;

		/**
		 * @brief Деструктор
		 */
		~HRDepartment() = default;

		/**
		 * @brief Добавить ребёнка
		 * @param person - ребёнок
		 */
		void addPerson(const Person& person);

		/**
		 * @brief Добавить сотрудника
		 * @param employee - сотрудник
		 */
		void addPerson(const Employee& employee);

		/**
		 * @brief Добавить сотрудника
		 * @param employee - сотрудник
		 */
		void addEmployee(const Employee& employee);

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
		 * @brief Получить список людей
		 * @return ссылку на массив людей
		 */
		const std::vector<Person>& getPeople() const noexcept;

		/**
		 * @brief Получить список сотрудников
		 * @return ссылку на массив сотрудников
		 */
		const std::vector<Employee>& getEmployees() const noexcept;

		/**
		 * @brief Получить список отделов
		 * @return ссылку на массив отделов
		 */
		const std::vector<Department>& getDepartments() const noexcept;

		/**
		 * @brief Получить список должностей
		 * @return ссылку на массив должностей
		 */
		const std::vector<Position>& getPositions() const noexcept;

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
