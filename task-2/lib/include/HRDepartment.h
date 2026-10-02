#pragma once
#include "Person.h"
#include "Employee.h"
#include "Department.h"
#include "Position.h"
#include <vector>
#include <memory>

class HRDepartment {
	private:
		std::vector<std::unique_ptr<Person>> people;
		std::vector<Department> departments;
		std::vector<Position> positions;
	public:
		void addPerson(std::unique_ptr<Person> person);
		void addDepartment(const Department& department);
		void addPosition(const Position& position);

		const std::vector<std::unique_ptr<Person>>& getPeople() const noexcept;

		void printAll() const;
		void printByPosition(const std::string& positionTitle) const;
		void printByRate(double rate) const;
		void printWithChildren() const;
		void printPensioners() const;
		void printDisabled() const;
		void printOnVacation() const;
		void printOnMaternityLeave() const;
		void printPositionInfo() const;
		void printPreviousWorkplaces() const;
		void printByFullName(const std::string& fullName) const;
		void printChildrenOf(int paretnId) const;
};
