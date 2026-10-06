#include "../include/HRDepartment.h"
#include <iostream>
#include <map>
#include <algorithm>

bool HRDepartment::containsId(const int id) const {
	bool inEmployees = std::any_of(employees.begin(), employees.end(), [id](const Employee& e) {
		return e.getId() == id;
	});
	if (inEmployees) return true;

	return std::any_of(people.begin(), people.end(), [id](const Person& p) {
		return p.getId() == id;
	});
}

void HRDepartment::addPerson(const Person& person) {
	if (containsId(person.getId())) return;
	people.push_back(person);
}

void HRDepartment::addPerson(const Employee& employee) {
	addEmployee(employee);
}

void HRDepartment::addEmployee(const Employee& employee) {
	if (containsId(employee.getId())) return;
	employees.push_back(employee);
}

void HRDepartment::addDepartment(const Department& department) {
	departments.push_back(department);
}

void HRDepartment::addPosition(const Position& position) {
	positions.push_back(position);
}

const std::vector<Person>& HRDepartment::getPeople() const noexcept {
	return people;
}

const std::vector<Employee>& HRDepartment::getEmployees() const noexcept {
	return employees;
}

void HRDepartment::printAll() const {
	for (const Person& p : people) {
		std::cout << p.getInfo() << std::endl;
	}
	for (const Employee& emp : employees) {
		std::cout << emp.getInfo() << std::endl;
	}
}

void HRDepartment::printByPosition(const std::string& positionTitle) const {
	for (const Employee& emp : employees) {
		if (emp.getPosition().getTitle() == positionTitle) {
			std::cout << emp.getInfo() << std::endl;
		}
	}
}

void HRDepartment::printByRate(const double rate) const {
	for (const Employee& emp : employees) {
		if (emp.getRate() == rate) {
			std::cout << emp.getInfo() << std::endl;
		}
	}
}

void HRDepartment::printWithChildren() const {
	for (const Employee& emp : employees) {
		if (emp.hasChildren()) {
			std::cout << emp.getInfo() << std::endl;
		}
	}
}

void HRDepartment::printPensioners() const {
	for (const Employee& emp : employees) {
		if (emp.isPensioner()) {
			std::cout << emp.getInfo() << std::endl;
		}
	}
}

void HRDepartment::printDisabled() const {
	for (const Employee& emp : employees) {
		if (emp.isDisabled()) {
			std::cout << emp.getInfo() << std::endl;
		}
	}
}

void HRDepartment::printOnVacation() const {
	for (const Employee& emp : employees) {
		if (emp.isOnVacation()) {
			std::cout << emp.getInfo() << std::endl;
		}
	}
}

void HRDepartment::printOnMaternityLeave() const {
	for (const Employee& emp : employees) {
		if (emp.isOnMaternityLeave()) {
			std::cout << emp.getInfo() << std::endl;
		}
	}
}

void HRDepartment::printPositionInfo() const {
	std::map<std::string, int> counter;
	for (const Employee& emp : employees) {
		counter[emp.getPosition().getTitle()]++;
	}
	for (const auto& [title, count] : counter) {
		std::cout << title << ": " << count << std::endl;
	}
}

void HRDepartment::printPreviousWorkplaces() const {
	for (const Employee& emp : employees) {
		std::cout << emp.getFullName() << ":" << std::endl;
		for (const PreviousWorkplace& wp : emp.getPreviousWorkplaces()) {
			std::cout << "  " << wp.toString() << std::endl;
		}
	}
}

void HRDepartment::printByFullName(const std::string& fullName) const {
	auto itEmp = std::find_if(employees.begin(), employees.end(), [&fullName](const Employee& e) {
		return e.getFullName() == fullName;
	});
	if (itEmp != employees.end()) {
		std::cout << itEmp->getInfo() << std::endl;
		return;
	}
	auto itPer = std::find_if(people.begin(), people.end(), [&fullName](const Person& p) {
		return p.getFullName() == fullName;
	});
	if (itPer != people.end()) {
		std::cout << itPer->getInfo() << std::endl;
		return;
	}
	std::cout << "Сотрудник не найден" << std::endl;
}

void HRDepartment::printChildrenOf(const int parentId) const {
	auto parentIt = std::find_if(employees.begin(), employees.end(), [parentId](const Employee& e) {
		return e.getId() == parentId;
	});
	if (parentIt == employees.end()) {
		auto personIt = std::find_if(people.begin(), people.end(), [parentId](const Person& p) {
			return p.getId() == parentId;
		});
		if (personIt != people.end()) {
			std::cout << "Это не сотрудник" << std::endl;
		} else {
			std::cout << "Родитель не найден" << std::endl;
		}
		return;
	}
	std::cout << "Дети: " << parentIt->getFullName() << std::endl;
	for (int childId : parentIt->getChildrenIds()) {
		auto childIt = std::find_if(people.begin(), people.end(), [childId](const Person& p) {
			return p.getId() == childId;
		});
		if (childIt != people.end()) {
			std::cout << childIt->getInfo() << std::endl;
			continue;
		}
		auto childEmpIt = std::find_if(employees.begin(), employees.end(), [childId](const Employee& e) {
			return e.getId() == childId;
		});
		if (childEmpIt != employees.end()) {
			std::cout << childEmpIt->getInfo() << std::endl;
		}
	}
}
