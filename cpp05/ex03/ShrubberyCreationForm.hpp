/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:23:24 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/22 10:23:25 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	static const std::string	_asciiTree;

  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rHs);

	const std::string&	getTarget() const;
	void				action() const;

	class ExecuteException : public std::exception {
	  public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& lHs, const ShrubberyCreationForm& rHs);
