#include "Data.hpp"
#include "Serializer.hpp"

int main(void) {
	Data doom1;
	Data doom2("Doom", 10, true, 0.5, 10.0);

	Serializer serializer;
	std::cout << doom1 << std::endl;
	std::cout << doom2 << std::endl;
	uintptr_t raw1 = serializer.serialize(&doom1);
	uintptr_t raw2 = serializer.serialize(&doom2);
	std::cout << std::endl;

	Data* doom3 = serializer.deserialize(raw1);
	Data* doom4 = serializer.deserialize(raw2);
	std::cout << std::endl;
	
	std::cout << "-Deserialzed data address-" << std::endl;
	std::cout << doom3 << std::endl;
	std::cout << doom4 << std::endl;
	std::cout << std::endl;
	std::cout << *doom3 << std::endl;
	std::cout << *doom4 << std::endl;

}