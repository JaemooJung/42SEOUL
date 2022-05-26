#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	std::cout << "Serializing data [" << ptr->getDoomName() << "]" << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	std::cout << "Deserializing data" << std::endl;
	return reinterpret_cast<Data*>(raw);
}

Serializer& Serializer::operator=(const Serializer&) {
	return *this;
}

Serializer::Serializer() {
	
}

Serializer::Serializer(const Serializer&) {
	
}

Serializer::~Serializer() {
	
}
