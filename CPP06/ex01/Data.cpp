#include "Data.hpp"

void Data::setValue(int num)
{
	this->value = num;
}

int Data::getValue()
{
	return (this->value);
}

// Orthodox Form

Data::Data() {};
Data::Data(const Data &other) {
	(void)other;
}
Data& Data::operator=(const Data &other) {
	
	if (this != &other) {

	}
	return (*this);
}
Data::~Data() {};