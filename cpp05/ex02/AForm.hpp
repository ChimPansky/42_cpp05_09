/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:21:59 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/22 10:22:00 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

class AForm {
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
	AForm();
	AForm(const std::string& name, int minSignGrade, int minExecGrade);
	AForm(const AForm& other);
	virtual ~AForm();

	AForm& operator=(const AForm& rHs);

	const std::string&	getName() const;
	bool				getSigned() const;
	int					getMinSignGrade() const;
	int					getMinExecGrade() const;

	void				beSigned(const Bureaucrat& signer);

	virtual void		execute(const Bureaucrat& executor) const;
	virtual void		action() const = 0;

	class GradeTooHighException : public std::exception {
	  public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	  public:
		const char* what() const throw();
	};

	class CannotExecuteLowException : public std::exception {
	  public:
		const char* what() const throw();
	};

	class CannotExecuteUnsignedException : public std::exception {
	  public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& lHs, const AForm& rHs);
