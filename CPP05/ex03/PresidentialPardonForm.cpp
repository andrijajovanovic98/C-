#include "PresidentialPardonForm.hpp"

// Orthodox Form

PresidentialPardonForm::PresidentialPardonForm() : Form::Form("PardonForm", false, 25, 5),  target("random") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form::Form("PardonForm", false, 25, 5),  target(other.target)
{
	std::cout << "The copy constructor is called" << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {

    if (this != &other)
	{ 
        Form::operator=(other);
        this->target = other.target;  
    }
	std::cout << "The copy assignment constructor is called" << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {};

// Another member functions

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form::Form("PardonForm", false, 25, 5),  target(target)
{
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {

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
