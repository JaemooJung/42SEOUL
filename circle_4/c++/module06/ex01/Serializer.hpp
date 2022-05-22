#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include "Data.hpp"
#include <cstdint>

class Serializer {
	public:
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif // __SERIALIZER_H__