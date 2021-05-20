#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &name) : Form("Shrubbery creation", 145, 137, name)
{
}


ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : Form(src.getName(), src.getGradeToSign(), src.getGradeToExec(), src.getTarget())
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	setSigned(rhs.getSigned());
	setGradeToSign(rhs.getGradeToSign());
	setGradeToExec(rhs.getGradeToExec());
	setTarget(rhs.getTarget());
	return *this;
}


std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
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


void ShrubberyCreationForm::execForm(Bureaucrat &ref) const
{
	if (getSigned() == false)
	{
		throw(Form::FormNotSigned());
	}
	if (getGradeToExec() < ref.getGrade())
	{
		throw(Form::GradeTooLowtExecption());
	}
	std::string file;

	file = getTarget() + "_shrubbery";

	std::ofstream ofs(file.c_str());

	ofs << "         *         " << std::endl;
	ofs << "       	 T         " << std::endl;
	ofs << "        $$@        " << std::endl;
	ofs << "       $$$@b       " << std::endl;
	ofs << "     d@$$$$@$b     " << std::endl;
 	ofs << "  .d$$i$$$@$$$$b.  " << std::endl;
	ofs << "     d@$$$$@$b     " << std::endl;
	ofs << "  .d$$i$$$@$$$$b.  " << std::endl;
	ofs << ".d$$$$i$$$@$$$$$$b." << std::endl;
	ofs << "        ###        " << std::endl;
	ofs << "        ###        " << std::endl;
	ofs << "        ###        " << std::endl;
	ofs.close();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

