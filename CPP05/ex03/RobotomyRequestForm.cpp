#include "RobotomyRequestForm.hpp"

// Orthodox Form

RobotMyRequestForm::RobotMyRequestForm() :  Form::Form("RobotMyForm", false, 72, 45),  target("random") {};

RobotMyRequestForm::RobotMyRequestForm(const RobotMyRequestForm &other) : Form::Form("RobotMyForm", false, 72, 45),  target(other.target)
{
	std::cout << "The copy constructor is called" << std::endl;
}
RobotMyRequestForm& RobotMyRequestForm::operator=(const RobotMyRequestForm& other) {

    if (this != &other)
	{ 
        Form::operator=(other);
        this->target = other.target;  
    }
	std::cout << "The copy assignment constructor is called" << std::endl;

    return (*this);
}

RobotMyRequestForm::~RobotMyRequestForm() {};

// Another member functions


RobotMyRequestForm::RobotMyRequestForm(std::string target) : Form::Form("RobotMyForm", false, 72, 45),  target(target)
{
}

void	RobotMyRequestForm::execute(Bureaucrat const & executor) const {

	int randomnum;
	srand(time(0));

	if (isSignOrNot() == "is not signed")
		throw NotSignedexp();
	if (executor.getGrade() >  this->getGradeToExecute())
	{
		std::cout << "Sorry but " << "the bureaucrat" << " need to be minimum grade: " << this->getGradeToExecute() << std::endl;
		throw GradeTooLowException();
	}
	randomnum = rand();
	if (isSignOrNot() == "is signed" && executor.getGrade() < this->getGradeToExecute())
	{
		std::cout << "brppppppp something is happening" << std::endl;
		std::cout << this->target << " has been robotomized successfully  50% of the time" << std::endl;
	}
	if (randomnum % 2 == 0 && isSignOrNot() == "is signed")
		std::cout << "The robot is successfully created" << std::endl;
	else if (randomnum % 2 != 0 && isSignOrNot() == "is signed" && executor.getGrade() <  this->getGradeToExecute())
		std::cout << "The robot is failed" << std::endl;
}