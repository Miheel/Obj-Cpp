#ifndef LISTOFLINES_HPP
#define LISTOFLINES_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

#include "line.hpp"
#include "helpFunk.hpp"

class ListOfLines
{
public:
	/**
	*	Read a file line by line and push each line in to a vector.
	*
	*	@param fileName The name of the file to read from.
	*   @return a vector containing the lines from the file.
	*/
	void readFile(const std::string fileName);

	/**
	 *	Read from standard in line by line and push each line in to a vector.
	 *
	 */
	void readSTD();

	void printToFileOrSTD(std::string outFile, bool rFlag, int keyFilter);

	void sort(int, bool);

private:
	Line line;
	std::vector<Line> lineVec;

	std::string onlyKey(int filter, std::vector<Line>::iterator &itr);
};

#endif // !LISTOFLINES_HPP
