#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

std::ostream& operator<<(std::ostream& lHs, const ShrubberyCreationForm& rHs) {
	lHs << rHs.getName() << "(signed: " << (rHs.getSigned() ? "YES" : "NO")
		<< "; Sign req: " << rHs.getMinSignGrade() << "; Exec req: "
		<< rHs.getMinExecGrade() << "; target: " << rHs.getTarget() << ")";
	return (lHs);
}

const std::string	ShrubberyCreationForm::_defName = "ShrubForm";
const int			ShrubberyCreationForm::_defMinSignGrade = 145;
const int			ShrubberyCreationForm::_defMinExecGrade = 137;
const std::string	ShrubberyCreationForm::_defTarget = "Dummy";
const std::string	ShrubberyCreationForm::_asciiTree = "\n"
"   /\\ \n"
"  /  \\ \n"
" /    \\ \n"
"/______\\ \n"
"  |||| \n"
"  |||| \n";


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

void	ShrubberyCreationForm::action() const {
	std::string	fName = _target + "_shrubbery";
	std::ofstream	outFile(fName.c_str(), std::ofstream::app);
	if (!outFile)
		throw ShrubberyCreationForm::ExecuteException();
	outFile << _asciiTree;
	outFile.close();
}

const char*	ShrubberyCreationForm::ExecuteException::what() const throw() {
	return "Shrubbery exception: error while executing!";
}
