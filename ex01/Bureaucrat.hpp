#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Bureaucrat
{

	public:

		Bureaucrat(std::string const &name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		void					signForm(Form &form);

		int						getGrade(void) const;
		std::string const &		getName(void) const;
		void					incGrade(void);
		void					decGrade(void);

		class GradeTooHightExecption : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too Hight");
				}
		};
		class GradeTooLowtExecption : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too Low");
				}
		};

	private:
		Bureaucrat &		operator=( Bureaucrat const & rhs );
		Bureaucrat();
		std::string const	_name;
		int					_grade;
		

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );


#endif /* ****************************************************** BUREAUCRAT_H */