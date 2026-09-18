#include <cstdlib>

#include "../include/Task1Exercise.h"

Task1Exercise::Task1Exercise(Matrix& src, Generator& gen) : Exercise(src, gen) {}

Matrix Task1Exercise::solve() {
	Matrix result(source);

	const size_t rows = result.getRows();
	const size_t columns = result.getColumns();

	if (rows == 0 || columns == 0) {return result;}

	

	for (size_t j = 0; j < columns; j++) {
		size_t minRow = 0;
		int minAbs = std::abs(result[0][j]);
		for (size_t i = 1; i < rows; i++) {
			int curAbs = std::abs(result[i][j]);
			if (curAbs < minAbs) {
				minAbs = curAbs;
				minRow = i;
			}
		}
		result[minRow][j] = -result[minRow][j];
	}
	return result;
}
