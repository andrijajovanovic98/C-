#include "inter.hpp"

void plusfive(float &i)
{
	i += 5;
}
void multiplydecimal(double &i)
{
	i *= 0.2;
}


void multiplytwo(int &i)
{
	i *= 2;
}

void	rotchar(char &c)
{
	if (isalpha(c))
	{
		if (isupper(c))
		{
			if (c == 'Z')
				c = 'A';
			else
				c += 1;
		}
		else
		{
			if (c == 'z')
			{	
				c = 'a';
			}
			else
				c += 1;
		}
	}
}

void stringrot(std::string &string)
{
	for (size_t i = 0; i < string.length(); ++i)
		rotchar(string[i]);

}

int main(void)
{
	float armani[3] = {1.15, 2.25, 3.35};
	iter(armani, 3, ::plusfive);
	printarray(armani, 3);

	std::cout << std::endl;

	int integers[] = {1, 2, 3, 4, 5};
	iter(integers, 5, ::multiplytwo);
	printarray(integers, 5);

	std::cout << std::endl;

	double maraqja[4] = {4.15, 22.25, 34.35};
	iter(maraqja, 3, ::multiplydecimal);
	printarray(maraqja, 3);

	char array[6] = { 'H', 'e', 'l', 'l', 'o'};
	for (int i = 0; i < 6; i++)
		std::cout << array[i] << std::endl;;
	iter(array, 6, rotchar);
	 for (int i = 0; i < 6; i++)
		std::cout << array[i];
	std::cout << std::endl;
	std::string arraying[3] = {"Hello", "World", "Bye"};
	for(int i = 0; i < 3; i++)
		std::cout << arraying[i] << std::endl;
	iter(arraying, 3, stringrot);
	for(int i = 0; i < 3; i++)
		std::cout << arraying[i] << std::endl;
	
	return (0);
}