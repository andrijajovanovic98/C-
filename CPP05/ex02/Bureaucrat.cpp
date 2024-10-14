#include "Bureaucrat.hpp"

// ORTHODOX AForm

Bureaucrat::Bureaucrat() : name("default"), grade(100){
	std::cout << "Default Bureaucrat is created" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "The copy constructor is called" << std::endl;
	std::cout << "The name is: " << this->name;
	std::cout << " And the grade is: " << this->grade << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "The copy assigment constructor is called" << std::endl;
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {};

// Anothe member functions

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHeighException();
	std::cout << "The name is: " << this->name << " and ";
	std::cout << "The grade is: " << this->grade << std::endl;
}

const char* Bureaucrat::GradeTooHeighException::what() const throw() {
		return "Grade is too heigh";
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
		return "Grade is too low";
};

const std::string&	Bureaucrat::getName() {
	return(this->name);
}

int	Bureaucrat::getGrade() const {
	return(this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHeighException();
	grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}
std::ostream& operator<<(std::ostream& os, Bureaucrat& print)
{
	os << "name, " << print.getName() << " grade ";
	os << print.getGrade() << "." << std::endl;	
	return (os);
}

void Bureaucrat::signAForm(AForm &theAForm)
{
	if (theAForm.getGradeToSign() < this->grade && theAForm.getGradeToExecute() < this->grade)
	{
		std::cout << this->name << " couldnt sign " << theAForm.getAFormName() << " because of to low grade" << std::endl;
		throw GradeTooLowException();
	}
	else {
	theAForm.beSigned(*this);
	std::cout << this->name << " signed " << theAForm.getAFormName() << std::endl;;
	}
}


void Bureaucrat::executeAForm(AForm const & AForm)
{
	
		AForm.execute(*this); 	
		std::cout << this->name << " executed " << AForm.getAFormName() << std::endl;

	/* catch(const std::exception &e) {
		std::cout << this->name << " couldnt execute " << AForm.getAFormName() << " because " <<  e.what() << std::endl;
	} */
}
