#include <algorithm>
#include <cmath>
#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>




/*Problem 67

Maximum path sum II

Problem 67
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)

Answer:	7273
 */

template<typename T>
std::vector<T> getTreeFromText(unsigned nRows, std::string filename = "triangle.txt") {
	std::ifstream infile(filename);
	std::string line;
	std::vector<T> v;
	v.reserve((nRows * (nRows + 1)) / 2);


	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		T n;

		while (iss >> n)
		{
			v.push_back(n);
		}
	}

	return v;
}

//TriangularMatrix collapseBottomRow(TriangularMatrix& triMatrix) {
//
//  return 
//}

unsigned maximum_path_from_tree(const unsigned nRows, const std::vector<unsigned> data)
{
	auto currRow = nRows;
	auto row_begin = data.begin() + (currRow * (currRow - 1) / 2);
	auto row_end = row_begin + currRow;
	auto result = std::vector<unsigned>(row_begin, row_end);
	while (currRow > 1)
	{
		// Take pairwise max of result
		for (auto val = result.begin(); val != (result.end() - 1); ++val)
		{
			if (*(val + 1) > * val)
			{
				*val = *(val + 1);
			}
		}

		// Remove garbage last element
		result.pop_back();

		--currRow;

		auto row_begin = data.begin() + (currRow * (currRow - 1) / 2);

		// Add results
		std::transform(result.begin(), result.end(), row_begin, result.begin(), std::plus<unsigned>());
	}

	return result[0];
}

int main(void) {

	const unsigned nRows = 100;
	auto data = getTreeFromText<unsigned>(nRows, "triangle.txt");

	// Get starting timepoint 
	auto start = std::chrono::high_resolution_clock::now();

	// Call the function, here sort() 
	auto answer = maximum_path_from_tree(nRows, data);
	// Get ending timepoint 
	auto stop = std::chrono::high_resolution_clock::now();

	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "Answer: " << answer << '\n';

	std::cout << "Time: " 
		<< duration.count() << "microseconds" << std::endl;



	return 0;
}
