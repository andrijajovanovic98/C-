#include "Form.hpp"

// Orthodox Form

Form::Form() : name("default"), isSigned(false), gradeToSign(40), gradeToExecute(80) {};

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned),
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << "The copy constructor is called" << std::endl;
	std::cout << "Form is created with name: " << this->name << std::endl;
	std::cout << "gradeToSign is: " << this->gradeToSign << " and gradetoExecute is ";
	std::cout << this->gradeToExecute << std::endl;
}

Form& Form::operator=(const Form &other) {
	std::cout << "The copy assigment constructor is called" << std::endl;
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	std::cout << "Form is created with name: " << this->name << std::endl;
	std::cout << "gradeToSign is: " << this->gradeToSign << " and gradetoExecute is ";
	std::cout << this->gradeToExecute << std::endl;
	return (*this);
}

Form::~Form() {};

// Another member functions

Form::Form(const std::string &name, bool isSigned, const int gradeToSign, const int gradeToExecute)
 : name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	std::cout << "Form is created with name: " << this->name << std::endl;
	std::cout << "gradeToSign is: " << this->gradeToSign << " and gradetoExecute is ";
	std::cout << this->gradeToExecute << std::endl;
 };


void Form::beSigned(Bureaucrat &person)
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

const char* Form::GradeTooLowException::what() const throw() {
		return "Grade of this Bureaucrat is too low";
};

const char* Form::GradeTooHighException::what() const throw() {
		return "Grade of this Bureaucrat is too heigh";
};


std::string Form::getFormName() const {
	return (this->name);
}

int Form::getGradeToExecute() const {
	return (gradeToExecute);
}


int Form::getGradeToSign() {
	return (gradeToSign);
}

std::string Form::isSignOrNot() const
{
	if (this->isSigned == true)
		return "is signed";
	else
		return "is not signed";
}

std::ostream& operator<<(std::ostream& os, Form& print)
{
	os << "This Form called " << print.getFormName() << " " << print.isSignOrNot();
	os << std::endl;
	os << "gradeToSign is " << print.getGradeToSign();
	os << " and gradeToExecute is " << print.getGradeToExecute();
	os << std::endl;
	return (os);

}

const char* Form::NotSignedexp::what() const throw() {
		return "This Form is still not signed excep";
};

