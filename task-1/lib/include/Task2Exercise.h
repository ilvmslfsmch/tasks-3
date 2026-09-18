#pragma once

#include "Exercise.h"

class Task2Exercise : public Exercise {
	public:
		Task2Exercise(Matrix& src, Generator& gen);

		~Task2Exercise() override = default;

		Matrix solve() override;
};
