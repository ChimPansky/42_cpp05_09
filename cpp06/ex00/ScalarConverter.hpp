/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:23:31 by tkasbari          #+#    #+#             */
/*   Updated: 2024/06/22 13:47:05 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "utils.hpp"

#ifndef VERBOSE
	#define VERBOSE 1
	#if VERBOSE
	# define VERBOSE_OUT(msg) std::cout << msg << std::endl;
	#else
	# define VERBOSE_OUT(msg)
	#endif
#endif

class ScalarConverter {
  // make Constructors private, so that class is not instantiable...
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();

	ScalarConverter& operator=(const ScalarConverter& other);

  public:
	static void	convert(const std::string& str);
};
