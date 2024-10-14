#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{

  	try {
	Bureaucrat person("Orban", 6);
	PresidentialPardonAForm KillAForm("Merenylo");
	person.signAForm(KillAForm);
	person.executeAForm(KillAForm);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
 		Bureaucrat person("Thunder", 60);
		RobotMyRequestAForm RobotAForm("Me");
		person.signAForm(RobotAForm);
		RobotAForm.execute(person);		
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << std::endl;
	try {
		Bureaucrat person("Thomas", 150);
		ShrubberyCreationAForm test("Home");
		person.signAForm(test);
		test.execute(person);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat person("MusterMaxx", 1);
		ShrubberyCreationAForm test("Home");
		person.signAForm(test);
		test.execute(person);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
 	try {
		Bureaucrat person("LowMax", 138);
		ShrubberyCreationAForm test("Home");
		person.signAForm(test);
		test.execute(person);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}