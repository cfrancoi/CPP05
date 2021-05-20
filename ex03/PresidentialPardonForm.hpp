#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{

	public:

		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm( PresidentialPardonForm const & src );
		virtual ~PresidentialPardonForm();


		virtual void	execForm(Bureaucrat &ref) const;

		
	private:
		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );
		PresidentialPardonForm();
		

};

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */