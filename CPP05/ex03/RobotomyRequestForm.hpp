#ifndef ROBOTMYREQUESTForm_HPP
#define ROBOTMYREQUESTForm_HPP

#include "Form.hpp"
#include <cstdlib>
#include <ctime>

class RobotMyRequestForm : public Form {
private:

	std::string target;

public :

	RobotMyRequestForm();
	RobotMyRequestForm(const RobotMyRequestForm &othe);
	RobotMyRequestForm& operator=(const RobotMyRequestForm& other);
	~RobotMyRequestForm();

	RobotMyRequestForm(std::string target);
	void	execute(Bureaucrat const & executor) const;

};

#endif