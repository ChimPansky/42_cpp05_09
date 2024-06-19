#include "ShrubberyCreationForm.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& lHs, const ShrubberyCreationForm& rHs) {
	lHs << rHs.getName() << "(signed: " << (rHs.getSigned() ? "YES" : "NO")
		<< "; Sign req: " << rHs.getMinSignGrade() << "; Exec req: "
		<< rHs.getMinExecGrade() << "; target: " << rHs.getTarget() << ")";
	return (lHs);
}

const std::string	ShrubberyCreationForm::_defName = "Default ShrubForm";
const int			ShrubberyCreationForm::_defMinSignGrade = 145;
const int			ShrubberyCreationForm::_defMinExecGrade = 137;
const std::string	ShrubberyCreationForm::_defTarget = "home";

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(_defName, _defMinSignGrade, _defMinExecGrade), _target(_defTarget) {
		VERBOSE_OUT(*this << ": Default Constructor");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(_defName, _defMinSignGrade, _defMinExecGrade), _target(target) {
		VERBOSE_OUT(*this << ": Constructor(target)");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(_defName, _defMinSignGrade, _defMinExecGrade), _target(other._target) {
		VERBOSE_OUT(*this << ": Copy Constructor");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	VERBOSE_OUT(*this << ": Destructor");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	VERBOSE_OUT(*this << ": Copy Assignment operator overload");
	(void)other;
	return *this;
}

const std::string&	ShrubberyCreationForm::getTarget() const {
	return _target;
}

void	ShrubberyCreationForm::formAction() const {
	std::cout << "Shrubby Action is being executed..." << std::endl;
}
