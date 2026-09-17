#pragma once

#include "Generator.h"

class ConstGenerator : public Generator {
	private:
		int const_value;
	public:
		explicit ConstGenerator(int value);

		~ConstGenerator() override = default;

		int generate() override;
};
