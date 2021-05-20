#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{

	public:
		RobotomyRequestForm(std::string const & name);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		virtual ~RobotomyRequestForm();

		virtual void execForm(Bureaucrat &ref) const;

	private:
		RobotomyRequestForm();
		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */