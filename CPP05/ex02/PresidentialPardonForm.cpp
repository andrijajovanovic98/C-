#include "PresidentialPardonForm.hpp"

// Orthodox AForm

PresidentialPardonAForm::PresidentialPardonAForm() : AForm::AForm("PardonAForm", false, 25, 5),  target("random") {}

PresidentialPardonAForm::PresidentialPardonAForm(const PresidentialPardonAForm &other) : AForm::AForm("PardonAForm", false, 25, 5),  target(other.target)
{
	std::cout << "The copy constructor is called" << std::endl;
}
PresidentialPardonAForm& PresidentialPardonAForm::operator=(const PresidentialPardonAForm& other) {

    if (this != &other)
	{ 
        AForm::operator=(other);
        this->target = other.target;  
    }
	std::cout << "The copy assignment constructor is called" << std::endl;

    return (*this);
}

PresidentialPardonAForm::~PresidentialPardonAForm() {};

// Another member functions

PresidentialPardonAForm::PresidentialPardonAForm(std::string target) : AForm::AForm("PardonAForm", false, 25, 5),  target(target)
{
}

void	PresidentialPardonAForm::execute(Bureaucrat const & executor) const {

	if (isSignOrNot() == "is not signed")
		throw NotSignedexp();
	if (executor.getGrade() >  this->getGradeToExecute())
	{
		std::cout << "Sorry but " << "the bureaucrat" << " need to be minimum grade: " << this->getGradeToExecute() << std::endl;
		throw GradeTooLowException();
	}
	if (isSignOrNot() == "is signed" && this->getGradeToExecute() > executor.getGrade())
		std::cout << this->target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}
