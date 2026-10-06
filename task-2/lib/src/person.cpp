#include "../include/Person.h"
#include <utility>

Person::Person() : id(0) {}

Person::Person(const int id, const std::string& fullName, const std::string& birthDate)
	: id(id), fullName(fullName), birthDate(birthDate) {}

int Person::getId() const noexcept {return id;}

const std::string& Person::getFullName() const noexcept {return fullName;}

const std::string& Person::getBirthDate() const noexcept {return birthDate;}

std::string Person::getInfo() const {
	return "ID: " + std::to_string(id) + 
		" | ФИО: " + fullName + 
		" | Дата рождения: " + birthDate;
}
