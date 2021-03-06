#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{

	public:

		ShrubberyCreationForm(std::string const &name);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		virtual ~ShrubberyCreationForm();
		

		virtual void execForm(Bureaucrat &ref) const;

	private:
		ShrubberyCreationForm();
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */