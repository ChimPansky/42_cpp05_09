#include "Bureaucrat.hpp"
#include <ostream>

std::ostream& operator<<(std::ostream& lHs, const Bureaucrat& rHs) {
	lHs << rHs.getName();
	return (lHs);
}

Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(100) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name) {
	*this = other;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		_grade = other._grade;
	return *this;
}

const std::string&	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::incrementGrade() {
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	_grade++;
}
