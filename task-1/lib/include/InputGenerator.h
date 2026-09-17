#pragma once

#include <iosfwd>

#include "Generator.h"

class InputGenerator : public Generator {
	private:
		std::istream& input;
	
	public:
		explicit InputGenerator(std::istream& input_value);

		~InputGenerator() override = default;

		int generate() override;
};
