/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:23:10 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/22 10:23:11 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

std::ostream& operator<<(std::ostream& lHs, const PresidentialPardonForm& rHs) {
	lHs << rHs.getName() << "(signed: " << (rHs.getSigned() ? "YES" : "NO")
		<< "; Sign req: " << rHs.getMinSignGrade() << "; Exec req: "
		<< rHs.getMinExecGrade() << "; target: " << rHs.getTarget() << ")";
	return (lHs);
}

const std::string	PresidentialPardonForm::_defName = "PresidentialPardon";
const int			PresidentialPardonForm::_defMinSignGrade = 25;
const int			PresidentialPardonForm::_defMinExecGrade = 5;
const std::string	PresidentialPardonForm::_defTarget = "Dummy";

PresidentialPardonForm::PresidentialPardonForm()
	: AForm(_defName, _defMinSignGrade, _defMinExecGrade), _target(_defTarget) {
		VERBOSE_OUT(*this << ": Default Constructor");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(_defName, _defMinSignGrade, _defMinExecGrade), _target(target) {
		VERBOSE_OUT(*this << ": Constructor(target)");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(_defName, _defMinSignGrade, _defMinExecGrade), _target(other._target) {
		VERBOSE_OUT(*this << ": Copy Constructor");
}

PresidentialPardonForm::~PresidentialPardonForm() {
	VERBOSE_OUT(*this << ": Destructor");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	VERBOSE_OUT(*this << ": Copy Assignment operator overload");
	(void)other;
	return *this;
}

const std::string&	PresidentialPardonForm::getTarget() const {
	return _target;
}

void	PresidentialPardonForm::action() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
