#pragma once
#include <string>

class Bureaucrat {
  private:
	const std::string _name;
	int	_grade;

  public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat operator=(const Bureaucrat& rHs);

	const std::string&	getName() const;
	int					getGrade() const;

	void				incrementGrade();
	void				decrementGrade();
};

std::ostream& operator<<(std::ostream& lHs, const Bureaucrat& rHs);
