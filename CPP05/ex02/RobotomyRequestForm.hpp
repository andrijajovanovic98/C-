#ifndef ROBOTMYREQUESTAForm_HPP
#define ROBOTMYREQUESTAForm_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotMyRequestAForm : public AForm {
private:

	std::string target;

public :

	RobotMyRequestAForm();
	RobotMyRequestAForm(const RobotMyRequestAForm &othe);
	RobotMyRequestAForm& operator=(const RobotMyRequestAForm& other);
	~RobotMyRequestAForm();

	RobotMyRequestAForm(std::string target);
	void	execute(Bureaucrat const & executor) const;

};

#endif