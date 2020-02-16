#include <algorithm>
#include <cmath>
#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>




/*Problem 18

Maximum path sum I


By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

               3
              7 4
             2 4 6
            8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

                          75
                         95 64
                       17 47 82
                     18 35 87 10
                    20 04 82 47 65
                  19 01 23 75 03 34
                88 02 77 73 07 63 67
              99 65 04 28 06 16 70 92
            41 41 26 56 83 40 80 70 33
          41 48 72 33 47 32 37 16 94 29
        53 71 44 65 25 43 91 52 97 51 14
      70 11 33 28 77 73 17 78 39 68 17 57
    91 71 52 38 17 14 91 43 58 50 27 29 48
  63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)


Answer:	1074
 */
 

std::vector<unsigned> getTreeFromText(unsigned nRows, std::string filename = "input.txt") {
  std::ifstream infile(filename);
  std::string line;
  std::vector<unsigned> v;
  v.reserve((nRows * (nRows + 1)) / 2);
  

  while (std::getline(infile, line))
  {
	std::istringstream iss(line);
    unsigned n;    

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
		auto row_end = row_begin + currRow;

		// Add results
		std::transform(result.begin(), result.end(), row_begin, result.begin(), std::plus<unsigned>());
	}

	return result[0];
}

int main(void) {

	const unsigned nRows = 15;
	auto data = getTreeFromText(nRows, "input.txt");

	// Get starting timepoint 
	auto start = std::chrono::high_resolution_clock::now();

	// Call the function, here sort() 
	auto answer = maximum_path_from_tree(nRows, data);
	// Get ending timepoint 
	auto stop = std::chrono::high_resolution_clock::now();

	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

	std::cout << "Answer: " << answer << '\n';

	std::cout << "Time: "
		<< duration.count() << " ns" << std::endl;
	


    return 0;
}
