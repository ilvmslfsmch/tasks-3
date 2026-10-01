#pragma once
#include "Person.h"
#include "Position.h"
#include "Department.h"
#include "PreviousWorkplace.h"
#include <vector>

class Employee : public Person {
	private:
		Position position;
		Department department;
		double rate;
		std::vector<PreviousWorkplace> previousWorkplace;
		std::vector<int> childrenIds;

		bool pensioner;
		bool disabled;
		bool onVacation;
		bool onMaternityLeave;

	public:
		Employee();
		Employee(std::string fullName, std::string birthDate, Position position, Department department, double rate);
		const Position& getPosition() const noexcept;
		const Department& getDepartment() const noexcept;
		double getRate() const noexcept;
		const std::vector<PreviousWorkplace>& getPreviousWorkplaces() const noexcept;
		const std::vector<int>& getChildrenIds() const noexcept;

		void addPreviousWorkplace(const PreviousWorkplace& wp);
		void addChildId(int childId);
		void setFlags(bool pensioner, bool disabled, bool onVacation, bool onMaternityLeave);

		bool hasChildren() const noexcept;
		bool isPensioner() const noexcept;
		bool isDisabled() const noexcept;
		bool isOnVacation() const noexcept;
		bool isOnMaternityLeave() const noexcept;

		std::string getInfo() const override;
};
