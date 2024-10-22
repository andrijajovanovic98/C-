#include "easyfind.hpp"

template <typename T>
void easyfind(T var, int num)
{
	
	typename T::iterator p = std::find(var.begin(), var.end(), num);
	if (p != var.end())
		std::cout << "We find the value" << std::endl;
	else
		throw std::string ("We didnt found the value");
}

int main(void)
{
	std::list<int> myList;
	for (int i = 0; i < 61; i++)
		myList.push_back(i);
	std::vector<int> secoundList;
	for (int i = 0; i < 150; i++)
		secoundList.push_back(i);
	
	try {
		easyfind(myList, 2);
	}
	catch (const std::string& e) {
		std::cout << e << std::endl;
	}
	try {
		easyfind(myList, -1);
	}
	catch (const std::string& e) {
		std::cout << e << std::endl;
	}

	std::cout << std::endl;
	try {
		easyfind(secoundList, 2);
	}
	catch (const std::string& e) {
		std::cout << e << std::endl;
	}

	try {
		easyfind(secoundList, 200);
	}
	catch (const std::string& e) {
		std::cout << e << std::endl;
	}
	return (0);
}