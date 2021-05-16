#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(std::string const & name, int grade_to_sign, int grade_to_exec, std::string const & target) : _name(name), 
																				_signed(false),
																				_grade_to_sign(grade_to_sign),
																				_grade_to_exec(grade_to_exec),
																				_target(target)
{
	if (grade_to_sign > 150 || grade_to_exec > 150)
		throw (Form::GradeTooLowtExecption());
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw (Form::GradeTooHightExecption());	
}


Form::Form()
{
}

Form::Form( const Form & src ) : _name(src._name)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	_signed = rhs._signed;
	_grade_to_sign = rhs.getGradeToSign();
	_grade_to_exec = rhs.getGradeToExec();

	return *this;
}


std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form " << i.getName() << " need grade : " << std::endl;
	o << " - to sign : " << i.getGradeToSign() << std::endl;
	o << " - to exec : " << i.getGradeToExec() << std::endl;
	o << "Status is :";
	if (i.getSigned())
	{
		o << " signed" << std::endl;
	}
	else
	{
		o << " not signed" << std::endl;
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat &ref) 
{
	if (_grade_to_sign < ref.getGrade())
	{
		throw (Form::GradeTooLowtExecption());
	}
	else
	{
		_signed = true;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

bool Form::getSigned() const
{
	return _signed;
}

void Form::setSigned(bool state) 
{
	_signed = state;
}

std::string const& Form::getName() const
{
	return _name;
}

int Form::getGradeToSign() const
{
	return _grade_to_sign;
}

int Form::getGradeToExec() const
{
	return _grade_to_exec;
}

std::string const& Form::getTarget() const
{
	return _target;
}


/* ************************************************************************** */
