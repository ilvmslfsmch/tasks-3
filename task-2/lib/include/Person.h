#pragma once

#include <string>

class Person {
	protected:
		int id;
		std::string fullName;
		std::string birthDate;

	public:
		Person();
		Person(int id, std::string fullName, std::string birthDate);
		virtual ~Person() = default;

		int getId() const noexcept;
		std::string getFullName() const noexcept;
		std::string getBirthDate() const noexcept;

		virtual std::string getInfo() const;
};
