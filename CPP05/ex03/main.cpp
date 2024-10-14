#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern someIntern;
    
    Form* form1 = someIntern.makeForm("ShrubberyCreationForm", "Bender");
    Form* form2 = someIntern.makeForm("RobotMRequestForm", "Garden");
    Form* form3 = someIntern.makeForm("PresidentialPardonForm", "Fry");
    Form* form4 = someIntern.makeForm("invalid form", "Nobody");

	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("RobotMRequestForm", "Bender");
	delete rrf;

	(void)form4;
    delete form1;
    delete form2;
    delete form3;
	return (0);
}