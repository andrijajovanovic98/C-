#include "Bureaucrat.hpp"

int	main(void)
{
	try {
		Bureaucrat persontest("Milgouer", 1);
		std::cout << persontest;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
	 	Bureaucrat person("Wolfstein", 110);
		Bureaucrat copyperson(person);
		std::cout << person.getName() << std::endl;
		std::cout << person.getGrade() << std::endl;
		person.incrementGrade();
		std::cout << person.getGrade() << std::endl;
		person.decrementGrade();
		person.decrementGrade();
		std::cout << person;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		throw Bureaucrat::GradeTooLowException();
	}
	catch (const Bureaucrat::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}

	try {
		throw Bureaucrat::GradeTooHeighException();
	}
	catch (const Bureaucrat::GradeTooHeighException& e){
		std::cout << e.what() << std::endl;
	}
	try {
	Bureaucrat person2("Steiner", 151);
	}
	catch(const std::exception& e) {
		std::cout << "Sorry but " << e.what() << std::endl;
	}
	try {
	Bureaucrat person2("Koppenhauer", -1);
	}
	catch(const std::exception& e) {
		std::cout << "Sorry but " << e.what() << std::endl;
	}

    return (0);
}