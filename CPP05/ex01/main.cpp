#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try {
		Bureaucrat person("Thomson", 2);
		Form fok1("Thunberg", false, 20, 1);
		person.signForm(fok1);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat person("OlderBrother", 51);
		Form fok1("Trip", false, 20, 1);
		person.signForm(fok1);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat person("Thomson", 2);
		Form fok1("Thunberg", false, 20, 1);
		Form fok2("Trip", false, 40, 20);
		Form fok3(fok1);
		person.signForm(fok1);
		fok3 = fok2;
		std::cout << std::endl << fok3;
		person.signForm(fok3);
		std::cout << std::endl << fok2;

	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    return (0);
}