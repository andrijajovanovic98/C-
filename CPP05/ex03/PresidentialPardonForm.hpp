#ifndef PRESIDENTIALPARDONForm_HPP
#define PRESIDENTIALPARDONForm_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
private:

	std::string target;

public:

	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	PresidentialPardonForm(std::string target);
	void	execute(Bureaucrat const & executor) const;

};

#endif