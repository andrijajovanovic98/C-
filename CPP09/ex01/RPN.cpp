#include "RPN.hpp"

void whichOperator(std::stack<int>& numbers, std::string token)
{
	int b = numbers.top(); numbers.pop();
    int a = numbers.top(); numbers.pop();
	
	if (token == "+")
        numbers.push(a + b);
    else if (token == "-")
        numbers.push(a - b);
    else if (token == "*")
        numbers.push(a * b);
    else if (token == "/")
	{
    	if (b == 0)
            throw  std::string("Error: Division by zero.");
		if (a % b != 0)
			throw std::string(NOTINT);
        numbers.push(a / b);
    }
}

int RPN(int argc, char **argv)
{
	if (argc != 2)
        throw std::string(USAGE);

	std::string input = argv[1];  
    std::istringstream ss(input);  
    std::string token;             
    std::stack<int> numbers;       

    while (ss >> token) {
        if (isdigit(token[0]))
        {
            if (token.size() > 1)
                throw std::string("Single numbers are accepted. 0 - 9 !");
            numbers.push(atoi(token.c_str()));
        } 
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (numbers.size() < 2)
				throw std::string("Error: Not enough operands for the operation.");
			whichOperator(numbers, token);
        } 
        else
			throw std::string("Error: Invalid token.");
    }
    if (numbers.size() != 1)
        throw std::string("Error: Invalid RPN expression.");
    std::cout << "Result: " << numbers.top() << std::endl;
	return (0);
}
