#include <algorithm>
#include <cmath>
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


Answer:	
 */
 
//class TriangularMatrix {
//
//  std::vector<unsigned> values;
//
//  public:
//
//  TriangularMatrix(unsigned _rows) : rows(_rows), values(_rows * (_rows + 1)/2, 0) {};
//
//  std::vector<unsigned>::iterator index(unsigned row, unsigned col) {
//    return values.begin() + (row * (row - 1)/2 + (col-1));
//  }
//
//  unsigned rows;	
//}

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

int main()
{
	unsigned nRows = 15;
	
   	//std::cout << problem_018() << std::endl;
	auto triData = getTreeFromText(nRows);

	nRows -= 2;
	for (; nRows >= 1; --nRows)
	{
		unsigned rowBegin = ((nRows * (nRows+1)) / 2);
		for (auto i = rowBegin; i < (rowBegin + nRows); ++i)
		{
			/*std::cout << "i:\t" << i << '\n';
			std::cout << "data[i]:\t" << triData[i] << '\n';
			std::cout << "children:\t" << triData[i + nRows] << ", " << triData[i + nRows + 1] << '\n';*/
			triData[i] = triData[i] + std::max(triData[i + nRows+1], triData[i + nRows + 2]);
		}
	}
	std::cout << triData[0] << triData[1] << triData[2] << '\n';
    return 0;
}
