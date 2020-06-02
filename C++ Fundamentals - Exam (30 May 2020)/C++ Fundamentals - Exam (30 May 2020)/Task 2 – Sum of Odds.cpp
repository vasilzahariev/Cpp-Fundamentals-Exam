#include <iostream>
#include <vector>

int main2() {
	std::vector< std::vector<int> > matrix;
	int n;

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		matrix.push_back(std::vector<int>());

		for (int u = 0; u < n; u++) {
			int input;

			std::cin >> input;

			matrix[i].push_back(input);
		}
	}

	int sum = 0;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			int number = matrix[row][col];

			if (number % 2 != 0 &&
				col != row &&
				col != n - 1 - row)
				sum += number;
		}
	}

	std::cout << "The sum is: " << sum << std::endl;

	return 0;
}
