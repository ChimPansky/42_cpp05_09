#pragma once
#include <string>

#ifndef VERBOSE
	#define VERBOSE 0
	#if VERBOSE
	# define VERBOSE_OUT(msg) std::cout << msg << std::endl;
	#else
	# define VERBOSE_OUT(msg)
	#endif
#endif

class Bureaucrat;

class Form {
  private:
	const std::string 	_name;
	bool				_signed;
	const int			_minSignGrade;
	const int			_minExecGrade;

	static int			_highestGrade;
	static int			_lowestGrade;

	bool				_gradeTooHigh(int grade) const;
	bool				_gradeTooLow(int grade) const;
	void				_checkGrade(int grade) const;

  public:
	Form();
	Form(const std::string& name, int minSignGrade, int minExecGrade);
	Form(const Form& other);
	~Form();

	Form& operator=(const Form& rHs);

	const std::string&	getName() const;
	bool				getSigned() const;
	int					getMinSignGrade() const;
	int					getMinExecGrade() const;

	void				beSigned(const Bureaucrat& signer);

	class GradeTooHighException : public std::exception {
	  public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	  public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& lHs, const Form& rHs);
