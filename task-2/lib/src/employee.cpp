#include "../include/Employee.h"
#include <utility>

Employee::Employee() : Person(), rate(1.0), pensioner(false), disabled(false), onVacation(false), onMaternityLeave(false) {}

Employee::Employee(int id, std::string fullName, std::string birthDate, std::string position, std::string department, double rate) : Person(id, std::move(fullName), std::move(birthDate)), position(std::move(position)), department(std::move(department)), rate(rate), pensioner(false), disabled(false), onVacation(false), onMaternityLeave(false) {}

std::string Employee::getPosition() const noexcept {return position;}

std::string Employee::getDepartment() const noexcept {return department;}

double Employee::getRate() const noexcept {return rate;}

const std::vector<PreviousWorkplace>& Employee::getPreviousWorkplaces() const noexcept {
	return previousWorkplace;
}

const std::vector<int>& Employee::getChildrenIds() const noexcept {
	return childrenIds;
}

void Employee::addPreviousWorkplace(const PreviousWorkplace& wp) {
	previousWorkplace.push_back(wp);
}

void Employee::addChildId(int childId) {
	childrenIds.push_back(childId);
}

void Employee::setFlags(bool pensioner, bool disabled, bool onVacation, bool onMaternityLeave) {
	this -> pensioner = pensioner;
	this -> disabled = disabled;
	this -> onVacation = onVacation;
	this -> onMaternityLeave = onMaternityLeave;
}

bool Employee::hasChildren() const noexcept {return !childrenIds.empty();}
bool Employee::isPensioner() const noexcept {return pensioner;}
bool Employee::isDisabled() const noexcept {return disabled;}
bool Employee::isOnVacation() const noexcept {return onVacation;}
bool Employee::isOnMaternityLeave() const noexcept {return onMaternityLeave;}

std::string Employee::getInfo() const {
	std::string result = Person::getInfo();
	result += " | Должность: " + position;
	result += " | Отдел: " + department;
	result += " | Ставка: " + std::to_string(rate);
	result += " | Дети: ";
	result += hasChildren() ? std::to_string(childrenIds.size()) : "Нет";
	if (pensioner) result += " | Пенсионер";
	if (disabled) result += " | Инвалид";
	if (onVacation) result += " | В отпуске";
	if (onMaternityLeave) result += " | В декретном отпуске";
	return result;
}
