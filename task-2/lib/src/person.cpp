#include "../include/Person.h"
#include <utility>

int Person::nextId = 1;

Person::Person() : id(nextId++) {}

Person::Person(std::string fullName, std::string birthDate) : id(nextId++), fullName(std::move(fullName)), birthDate(std::move(birthDate)) {}

int Person::getId() const noexcept {return id;}

std::string Person::getFullName() const noexcept {return fullName;}

std::string Person::getBirthDate() const noexcept {return birthDate;}

std::string Person::getInfo() const {
	return "ID: " + std::to_string(id) + 
		" | ФИО:" + fullName + 
		" | Дата рождения: " + birthDate;
}
