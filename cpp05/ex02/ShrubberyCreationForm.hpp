#pragma once
#include "AForm.hpp"
#include <string>

#ifndef VERBOSE
	#define VERBOSE 0
	#if VERBOSE
	# define VERBOSE_OUT(msg) std::cout << msg << std::endl;
	#else
	# define VERBOSE_OUT(msg)
	#endif
#endif

class AForm;

class ShrubberyCreationForm : public AForm {
  private:
	const std::string	_target;

	static const std::string	_defName;
	static const int			_defMinSignGrade;
	static const int			_defMinExecGrade;
	static const std::string	_defTarget;

  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rHs);

	const std::string&	getTarget() const;
	void				formAction() const;
};

std::ostream& operator<<(std::ostream& lHs, const ShrubberyCreationForm& rHs);
