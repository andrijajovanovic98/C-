#ifndef AForm_HPP
#define  AForm_HPP


#include "Bureaucrat.hpp"
#include <exception>

class Bureaucrat;

class AForm {
private:

	const std::string name;
	bool	isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:

	AForm();
	AForm(const AForm &other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	AForm(const std::string &name, bool isSigned, const int gradeToSign, const int gradetoExecute);
	void getter() {
		std::cout << name << isSigned << gradeToSign << gradeToExecute << std::endl;
	}

	std::string	getAFormName() const;
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class NotSignedexp : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
	
	void beSigned(Bureaucrat &person);
	int	getGradeToSign();
	int getGradeToExecute() const;
	std::string isSignOrNot() const;

	virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, AForm& print);


#endif