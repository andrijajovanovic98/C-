#ifndef INTER_HPP
#define INTER_HPP

#include <iostream>


template <typename T>
void printarray(T *array, size_t size)
{

	size_t i = 0;
	std::cout << "the value of size is " << size << std::endl;
	while (i < size)
	{
		std::cout << *array++ << std::endl;
		i++;
	}
}


template <typename T, typename F>
void iter(T *array, size_t size, F randomfunction)
{

	size_t i = 0;
	while (i < size )
	{
		randomfunction(array[i]);
		i++;
	}
}


#endif