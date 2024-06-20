#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
	Bureaucrat	bob("Bob", 1);
	Bureaucrat	edd("Edd", 30);
	Bureaucrat	moe("Moe", 100);
	Bureaucrat	lou("Lou", 140);
	Bureaucrat	joe("Joe", 150);
	Intern	randomIntern;
	AForm*	randomForm = 0;

	std::cout << "\n---1---\n";
	randomForm = 0;
	try {
		randomForm = randomIntern.makeForm("wrong form type", "Ron Weasley");
		bob.signForm(*randomForm);
		bob.executeForm(*randomForm);
		delete randomForm;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		delete randomForm;
	}

	std::cout << "\n---2---\n";
	randomForm = 0;
	try {
		randomForm = randomIntern.makeForm("shrubbery creation", "home");
		joe.signForm(*randomForm);
		bob.executeForm(*randomForm);
		delete randomForm;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		delete randomForm;
	}

	std::cout << "\n---3---\n";
	randomForm = 0;
	try {
		randomForm = randomIntern.makeForm("sshrubbery creation", "home");
		lou.signForm(*randomForm);
		bob.executeForm(*randomForm);
		delete randomForm;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		delete randomForm;
	}

	std::cout << "\n---4---\n";
	randomForm = 0;
	try {
		randomForm = randomIntern.makeForm("shrubbery creation", "home");
		lou.signForm(*randomForm);
		bob.executeForm(*randomForm);
		delete randomForm;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		delete randomForm;
	}

	std::cout << "\n---5---\n";
	randomForm = 0;
	try {
		randomForm = randomIntern.makeForm("robotomy request", "Ron Weasley");
		lou.signForm(*randomForm);
		bob.executeForm(*randomForm);
		delete randomForm;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		delete randomForm;
	}

	std::cout << "\n---6---\n";
	randomForm = 0;
	try {
		randomForm = randomIntern.makeForm("robotomy request", "Ron Weasley");
		moe.signForm(*randomForm);
		lou.executeForm(*randomForm);
		delete randomForm;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		delete randomForm;
	}

	std::cout << "\n---7---\n";
	randomForm = 0;
	try {
		randomForm = randomIntern.makeForm("robotomy request", "Ron Weasley");
		edd.signForm(*randomForm);
		lou.executeForm(*randomForm);
		delete randomForm;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		delete randomForm;
	}

	std::cout << "\n---8---\n";
	randomForm = 0;
	try {
		randomForm = randomIntern.makeForm("robotomy request", "Ron Weasley");
		edd.signForm(*randomForm);
		edd.executeForm(*randomForm);
		delete randomForm;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		delete randomForm;
	}

	std::cout << "\n---9---\n";
	randomForm = 0;
	try {
		randomForm = randomIntern.makeForm("presidential pardon", "Donald Trump");
		edd.signForm(*randomForm);
		edd.executeForm(*randomForm);
		delete randomForm;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		delete randomForm;
	}

	std::cout << "\n---10---\n";
	randomForm = 0;
	try {
		randomForm = randomIntern.makeForm("presidential pardon", "Donald Trump");
		bob.signForm(*randomForm);
		bob.executeForm(*randomForm);
		delete randomForm;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		delete randomForm;
	}

	std::cout << std::endl;
	return 0;
}
