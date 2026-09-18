#pragma once

#include "Exercise.h"

class Task1Exercise : public Exercise {
	public:
		Task1Exercise(Matrix& src, Generator& gen);
		~Task1Exercise() override = default;
		Matrix solve() override;
};
