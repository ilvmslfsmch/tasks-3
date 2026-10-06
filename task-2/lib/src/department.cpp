#include "../include/Department.h"
#include <utility>

Department::Department(const std::string& name) : name(name) {}

const std::string& Department::getName() const noexcept {return name;}

