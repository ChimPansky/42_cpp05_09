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

class AForm;

class Bureaucrat {
  private:
	const std::string 	_name;
	int					_grade;
	char				*_allocatedData;

	static int			_highestGrade;
	static int			_lowestGrade;
	static int			_defaultGrade;

	void				_allocateStuff();
	bool				_gradeTooHigh(int grade) const;
	bool				_gradeTooLow(int grade) const;
	void				_checkGrade(int grade) const;

  public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& rHs);

	const std::string&	getName() const;
	int					getGrade() const;

	char*				getAllocatedData() const;
	void				setAllocatedData(char c);

	void				incrementGrade();
	void				decrementGrade();

	void				signForm(AForm& form);
	void				executeForm(const AForm& form);

	class GradeTooHighException : public std::exception {
	  public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	  public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& lHs, const Bureaucrat& rHs);
