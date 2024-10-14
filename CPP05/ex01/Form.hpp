#ifndef FORM_HPP
#define  FORM_HPP


#include "Bureaucrat.hpp"
#include <exception>

class Bureaucrat;

class Form {
private:

	const std::string name;
	bool	isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:

	Form();
	Form(const Form &other);
	Form& operator=(const Form& other);
	~Form();

	Form(const std::string &name, bool isSigned, const int gradeToSign, const int gradetoExecute);
	void getter() {
		std::cout << name << isSigned << gradeToSign << gradeToExecute << std::endl;
	}

	std::string	getFormName();
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	void beSigned(Bureaucrat &person);
	int	getGradeToSign();
	int getGradeToExecute();
	std::string isSignOrNot();
};

std::ostream& operator<<(std::ostream& os, Form& print);


#endif