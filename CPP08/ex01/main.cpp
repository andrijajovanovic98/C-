#include "Span.hpp"

int main(void)
{
	try {
		
		Span first(3);
		first.addNumber(1);
		first.addNumber(5);
		first.addNumber(8);
		first.printOutTheValues();
		std::cout << std::endl;
		std::cout << "shortestSpan: " << first.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << first.longestSpan() << std::endl;
		
		std::cout << "__________________________________" << std::endl;
		std::cout << std::endl;
		
		Span brap(first);
		
		brap.printOutTheValues();
		std::cout << std::endl;
		std::cout << "shortSpan: " << brap.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << brap.longestSpan() << std::endl;
		
		std::cout << "__________________________________" << std::endl;
		std::cout << std::endl;
		
		Span copyass(1);
		copyass = first;
		copyass.printOutTheValues();
		copyass.addNumber(8);

	}
	catch (const std::string &e)
	{
		std::cout << e << std::endl;
		std::cout << "__________________________________" << std::endl;

	}
	
	std::cout << std::endl;
	try {

		Span secound(51);
		secound.addRange(50);
		std::cout << "The shortestSpan is: " << secound.shortestSpan() << std::endl;
		std::cout << "The longestSpan is: " << secound.longestSpan() << std::endl;
		std::cout << "__________________________________" << std::endl;

	}
	catch (const std::string &e)
	{
		std::cout << e << std::endl;
	}

	std::cout << std::endl;
	try {
		Span third(50);
		third.addRange(51);
		std::cout << ":(";
	}
	catch (const std::string &e)
	{
		std::cout << e << std::endl;
		std::cout << "__________________________________" << std::endl;

	}

	std::cout << std::endl;
	try {
		Span first(5);
		first.addNumber(100);
		first.addNumber(5);
		first.addNumber(-4);
		first.addNumber(60);
		first.addNumber(-2147483648);
		first.printOutTheValues();
		std::cout << std::endl;
		std::cout << "shortestSpan: " << first.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << first.longestSpan() << std::endl;
		std::cout << "__________________________________" << std::endl;

	}
	catch (const std::string &e)
	{
		std::cout << e << std::endl;
	}
	return (0);
}


/* int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
} */