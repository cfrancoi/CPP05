#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;


class Form
{

	public:
		Form();
		Form(std::string const & name, int grade_to_sign, int grade_to_exec, std::string const & target);
		Form( Form const & src );
		virtual ~Form();

		
		void			beSigned(Bureaucrat &ref);
		virtual void	execForm(Bureaucrat &ref) const = 0;

		bool					getSigned() const;
		void					setSigned(bool state);
		std::string	const &		getName() const;
		int						getGradeToSign() const;
		int						getGradeToExec() const;
		std::string	const &		getTarget() const;

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
		class FormNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form is not signed");
				}
		};
	private:
		
		Form &		operator=( Form const & rhs );

		std::string const	_name;
		bool				_signed;
		int					_grade_to_sign;
		int					_grade_to_exec;
		std::string			_target;


};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */