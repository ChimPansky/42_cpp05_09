/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:23:16 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/22 10:23:17 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::ostream& operator<<(std::ostream& lHs, const RobotomyRequestForm& rHs) {
	lHs << rHs.getName() << "(signed: " << (rHs.getSigned() ? "YES" : "NO")
		<< "; Sign req: " << rHs.getMinSignGrade() << "; Exec req: "
		<< rHs.getMinExecGrade() << "; target: " << rHs.getTarget() << ")";
	return (lHs);
}

const std::string	RobotomyRequestForm::_defName = "RobotomyRequest";
const int			RobotomyRequestForm::_defMinSignGrade = 72;
const int			RobotomyRequestForm::_defMinExecGrade = 45;
const std::string	RobotomyRequestForm::_defTarget = "Dummy";

RobotomyRequestForm::RobotomyRequestForm()
	: AForm(_defName, _defMinSignGrade, _defMinExecGrade), _target(_defTarget) {
		VERBOSE_OUT(*this << ": Default Constructor");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(_defName, _defMinSignGrade, _defMinExecGrade), _target(target) {
		VERBOSE_OUT(*this << ": Constructor(target)");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(_defName, _defMinSignGrade, _defMinExecGrade), _target(other._target) {
		VERBOSE_OUT(*this << ": Copy Constructor");
}

RobotomyRequestForm::~RobotomyRequestForm() {
	VERBOSE_OUT(*this << ": Destructor");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	VERBOSE_OUT(*this << ": Copy Assignment operator overload");
	(void)other;
	return *this;
}

const std::string&	RobotomyRequestForm::getTarget() const {
	return _target;
}

void	RobotomyRequestForm::action() const {
	std::cout << "DRRRRRILLLLLLZZZZZzzzz..." << std::endl;
	std::srand(time(0));
	if (rand() % 2 == 1)
		std::cout << _target << " has been robotomized!" << std::endl;
	else
		throw RobotomyRequestForm::ExecuteException();
}

const char*	RobotomyRequestForm::ExecuteException::what() const throw() {
	return "Robotomy exception: robotomy failed!";
}
