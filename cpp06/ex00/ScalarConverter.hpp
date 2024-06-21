#pragma once
#include <string>

#ifndef VERBOSE
	#define VERBOSE 1
	#if VERBOSE
	# define VERBOSE_OUT(msg) std::cout << msg << std::endl;
	#else
	# define VERBOSE_OUT(msg)
	#endif
#endif

class ScalarConverter {
  public:
	static int	convert(const std::string& str);
	static bool	containsUnprintable(const std::string& str);

	class NonDisplayableException : public std::exception {
	  public:
		const char* what() const throw();
	};
};
