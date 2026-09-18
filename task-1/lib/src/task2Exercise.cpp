#include <vector>

#include "../include/Task2Exercise.h"

Task2Exercise::Task2Exercise(Matrix& src, Generator& gen) : Exercise(src, gen) {}

Matrix Task2Exercise::solve() {
	const size_t rows = source.getRows();
	const size_t columns =  source.getColumns();

	if (rows == 0 || columns == 0) {return Matrix();}

	int maxValue = source[0][0];
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			if (source[i][j] > maxValue) {
				maxValue = source[i][j];
			}
		}
	}

	std::vector<size_t> keptRows;
	keptRows.reserve(rows);
	for (size_t i = 0; i < rows; i++) {
		bool hasMax = false;
		for (size_t j = 0; j < columns; j++) {
			if (source[i][j] == maxValue) {
				hasMax = true;
				break;
			}
		}
		if (!hasMax) {
			keptRows.push_back(i);
		}
	}

	Matrix result(keptRows.size(), columns);
	for (size_t r = 0; r < keptRows.size(); r++) {
		for (size_t c = 0; c < columns; c++) {
			result[r][c] = source[keptRows[r]][c];
		}
	}

	return result;
}
