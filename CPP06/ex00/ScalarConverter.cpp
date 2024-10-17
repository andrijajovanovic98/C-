#include "ScalarConverter.hpp"

int 	handlePseudoLiterals(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (1);
	}
	if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (1);
	}
	if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (1);
	}
	return (0);
}

void ScalarConverter::convert(const std::string &literal)
{
	char* endPtr;
	double value = std::strtod(literal.c_str(), &endPtr);
	double valuetoChar = value;

	if (handlePseudoLiterals(literal) == 1)
		return ;
	if ((*endPtr != '\0' && *endPtr != 'f') || literal == "inf") {
		std::cerr << "Error: Invalid input" << std::endl;
		return;
	}
	for (std::string::const_iterator it = literal.begin(); it != literal.end(); ++it)
	{
		if (*it == '.')
		{
			valuetoChar = DECIMAL;
		}
		if (*it == '.' && it + 1 == literal.end())
		{
			std::cout << "Error: Invalid input" << std::endl;
			return;
		}
	}
	toChar(valuetoChar);
	toInt(value);
	toFloat(value);
	toDouble(value);
}

void ScalarConverter::toChar(double value)
{
	
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
		std::cout << "char: impossible" << std::endl;
	}
	else {
		char c = static_cast<char>(value);
		if (std::isprint(c)) {
			std::cout << "char: '" << c << "'" << std::endl; }
		else {
			std::cout << "char: Non displayable" << std::endl;
		}
	}
}

void ScalarConverter::toInt(double value)
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
	{
		int c = static_cast<int>(value);
		std::cout << "int: " << c << std::endl;
	}
}

void ScalarConverter::toFloat(double value)
{
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
	{
		float c = static_cast<float>(value);
		if (c == static_cast<int>(c))
			std::cout << "float: " << c << ".0f" << std::endl;
		else 
			std::cout << "float: " << c << "f" << std::endl;
	}
}

void ScalarConverter::toDouble(double value)
{
	if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
	{
		if (value == static_cast<int>(value))
			std::cout << "double: " << value << ".0" << std::endl;
		else
			std::cout << "double: " << value << std::endl;
	}
}

// Orthodox Form


ScalarConverter::ScalarConverter() {};
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other) {
		
	}
	return (*this);
}
ScalarConverter::~ScalarConverter() {};