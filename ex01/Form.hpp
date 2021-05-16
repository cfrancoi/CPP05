#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;


class Form
{

	public:

		Form(std::string const & name, int grade_to_sign, int grade_to_exec);
		Form( Form const & src );
		~Form();

		
		void			beSigned(Bureaucrat &ref);

		bool					getSigned() const;
		std::string	const &		getName() const;
		int						getGradeToSign() const;
		int						getGradeToExec() const;

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
		Form();

		Form &		operator=( Form const & rhs );

		std::string const	_name;
		bool				_signed;
		int					_grade_to_sign;
		int					_grade_to_exec;


};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */