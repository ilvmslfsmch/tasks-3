#include "../include/HRDepartment.h"
#include <iostream>
#include <map>
#include <algorithm>

void HRDepartment::addPerson(std::unique_ptr<Person> person) {
	people.push_back(std::move(person));
}

void HRDepartment::addDepartment(const Department& department) {
	departments.push_back(department);
}

void HRDepartment::addPosition(const Position& position) {
	positions.push_back(position);
}

const std::vector<std::unique_ptr<Person>>& HRDepartment::getPeople() const noexcept {
	return people;
}

void HRDepartment::printAll() const {
	for (const auto& p : people) {
		std::cout << p->getInfo() << std::endl;
	}
}

void HRDepartment::printByPosition(const std::string& positionTitle) const {
	for (const auto& p : people) {
		auto emp = dynamic_cast<Employee*>(p.get());
		if (emp && emp->getPosition().getTitle() == positionTitle) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printByRate(const double rate) const {
	for (const auto& p : people) {
		auto emp = dynamic_cast<Employee*>(p.get());
		if (emp && emp->getRate() == rate) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printWithChildren() const {
	for (const auto& p : people) {
		auto emp = dynamic_cast<Employee*>(p.get());
		if (emp && emp->hasChildren()) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printPensioners() const {
	for (const auto& p : people) {
		auto emp = dynamic_cast<Employee*>(p.get());
		if (emp && emp->isPensioner()) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printDisabled() const {
	for (const auto& p : people) {
		auto emp = dynamic_cast<Employee*>(p.get());
		if (emp && emp->isDisabled()) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printOnVacation() const {
	for (const auto& p : people) {
		auto emp = dynamic_cast<Employee*>(p.get());
		if (emp && emp->isOnVacation()) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printOnMaternityLeave() const {
	for (const auto& p : people) {
		auto emp = dynamic_cast<Employee*>(p.get());
		if (emp && emp->isOnMaternityLeave()) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printPositionInfo() const {
	std::map<std::string, int> counter;
	for (const auto& p : people) {
		auto emp = dynamic_cast<Employee*>(p.get());
		if (emp) {
			counter[emp->getPosition().getTitle()]++;
		}
	}
	for (const auto& [title, count] : counter) {
		std::cout << title << ": " << count << std::endl;
	}
}

void HRDepartment::printPreviousWorkplaces() const {
	for (const auto& p : people) {
		auto emp = dynamic_cast<Employee*>(p.get());
		if (!emp) continue;
		std::cout << emp->getFullName() << ":" << std::endl;
		for (const auto& wp : emp->getPreviousWorkplaces()) {
			std::cout << "  " << wp.toString() << std::endl;
		}
	}
}

void HRDepartment::printByFullName(const std::string& fullName) const {
	auto it = std::find_if(people.begin(), people.end(), [&fullName](const std::unique_ptr<Person>& p) {
				return p->getFullName() == fullName;
			});
	if (it != people.end()) {
		std::cout << (*it)->getInfo() << std::endl;
	} else {
		std::cout << "Сотрудник не найден" << std::endl;
	}
}

void HRDepartment::printChildrenOf(const int parentId) const {
	auto parentIt = std::find_if(people.begin(), people.end(), [parentId](const std::unique_ptr<Person>& p) {
				return p->getId() == parentId;
			});
	if (parentIt == people.end()) {
		std::cout << "Родитель не найден" << std::endl;
		return;
	}
	auto emp = dynamic_cast<Employee*>(parentIt->get());
	if (!emp) {
		std::cout << "Это не сотрудник" << std::endl;
		return;
	}
	std::cout << "Дети: " << emp->getFullName() << std::endl;
	for (int childId : emp->getChildrenIds()) {
		auto childIt = std::find_if(people.begin(), people.end(), [childId](const std::unique_ptr<Person>& p) {
					return p->getId() == childId;
				});
		if (childIt != people.end()) {
			std::cout << (*childIt)->getInfo() << std::endl;
		}
	}
}
