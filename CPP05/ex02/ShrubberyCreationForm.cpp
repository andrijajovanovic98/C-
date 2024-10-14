#include "ShrubberyCreationForm.hpp"

// Orthodox AForm

ShrubberyCreationAForm::	ShrubberyCreationAForm() : AForm::AForm("ShrubberyAForm", false, 145, 137),  target("random")  {};

ShrubberyCreationAForm::	ShrubberyCreationAForm(const ShrubberyCreationAForm& other) : AForm::AForm("ShrubberyAForm", false, 145, 137),  target(other.target)
{
	std::cout << "The copy constructor is called" << std::endl;
}
ShrubberyCreationAForm& ShrubberyCreationAForm::operator=(const ShrubberyCreationAForm& other) {

    if (this != &other)
	{ 
        AForm::operator=(other);
        this->target = other.target;  
    }
	std::cout << "The copy assignment constructor is called" << std::endl;

    return (*this);
}

ShrubberyCreationAForm::~ShrubberyCreationAForm() {};

// Another member functions

ShrubberyCreationAForm::	ShrubberyCreationAForm(std::string target) : AForm::AForm("ShrubberyAForm", false, 145, 137),  target(target)
{
		std::cout << this->getAFormName() << " is created" << std::endl;
}

void	ShrubberyCreationAForm::execute(Bureaucrat const & executor) const {
	
	if (isSignOrNot() == "is not signed")
		throw NotSignedexp();
	if (executor.getGrade() >  this->getGradeToExecute())
	{
		std::cout << "Sorry but " << "the bureaucrat" << " need to be grade: " << this->getGradeToExecute() << std::endl;
		throw GradeTooLowException();
	}
	if (executor.getGrade() < getGradeToExecute() && isSignOrNot() == "is signed")
	{
		std::string filename = this->target + "_shrubbery";
		std::cout << "The AForm will be executed ... " << std::endl;
		std::ofstream outfile(filename.c_str());

		if (outfile.is_open()) {
			outfile << "       ###\n";
        	outfile << "      #o###\n";
        	outfile << "    #####o###\n";
        	outfile << "   #o#\\#|#/###\n";
        	outfile << "    ###\\|/#o#\n";
        	outfile << "     # }|{  #\n";
        	outfile << "       }|{\n";
			outfile.close();
		}
		else
			std::cerr << "Error: Could not create file!" << std::endl;
	}
}