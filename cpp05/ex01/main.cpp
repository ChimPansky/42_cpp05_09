/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:21:52 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/22 10:21:53 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	//try {
		Bureaucrat	bob("Bob", 1);
		Bureaucrat	edd("Edd", 30);
		Form		form1("Form 1", 100 , 10);
		Form		form2("Form 2", 25, 10);
		Form		form3("Form 3", 50, 25);

		std::cout << "Hi, i am " << bob << std::endl;
		std::cout << "Hi, i am " << edd << "\n" << std::endl;
		std::cout << "There's a form: " << form1 << std::endl;
		std::cout << "There's a form: " << form2 << std::endl;
		std::cout << "There's a form: " << form3 << std::endl;

		edd.signForm(form2);
		bob.signForm(form2);
		edd.signForm(form3);
	// }
	// catch (const std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// catch (...) {
	// 	std::cout << "Caught unknown exception!" << std::endl;
	// }

	// std::cout << "---\n";

	// try {
	// 	Bureaucrat	bob("Bob", 101);
	// 	Form		form1("Form 1", 100 , 10);

	// 	std::cout << "Hi, i am " << bob << std::endl;
	// 	std::cout << "There's a form: " << form1 << std::endl;
	// 	form1.beSigned(bob);
	// }
	// catch (const std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// catch (...) {
	// 	std::cout << "Caught unknown exception!" << std::endl;
	// }

}
