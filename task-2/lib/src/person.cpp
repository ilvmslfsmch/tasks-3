#include "../include/Person.h"
#include <utility>

Person::Person() : id(0) {}

Person::Person(int id, std::string fullName, std::string birthDate) : id(id), fullName(std::move(fullName)), birthDate(std::move(birthDate)) {}

int Person::getId() const noexcept {return id;}

std::string Person::getFullName() const noexcept {return fullName;}

std::string Person::getBirthDate() const noexcept {return birthDate;}

std::string Person::getInfo() const {
	return "ID: " + std::to_string(id) + 
		" | ФИО:" + fullName + 
		" | Дата рождения: " + birthDate;
}
