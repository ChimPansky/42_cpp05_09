#pragma once

#ifndef VERBOSE
	#define VERBOSE 0
	#if VERBOSE
	# define VERBOSE_OUT(msg) std::cout << msg << std::endl;
	# define VERBOSE_OUT_ARGS(msg, arg_list) \
		do { \
			std::cout << msg << "("; \
			arg_list; \
			std::cout << ")" << std::endl; \
		} while (0)
	#else
	# define VERBOSE_OUT(msg)
	# define VERBOSE_OUT_ARGS(msg, arg_list)
	#endif
#endif
