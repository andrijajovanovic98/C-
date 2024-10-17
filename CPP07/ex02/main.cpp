#include "Array.hpp"

int main(void)
{
	try {
		Array<int> numbers;
		std::cout << numbers.size() << std::endl;
	}

	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		Array<int> numbers(1);
		numbers[0] = 5;
		numbers[1] = 6;
		numbers[2] = 6;
		std::cout << "The value is: " << numbers[0] << std::endl;
	}

	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		Array<int> numbers(3);
		numbers[0] = 5;
		numbers[1] = 6;
		numbers[2] = 6;
		Array<int> testcopy(numbers);
		std::cout << testcopy[0] << std::endl;
		testcopy[0] = 1;
		std::cout << testcopy[0] << std::endl;
		testcopy = numbers;
		std::cout << testcopy[0] << std::endl;
	}

	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

/* 
int main (void)
{
	
	try {
		Array<float> newarray(2);
		newarray[0] = 23.23f;
		newarray[1] = 43.23f;
		newarray[2] = 53.23f;
		std::cout << "the values are: ";
		std::cout << newarray[0] << std::endl;
		std::cout << newarray[1] << std::endl;
		std::cout << newarray[2] << std::endl;
		std::cout << "Noice" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
} */

/* 
int main(void)
{
	try {
		Array<double> newarray(3);
		newarray[0] = 12.3;
		newarray[2] = 22.3;
		newarray[1] = 2.3;
		std::cout << newarray[0] << std::endl;
		std::cout << newarray[1] << std::endl;
		std::cout << newarray[2] << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;

	}
	return (0);
} */