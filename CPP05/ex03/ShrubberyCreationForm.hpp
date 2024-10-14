#ifndef SHRUBBERYCREATIONForm_HPP
# define SHRUBBERYCREATIONForm_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


class ShrubberyCreationForm : public Form {
private:

	std::string target;

public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	
	ShrubberyCreationForm(std::string target);
	void	execute(Bureaucrat const & executor) const;
};

#endif