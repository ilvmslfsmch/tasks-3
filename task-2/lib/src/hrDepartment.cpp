#include "../include/HRDepartment.h"
#include <iostream>
#include <map>
#include <algorithm>

HRDepartment::~HRDepartment() {
	for (Person* p : people) {
		delete p;
	}
}

void HRDepartment::addPerson(Person* person) {
	people.push_back(person);
}

void HRDepartment::addDepartment(const Department& department) {
	departments.push_back(department);
}

void HRDepartment::addPosition(const Position& position) {
	positions.push_back(position);
}

const std::vector<Person*>& HRDepartment::getPeople() const noexcept {
	return people;
}

void HRDepartment::printAll() const {
	for (Person* p : people) {
		std::cout << p->getInfo() << std::endl;
	}
}

void HRDepartment::printByPosition(const std::string& positionTitle) const {
	for (Person* p : people) {
		Employee* emp = dynamic_cast<Employee*>(p);
		if (emp && emp->getPosition().getTitle() == positionTitle) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printByRate(const double rate) const {
	for (Person* p : people) {
		Employee* emp = dynamic_cast<Employee*>(p);
		if (emp && emp->getRate() == rate) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printWithChildren() const {
	for (Person* p : people) {
		Employee* emp = dynamic_cast<Employee*>(p);
		if (emp && emp->hasChildren()) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printPensioners() const {
	for (Person* p : people) {
		Employee* emp = dynamic_cast<Employee*>(p);
		if (emp && emp->isPensioner()) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printDisabled() const {
	for (Person* p : people) {
		Employee* emp = dynamic_cast<Employee*>(p);
		if (emp && emp->isDisabled()) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printOnVacation() const {
	for (Person* p : people) {
		Employee* emp = dynamic_cast<Employee*>(p);
		if (emp && emp->isOnVacation()) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printOnMaternityLeave() const {
	for (Person* p : people) {
		Employee* emp = dynamic_cast<Employee*>(p);
		if (emp && emp->isOnMaternityLeave()) {
			std::cout << emp->getInfo() << std::endl;
		}
	}
}

void HRDepartment::printPositionInfo() const {
	std::map<std::string, int> counter;
	for (Person* p : people) {
		Employee* emp = dynamic_cast<Employee*>(p);
		if (emp) {
			counter[emp->getPosition().getTitle()]++;
		}
	}
	for (const auto& [title, count] : counter) {
		std::cout << title << ": " << count << std::endl;
	}
}

void HRDepartment::printPreviousWorkplaces() const {
	for (Person* p : people) {
		Employee* emp = dynamic_cast<Employee*>(p);
		if (!emp) continue;
		std::cout << emp->getFullName() << ":" << std::endl;
		for (const PreviousWorkplace& wp : emp->getPreviousWorkplaces()) {
			std::cout << "  " << wp.toString() << std::endl;
		}
	}
}

void HRDepartment::printByFullName(const std::string& fullName) const {
	std::vector<Person*>::const_iterator it = std::find_if(people.begin(), people.end(), [&fullName](const Person* p) {
				return p->getFullName() == fullName;
			});
	if (it != people.end()) {
		std::cout << (*it)->getInfo() << std::endl;
	} else {
		std::cout << "Сотрудник не найден" << std::endl;
	}
}

void HRDepartment::printChildrenOf(const int parentId) const {
	std::vector<Person*>::const_iterator parentIt = std::find_if(people.begin(), people.end(), [parentId](const Person* p) {
				return p->getId() == parentId;
			});
	if (parentIt == people.end()) {
		std::cout << "Родитель не найден" << std::endl;
		return;
	}
	Employee* emp = dynamic_cast<Employee*>(*parentIt);
	if (!emp) {
		std::cout << "Это не сотрудник" << std::endl;
		return;
	}
	std::cout << "Дети: " << emp->getFullName() << std::endl;
	for (int childId : emp->getChildrenIds()) {
		std::vector<Person*>::const_iterator childIt = std::find_if(people.begin(), people.end(), [childId](const Person* p) {
					return p->getId() == childId;
				});
		if (childIt != people.end()) {
			std::cout << (*childIt)->getInfo() << std::endl;
		}
	}
}
