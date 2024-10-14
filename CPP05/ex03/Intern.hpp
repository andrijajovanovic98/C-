#ifndef INTERN_HPP
#define INTERN_HPP
#include "Form.hpp"

class Intern {
private:


public:

	Intern();
	Intern(const Intern &other);
	Intern& operator=(const Intern &other);
	~Intern();

	Form* makeForm(const std::string &name, const std::string &target);

};

#endif