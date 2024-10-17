#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data data;

	data.setValue(42);

	std::cout << "The value of Value is: " << data.getValue() << std::endl; 

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized pointer is: " << raw << std::endl;

	Data * deserializedData = Serializer::deserialize(raw);
	std::cout << "The pointer is " << deserializedData << std::endl;

	std::cout << "Deserialized value: " << deserializedData->getValue() << std::endl;

	return (0);
}
