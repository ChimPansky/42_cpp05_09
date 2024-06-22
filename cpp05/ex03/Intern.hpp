/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:22:46 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/22 10:22:47 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
