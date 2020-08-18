#include <getopt.h>
#include <unistd.h>
#include <iostream>
#include <string>

#include "helpFunk.hpp"
#include "listOfLines.hpp"

int main(int argc, char **argv)
{
	ListOfLines listOfLines;

	std::string outPutFile = "", inPutFile = "";

	bool reverseFlag = false, numericFlag = false;
	int sortProperty = Property::NUMERAL, keyProperty = Property::Def;

	static struct option long_options[] =
		{
			{"numeric", no_argument, nullptr, 'n'},
			{"reverse", no_argument, nullptr, 'r'},
			{"output", required_argument, nullptr, 'o'},
			{"input", required_argument, nullptr, 'i'},
			{"column", required_argument, nullptr, 'c'},
			{"keyonly", no_argument, nullptr, 'k'},
			{"version", no_argument, nullptr, 'v'},
			{"help", no_argument, nullptr, 'h'}};

	int option;
	const char *shortopt = "nro:i:c:kvh";

	while ((option = getopt_long(argc, argv, shortopt, long_options, nullptr)) != -1)
	{
		switch (option)
		{
		case 'n': //numeric
			numericFlag = true;
			break;

		case 'r': //reverced
			reverseFlag = true;
			break;

		case 'o': //outputfile
			outPutFile = optarg;
			break;

		case 'i': //inoutfile
			inPutFile = optarg;
			break;

		case 'c': //column
			switch (optarg[0])
			{
			case '0':
				sortProperty = Property::NUMERAL;
				break;
			case '1':
				sortProperty = Property::LITERAL;
				break;
			case '2':
				sortProperty = Property::ROMAN;
				break;
			default:
				std::cout << "column not found or switch wasn't followed my a digit\n";
				return EXIT_FAILURE;
				break;
			}
			break;

		case 'k': //keyonly
			keyProperty = sortProperty;
			break;

		case 'v': //version
			version();
			return EXIT_SUCCESS;

		case 'h': //help
			help();
			return EXIT_SUCCESS;
			
		default:
			return EXIT_FAILURE;
			break;
		}
	}

	if (isatty(STDIN_FILENO) && inPutFile == "")
	{
		std::cerr << "no input found\n";
		return EXIT_FAILURE;
	}
	else
	{
		if (inPutFile == "")
		{
			listOfLines.readSTD();
		}
		else
		{
			listOfLines.readFile(inPutFile);
		}
	}

	listOfLines.sort(sortProperty, numericFlag);
	listOfLines.printToFileOrSTD(outPutFile, reverseFlag, keyProperty);

	return EXIT_SUCCESS;
}
