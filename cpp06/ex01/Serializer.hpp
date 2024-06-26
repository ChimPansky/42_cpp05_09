#pragma once

#include "Data.hpp"
#include <stdint.h>

class Serializer {
  private:
	Serializer();
	Serializer(const Serializer& other);
	~Serializer();
	Serializer& operator=(const Serializer& other);

  public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};
