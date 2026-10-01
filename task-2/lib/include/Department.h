#pragma once
#include <string>

class Department {
	private:
		std::string name;
	public:
		Department() = default;
		explicit Department(std::string name);

		std::string getName() const noexcept;
};
