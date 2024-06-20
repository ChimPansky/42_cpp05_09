#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& lHs, const AForm& rHs) {
	lHs << "Form " <<  rHs.getName() << " (signed: " << (rHs.getSigned() ? "YES" : "NO")
		<< "; Sign req: " << rHs.getMinSignGrade() << "; Exec req: "
		<< rHs.getMinExecGrade() << ")";
	return (lHs);
}

int	AForm::_highestGrade = 1;
int	AForm::_lowestGrade = 150;

AForm::AForm()
	: _name("Default"), _signed(false), _minSignGrade(50), _minExecGrade(25) {
		VERBOSE_OUT(*this << ": Default Constructor");
		_checkGrade(_minSignGrade);
		_checkGrade(_minExecGrade);
	}

AForm::AForm(const std::string& name, int minSignGrade, int minExecGrade)
	: _name(name), _signed(false), _minSignGrade(minSignGrade), _minExecGrade(minExecGrade) {
		VERBOSE_OUT(*this << ": Constructor(name, minSign, minExec)");
		_checkGrade(_minSignGrade);
		_checkGrade(_minExecGrade);
}

AForm::AForm(const AForm& other)
	: _name(other._name), _minSignGrade(other._minSignGrade), _minExecGrade(other._minExecGrade) {
		VERBOSE_OUT(*this << ": Copy Constructor");
	*this = other;
}

AForm::~AForm() {
	VERBOSE_OUT(*this << ": Destructor");
}

AForm& AForm::operator=(const AForm& other) {
	VERBOSE_OUT(*this << ": Copy Assignment operator overload");
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

bool	AForm::_gradeTooHigh(int grade) const {
	return (grade < _highestGrade);
}

bool	AForm::_gradeTooLow(int grade) const {
	return (grade > _lowestGrade);
}

void	AForm::_checkGrade(int grade) const {
	if (_gradeTooHigh(grade))
		throw AForm::GradeTooHighException();
	if (_gradeTooLow(grade))
		throw AForm::GradeTooLowException();
}

const std::string&	AForm::getName() const {
	return _name;
}

bool		AForm::getSigned() const {
	return _signed;
}

int			AForm::getMinSignGrade() const {
	return _minSignGrade;
}

int			AForm::getMinExecGrade() const {
	return _minExecGrade;
}

void		AForm::beSigned(const Bureaucrat& signer) {
	if (signer.getGrade() > _minSignGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void		AForm::execute(const Bureaucrat& executor) const {
	if (!_signed)
		throw AForm::CannotExecuteUnsignedException();
	if (executor.getGrade() > _minExecGrade)
		throw AForm::CannotExecuteLowException();
	action();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm exception: grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm exception: grade too low!";
}

const char* AForm::CannotExecuteLowException::what() const throw() {
	return "AForm exception: cannot execute (grade too low)!";
}

const char* AForm::CannotExecuteUnsignedException::what() const throw() {
	return "AForm exception: cannot execute (form not signed)!";
}
