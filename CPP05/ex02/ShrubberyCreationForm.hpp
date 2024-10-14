#ifndef SHRUBBERYCREATIONAForm_HPP
# define SHRUBBERYCREATIONAForm_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>


class ShrubberyCreationAForm : public AForm {
private:

	std::string target;

public:

	ShrubberyCreationAForm();
	ShrubberyCreationAForm(const ShrubberyCreationAForm& other);
	ShrubberyCreationAForm& operator=(const ShrubberyCreationAForm& other);
	~ShrubberyCreationAForm();
	

	ShrubberyCreationAForm(std::string target);
	void	execute(Bureaucrat const & executor) const;
};

#endif