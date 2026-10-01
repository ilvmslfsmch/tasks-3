#pragma once

#include <string>

class PreviousWorkplace {
	private:
		std::string company;
		std::string position;
		std::string period;
	public:
		PreviousWorkplace() = default;
		PreviousWorkplace(std::string company, std::string position, std::string period);

		std::string getCompany() const noexcept;
		std::string getPosition() const noexcept;
		std::string getPeriod() const noexcept;
		std::string toString() const;
};
