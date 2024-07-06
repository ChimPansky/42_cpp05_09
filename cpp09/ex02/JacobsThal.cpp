#include "JacobsThal.hpp"

std::pair<std::size_t, std::size_t>	jacobsthal::getBounds(std::size_t val) {
	if (val < 2)
		return std::make_pair(1, 1);
	for (std::size_t i = 3; i < COUNT; i++) {
		if (val < SEQUENCE[i])
			return std::make_pair(SEQUENCE[i - 1], SEQUENCE[i]);
	}
	return std::make_pair(SEQUENCE[COUNT - 2], SEQUENCE[COUNT - 1]);
}
