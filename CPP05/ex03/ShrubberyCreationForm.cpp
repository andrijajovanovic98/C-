#include "ShrubberyCreationForm.hpp"

// Orthodox Form

ShrubberyCreationForm::	ShrubberyCreationForm() : Form::Form("ShrubberyForm", false, 145, 137),  target("random")  {};

ShrubberyCreationForm::	ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form::Form("ShrubberyForm", false, 145, 137),  target(other.target)
{
	std::cout << "The copy constructor is called" << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {

    if (this != &other)
	{ 
        Form::operator=(other);
        this->target = other.target;  
    }
	std::cout << "The copy assignment constructor is called" << std::endl;

    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

// Another member functions

ShrubberyCreationForm::	ShrubberyCreationForm(std::string target) : Form::Form("ShrubberyForm", false, 145, 137),  target(target)
{
		std::cout << this->getFormName() << " is created" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	
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
		std::cout << "The Form will be executed ... " << std::endl;
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