/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:21:46 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/22 10:21:47 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& lHs, const Form& rHs) {
	lHs << "Form " << rHs.getName() << "(signed: " << (rHs.getSigned() ? "YES" : "NO")
		<< "; Sign req: " << rHs.getMinSignGrade() << "; Exec req: "
		<< rHs.getMinExecGrade() << ")";
	return (lHs);
}

int	Form::_highestGrade = 1;
int	Form::_lowestGrade = 150;

Form::Form()
	: _name("Default"), _signed(false), _minSignGrade(50), _minExecGrade(25) {
		VERBOSE_OUT(*this << ": Default Constructor");
		_checkGrade(_minSignGrade);
		_checkGrade(_minExecGrade);
	}

Form::Form(const std::string& name, int minSignGrade, int minExecGrade)
	: _name(name), _signed(false), _minSignGrade(minSignGrade), _minExecGrade(minExecGrade) {
		VERBOSE_OUT(*this << ": Constructor(name, minSign, minExec)");
		_checkGrade(_minSignGrade);
		_checkGrade(_minExecGrade);
}

Form::Form(const Form& other)
	: _name(other._name), _minSignGrade(other._minSignGrade), _minExecGrade(other._minExecGrade) {
		VERBOSE_OUT(*this << ": Copy Constructor");
	*this = other;
}

Form::~Form() {
	VERBOSE_OUT(*this << ": Destructor");
}

Form& Form::operator=(const Form& other) {
	VERBOSE_OUT(*this << ": Copy Assignment operator overload");
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

bool	Form::_gradeTooHigh(int grade) const {
	return (grade < _highestGrade);
}

bool	Form::_gradeTooLow(int grade) const {
	return (grade > _lowestGrade);
}

void	Form::_checkGrade(int grade) const {
	if (_gradeTooHigh(grade))
		throw Form::GradeTooHighException();
	if (_gradeTooLow(grade))
		throw Form::GradeTooLowException();
}

const std::string&	Form::getName() const {
	return _name;
}

bool		Form::getSigned() const {
	return _signed;
}

int			Form::getMinSignGrade() const {
	return _minSignGrade;
}

int			Form::getMinExecGrade() const {
	return _minExecGrade;
}

void		Form::beSigned(const Bureaucrat& signer) {
	if (signer.getGrade() > _minSignGrade)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form exception: grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form exception: grade too low!";
}
