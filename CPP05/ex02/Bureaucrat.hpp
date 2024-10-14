#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdio.h>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

private:

	const std::string name;
	int grade;

public:

	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat(std::string name, int grade);

	class GradeTooHeighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	const std::string&	getName();
	int    getGrade() const;
	void	incrementGrade();
	void	decrementGrade();

	void signAForm(AForm &theAForm);

	void executeAForm(AForm const & AForm);

};

std::ostream& operator<<(std::ostream& os, Bureaucrat& print);

#endif
