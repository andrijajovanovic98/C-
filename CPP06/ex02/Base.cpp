#include "Base.hpp"

Base::Base() {};
Base::Base(const Base &other) {
	(void)other;
}
Base& Base::operator=(const Base &other) {

	if (this != &other) {

	}
	return (*this);
}

Base::~Base() {};
