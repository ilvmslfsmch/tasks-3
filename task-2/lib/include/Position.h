#pragma once

#include <string>

class Position {
	private:
		std::string title;
	
	public:
		Position() = default;
		explicit Position(std::string title);

		std::string getTitle() const noexcept;

};
