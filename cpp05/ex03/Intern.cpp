/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:22:44 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/22 10:22:45 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void) other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
	(void) other;
	return *this;
}

AForm*	Intern::newShrubberyForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::newRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::newPresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& formType, const std::string& target) {
	std::string	formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm*	(*formCreators[3])(const std::string&) = {
		&Intern::newShrubberyForm,
		&Intern::newRobotomyForm,
		&Intern::newPresidentialForm
	};
	int i;
	for (i = 0; i < 3; i++) {
		if (formNames[i] == formType)
			break ;
	}
	if (i > 2)
		throw InvalidFormException();
	AForm*	formPtr = formCreators[i](target);
	std::cout << "Intern creates " << *formPtr << std::endl;
	return (formPtr);
}

const char* Intern::InvalidFormException::what() const throw() {
	return "Intern exception: Form not found!";
}

// is this really thaaaat ugly???
// AForm* Intern::makeForm(const std::string& formType, const std::string& target) {
// 	AForm*	formPtr;
// 	if (formType == "shrubbery creation")
// 		formPtr = new ShrubberyCreationForm(target);
// 	else if (formType == "robotomy request")
// 		formPtr = new RobotomyRequestForm(target);
// 	else if (formType == "presidential pardon")
// 		formPtr = new PresidentialPardonForm(target);
// 	else
// 	 	formPtr = 0;
// 	if (formPtr == 0)
// 		throw InvalidFormException();
// 	std::cout << "Intern creates " << *formPtr << std::endl;
// 	return formPtr;
// }
