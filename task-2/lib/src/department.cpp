#include "../include/Department.h"
#include <utility>

Department::Department(std::string name) : name(std::move(name)) {};

std::string Department::getName() const noexcept {return name;}

