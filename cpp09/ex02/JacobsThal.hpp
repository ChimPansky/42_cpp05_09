#pragma once
#include <utility>

// jacob[n] = jacob[n-2] * 2 + jacob[n-1]
namespace jacobsthal {
	static const std::size_t	COUNT = 33;
	static const std::size_t	SEQUENCE[COUNT] = {
	0,		  1,		  1, 		3, 		 5, 		11, 	   21,
	43, 	  85, 		 171, 	  	341, 	   683, 	  	1365, 	  2731,
	5461, 	  10923, 	 21845, 	43691, 	   87381, 		174763,   349525,
	699051,   1398101,   2796203,   5592405,   11184811, 	22369621, 44739243,
	89478485, 178956971, 357913941, 715827883, 1431655765};

	std::pair<std::size_t, std::size_t>	getBounds(std::size_t val);
}
