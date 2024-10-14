#include "RobotomyRequestForm.hpp"

// Orthodox AForm

RobotMyRequestAForm::RobotMyRequestAForm() :  AForm::AForm("RobotMyAForm", false, 72, 45),  target("random") {};

RobotMyRequestAForm::RobotMyRequestAForm(const RobotMyRequestAForm &other) : AForm::AForm("RobotMyAForm", false, 72, 45),  target(other.target)
{
	std::cout << "The copy constructor is called" << std::endl;
}
RobotMyRequestAForm& RobotMyRequestAForm::operator=(const RobotMyRequestAForm& other) {

    if (this != &other)
	{ 
        AForm::operator=(other);
        this->target = other.target;  
    }
	std::cout << "The copy assignment constructor is called" << std::endl;

    return (*this);
}

RobotMyRequestAForm::~RobotMyRequestAForm() {};

// Another member functions


RobotMyRequestAForm::RobotMyRequestAForm(std::string target) : AForm::AForm("RobotMyAForm", false, 72, 45),  target(target)
{
}

void	RobotMyRequestAForm::execute(Bureaucrat const & executor) const {

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