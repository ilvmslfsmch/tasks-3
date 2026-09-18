#pragma once

#include "Matrix.h"
#include "Generator.h"

class Exercise {
	protected:
		Matrix& source;
		Generator& generator;
	public:
		Exercise(Matrix& src, Generator& gen);
		virtual ~Exercise() = default;
		virtual Matrix solve() = 0;

};
