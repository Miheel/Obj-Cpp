#include "helpFunk.hpp"

std::istream &operator>>(std::istream &in, Line &other)
{
	std::string numeral, literal, roman;

	in >> numeral;
	in >> literal;
	in >> roman;

	other.setNumeral(numeral);
	other.setLiteral(literal);
	other.setRoman(roman);

	return in;
}

std::ostream &operator<<(std::ostream &out, const Line &other)
{
	return out << other.toString();
}

void help()
{
	std::cout << "--numeric | -n. Behandla sorterinsdatat som numeriska varden. Aven decimaltal ska hanteras.\n"
			  << "--reverse | -r. Skriv ut resultattet i omvand ordning.\n"
			  << "(--output | -o)FILE. Skriv resultatet till filen FILE istallet for standard ut.\n"
			  << "(--input  | -i)File. Anand FILE som indata\n"
			  << "(--column | -c)N. Sortera med avseende pa kolumn N\n"
			  << "--keyonly | -k. ge bara det sorterade vardet pa rad\n"
			  << "--version | -v. Skriver ut versionsnummer.\n"
			  << "--help 	| -h. Skriver ut tillgangliga switchar.\n";
}

void version()
{
	std::cout << "version: 1.0\n";
}
