#pragma once
#include <string>

class Bureaucrat {
  private:
	const std::string _name;
	int	_grade;

  public:
	const std::string&	getName() const;
	int					getGrade() const;

	void				incrementGrade();
	void				decrementGrade();

};
