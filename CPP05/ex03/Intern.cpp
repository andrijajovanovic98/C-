#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Orthodox Form

Intern::Intern() {};

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern& Intern::operator=(const Intern &other) {
	if (this != &other) {

	}
	return (*this);
};

Intern::~Intern() {};

// Another member functions

Form* Intern::makeForm(const std::string &name, const std::string &target)
{
	 std::string formTypes[3] = {"ShrubberyCreationForm", "RobotMRequestForm", "PresidentialPardonForm"};

     for (int i = 0; i < 3; i++) {
        if (formTypes[i] == name) {
            std::cout << "Intern creates " << name << std::endl;
            switch (i) {
                case 0:
                    return new ShrubberyCreationForm(target); 
                case 1:
                    return new RobotMyRequestForm(target);
                case 2:
                    return new PresidentialPardonForm(target);
            }
        }
    }
    return (NULL);
}