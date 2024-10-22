#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


class Span {
private:

	std::vector<int> myList;
	unsigned int maxnumber;

public:

	Span();
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	Span(unsigned int N);
	int shortestSpan();
	long long int longestSpan();
	void addNumber(int n);

	void printOutTheValues();
	void addRange(unsigned int numOfNum);

};


#endif