#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{	
	if (argc != 2 || !*argv[1])
	{
		if (argc != 2)
		{
			std::cout << REQARG << std::endl;
			return (0);
		}
		else
		{
			std::cout << EMPTY << std::endl;
			return (0);
		}
	}
 	ScalarConverter::convert((argv[1]));
	return (0); 
}