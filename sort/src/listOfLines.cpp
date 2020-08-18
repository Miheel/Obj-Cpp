#include "listOfLines.hpp"

void ListOfLines::readFile(const std::string fileName)
{
	std::ifstream inFile(fileName, std::ios::in);

	if (inFile.is_open())
	{
		while (inFile >> this->line)
		{
			this->lineVec.push_back(this->line);
		}
	}
	else
	{
		std::cerr << "could not open file. make sure the file exists\n";
	}
}

void ListOfLines::readSTD()
{
	while (std::cin >> this->line)
	{
		this->lineVec.push_back(this->line);
	}
}

void ListOfLines::printToFileOrSTD(std::string outFile, bool rFlag, int keyFilter)
{
	std::ofstream outF(outFile);
	std::vector<Line>::iterator begIter, endIter;
	std::vector<Line> temp;
	if (rFlag == false)
	{
		begIter = lineVec.begin();
		endIter = lineVec.end();
	}
	else
	{
		std::reverse_copy(lineVec.begin(), lineVec.end(), std::back_inserter(temp));
		begIter = temp.begin();
		endIter = temp.end();
	}

	for (int i = 0; begIter != endIter; begIter++, i++)
	{
		if (outFile == "")
		{
			std::cout << onlyKey(keyFilter, begIter) << "\n";
		}
		else
		{
			outF << onlyKey(keyFilter, begIter) << "\n";
		}
	}
}

void ListOfLines::sort(int sortProperty, bool numericFlag)
{
	auto lambdaSortRule = [sortProperty, numericFlag](Line &nr1, Line &nr2) -> bool {
		switch (sortProperty)
		{
		case Property::NUMERAL:
			if (numericFlag == true)
			{
				return std::stod(nr1.getNumeral()) < std::stod(nr2.getNumeral());
			}
			else
			{
				return nr1.getNumeral() < nr2.getNumeral();
			}
			break;

		case Property::LITERAL:
			return nr1.getLiteral() < nr2.getLiteral();
			break;

		case Property::ROMAN:
			//roman comp function
			return nr1.getRoman() < nr2.getRoman();
			break;

		default:

			return EXIT_FAILURE;
			break;
		}
	};

	std::sort(lineVec.begin(), lineVec.end(), lambdaSortRule);
}

std::string ListOfLines::onlyKey(int filter, std::vector<Line>::iterator &itr)
{
	switch (filter)
	{
	case Property::NUMERAL:
		return itr->getNumeral();
		break;
	case Property::LITERAL:
		return itr->getLiteral();
		break;
	case Property::ROMAN:
		return itr->getRoman();
		break;
	case Property::Def:
		return itr->toString();
		break;

	default:
		return "Column not found";
		break;
	}
}
