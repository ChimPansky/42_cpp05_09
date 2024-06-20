#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

std::ostream& operator<<(std::ostream& lHs, const Bureaucrat& rHs) {
	lHs << "Bureaucrat " << rHs.getName() << "(grade: " << rHs.getGrade() << ")";
	return (lHs);
}

int	Bureaucrat::_highestGrade = 1;
int	Bureaucrat::_lowestGrade = 150;
int	Bureaucrat::_defaultGrade = 130;

Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(_defaultGrade) {
		VERBOSE_OUT(*this << ": Default Constructor");
		_checkGrade(_grade);
		_allocateStuff();
	}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade) {
		VERBOSE_OUT(*this << ": Constructor(name, grade)");
		_checkGrade(_grade);
		_allocateStuff();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name) {
		VERBOSE_OUT(*this << ": Copy Constructor");
	_allocateStuff();
	*this->_allocatedData = *other._allocatedData;
	this->_grade = other._grade;
}

Bureaucrat::~Bureaucrat() {
	VERBOSE_OUT(*this << ": Destructor (freeing memory...)");
	delete _allocatedData;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	VERBOSE_OUT(*this << ": Copy Assignment operator overload");
	if (this != &other) {
		delete _allocatedData;
		_allocateStuff();
		*_allocatedData = *other._allocatedData;
		_grade = other._grade;
	}
	return *this;
}

void	Bureaucrat::_allocateStuff() {
	VERBOSE_OUT(*this << ": allocating memory...");
	_allocatedData = new char();
}
bool	Bureaucrat::_gradeTooHigh(int grade) const {
	return (grade < _highestGrade);
}

bool	Bureaucrat::_gradeTooLow(int grade) const {
	return (grade > _lowestGrade);
}

void	Bureaucrat::_checkGrade(int grade) const {
	if (_gradeTooHigh(grade))
		throw Bureaucrat::GradeTooHighException();
	if (_gradeTooLow(grade))
		throw Bureaucrat::GradeTooLowException();
}

const std::string&	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

char* Bureaucrat::getAllocatedData() const {
	return _allocatedData;
}

void	Bureaucrat::setAllocatedData(char c) {
	_allocatedData[0] = c;
}

void	Bureaucrat::incrementGrade() {
	_checkGrade(_grade - 1);
	VERBOSE_OUT(*this << ": incrementing grade...");
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	_checkGrade(_grade + 1);
	VERBOSE_OUT(*this << ": decrementing grade...");
	_grade++;
}

void	Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (const Form::GradeTooLowException& e) {
		std::cerr << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat exception: grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat exception: grade too low!";
}
