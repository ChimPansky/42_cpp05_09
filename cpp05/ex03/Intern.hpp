#pragma once
#include <string>

class AForm;

class Intern {
  private:


  public:
	Intern();
	Intern(const Intern& other);
	~Intern();
	Intern& operator=(const Intern& other);

	AForm*	makeForm(const std::string& formType, const std::string& target);

	static AForm*	newShrubberyForm(const std::string& target);
	static AForm*	newRobotomyForm(const std::string& target);
	static AForm*	newPresidentialForm(const std::string& target);

	class InvalidFormException : public std::exception {
	  public:
		const char* what() const throw();
	};
};
