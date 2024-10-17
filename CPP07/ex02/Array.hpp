#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <execinfo.h>

template <typename T>
class Array {
private:

	T *brap;
	size_t array_size;

public:

	Array() : array_size(0) {
		this->brap = NULL;
	}

	Array(unsigned int n) : array_size(0) {
		this->array_size = n;
		this->brap = new T[n];
	}

	Array(const Array &other) {
		
		this->brap = new T[other.array_size];
		this->array_size = other.array_size;
		for (size_t i = 0; i < other.array_size; i++)
			this->brap[i] = other.brap[i];
	}

	Array& operator=(const Array &other) {
		if (this != &other) {

			delete [] this->brap;
			this->array_size = other.array_size;
			this->brap = new T[other.array_size];
			for (size_t i = 0; i < other.array_size; i++)
				this->brap[i] = other.brap[i];
		}
		return (*this);
	}

	T& operator[](size_t index)
	{
		if (index >= this->array_size)
			throw std::exception();
		return (brap[index]);
	}

	size_t size()
	{
		return (this->array_size);
	}
	
	~Array()
	{
		delete[] this->brap;
	}
};

//Header if we want to use the tpp file for functions (clearity)
//#include "Array.tpp" 

#endif