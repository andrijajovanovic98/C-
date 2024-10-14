#include "AForm.hpp"

// Orthodox AForm

AForm::AForm() : name("default"), isSigned(false), gradeToSign(40), gradeToExecute(80) {};

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned),
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << "The copy constructor is called" << std::endl;
	std::cout << "AForm is created with name: " << this->name << std::endl;
	std::cout << "gradeToSign is: " << this->gradeToSign << " and gradetoExecute is ";
	std::cout << this->gradeToExecute << std::endl;
}

AForm& AForm::operator=(const AForm &other) {
	std::cout << "The copy assigment constructor is called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	std::cout << "AForm is created with name: " << this->name << std::endl;
	std::cout << "gradeToSign is: " << this->gradeToSign << " and gradetoExecute is ";
	std::cout << this->gradeToExecute << std::endl;
	return (*this);
}

AForm::~AForm() {};

// Another member functions

AForm::AForm(const std::string &name, bool isSigned, const int gradeToSign, const int gradeToExecute)
 : name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	std::cout << "AForm is created with name: " << this->name << std::endl;
	std::cout << "gradeToSign is: " << this->gradeToSign << " and gradetoExecute is ";
	std::cout << this->gradeToExecute << std::endl;
 };


void AForm::beSigned(Bureaucrat &person)
{
	if (person.getGrade() > this->gradeToSign && person.getGrade() > this->gradeToExecute)
		throw GradeTooLowException();
	else if (person.getGrade() < 0)
		throw GradeTooHighException();
	else
	{
		this->isSigned = true;
	}
}

const char* AForm::GradeTooLowException::what() const throw() {
		return "Grade of this Bureaucrat is too low";
};

const char* AForm::GradeTooHighException::what() const throw() {
		return "Grade of this Bureaucrat is too heigh";
};


std::string AForm::getAFormName() const {
	return (this->name);
}

int AForm::getGradeToExecute() const {
	return (gradeToExecute);
}


int AForm::getGradeToSign() {
	return (gradeToSign);
}

std::string AForm::isSignOrNot() const
{
	if (this->isSigned == true)
		return "is signed";
	else
		return "is not signed";
}

void	AForm::execute(Bureaucrat const & executor) const { (void)executor;}


std::ostream& operator<<(std::ostream& os, AForm& print)
{
	os << "This AForm called " << print.getAFormName() << " " << print.isSignOrNot();
	os << std::endl;
	os << "gradeToSign is " << print.getGradeToSign();
	os << " and gradeToExecute is " << print.getGradeToExecute();
	os << std::endl;
	return (os);

}

const char* AForm::NotSignedexp::what() const throw() {
		return "This AForm is still not signed excep";
};

