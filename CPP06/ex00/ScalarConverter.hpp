#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <cmath>


# define EMPTY "No empty string are allowed"
# define REQARG "Two arguments are requirted"
# define DECIMAL -1

class ScalarConverter {
private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter& operator=(const ScalarConverter &other);
	~ScalarConverter();

public:
	
	static void toChar(double value);
	static void toInt(double value);
	static void toFloat(double value);
	static void toDouble(double value);

	static void convert(const std::string& literal);

};

#endif