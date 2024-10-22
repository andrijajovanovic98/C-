#include "Span.hpp"

// Orthodox Form

Span::Span() : maxnumber(50) {};
Span::Span(const Span& other) : myList(other.myList), maxnumber(other.maxnumber) {};
Span& Span::operator=(const Span& other) {

	if (this != &other)
	{
		this->maxnumber = other.maxnumber;
		this->myList = other.myList;
	}
	return (*this);
}

Span::~Span() {};

// Member functions

Span::Span(unsigned int N) : maxnumber(N) {};

void Span::addNumber(int n) {
	if (myList.size() == maxnumber)
		throw std::string("Too much numbers in the cointainer");
	for (std::vector<int>::iterator it = myList.begin(); it != myList.end(); it++)
	{
		if (*it > n)
		{
			myList.insert(it, n);
			return;
		}
	}
	myList.push_back(n);

}

int Span::shortestSpan()
{
	int smallest = std::abs(myList[1] - myList[0]);
	if (myList.size() <  2)
		throw std::string("Less then 2 numbers");
	reverse(myList.begin(), myList.end());
	int last = *myList.begin();
	reverse(myList.begin(), myList.end());
	for (std::vector<int>::iterator it = myList.begin(); *it != last; it++)
	{
		if (std::abs(std::abs(*(it + 1)) - *it) < smallest)
			smallest = (*(it + 1)) - *it;
	}
	return (smallest);
}

long long int Span::longestSpan()
{
	if (myList.size() <  2)
		throw std::string("Less then 2 numbers");
	std::vector<int>::iterator lastElement = myList.end(); --lastElement;
	long long int biggest = static_cast<long long int>(*lastElement) - static_cast<long long int>(*myList.begin());
	return (biggest);
}

void Span::printOutTheValues() {

	for (std::vector<int>::iterator it = myList.begin(); it != myList.end(); it++)
		std::cout << *it << std::endl;
}

void Span::addRange(unsigned int numOfNum)
{
	srand(static_cast<unsigned int>(time(0)));
	if (numOfNum > maxnumber)
		throw std::string("Out of range!");
	for (unsigned int i = 0; i < numOfNum; i++)
	{
		int randomValue = rand() % 2147483647;
		if (rand() % 2 == 0)
			randomValue = -randomValue;
		this->addNumber(randomValue);
	}	

}