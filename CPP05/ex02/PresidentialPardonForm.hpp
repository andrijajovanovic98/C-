#ifndef PRESIDENTIALPARDONAForm_HPP
#define PRESIDENTIALPARDONAForm_HPP

#include "AForm.hpp"

class PresidentialPardonAForm : public AForm {
private:

	std::string target;

public:

	PresidentialPardonAForm();
	PresidentialPardonAForm(const PresidentialPardonAForm &other);
	PresidentialPardonAForm& operator=(const PresidentialPardonAForm& other);
	~PresidentialPardonAForm();

	PresidentialPardonAForm(std::string target);
	void	execute(Bureaucrat const & executor) const;

};

#endif