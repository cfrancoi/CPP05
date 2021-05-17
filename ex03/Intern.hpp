#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"


class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Form * makeForm(std::string const & name, std::string const & target);
		Intern &		operator=( Intern const & rhs );
	private:
		typedef struct	s_tab
		{
			std::string		name;
			Form			*(*fct)(std::string const &target);
		}				t_tab;

		t_tab 			_lst[3];

	/*	Form			*CreatePresidential(std::string const & target);
		Form			*CreateRobotomy(std::string const & target);
		Form			*CreateShrubbery(std::string const & target);*/


};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */