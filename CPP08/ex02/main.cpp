#include "MutantStack.hpp"

void printTheStack(std::stack<int> stack)
{
	while (!stack.empty())
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}
}

int main(void)
{
	MutantStack<int> myStack;

	myStack.push(5);
	myStack.push(2);
	myStack.push(15);
	myStack.push(18);

	std::cout << "Lets iterat through the stack: " << std::endl;

	MutantStack<int>::iterator it = myStack.begin();
	it++;
	it++;
	for (; it != myStack.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "Lets try reverse iterating" << std::endl;

	for (MutantStack<int>::reverse_iterator rit = myStack.rbegin(); rit != myStack.rend(); rit ++)
		std::cout << *rit << std::endl;
	
	std::cout << std::endl;
	printTheStack(myStack);
	return (0);
}


/* int main()
{
	MutantStack<int> myStack;
	myStack.push(5);
	myStack.push(17);
	std::cout << myStack.top() << std::endl;
	myStack.pop();
	std::cout << myStack.size() << std::endl;
	myStack.push(3);
	myStack.push(5);
	myStack.push(737);
	//[...]
	myStack.push(0);
	MutantStack<int>::iterator it = myStack.begin();
	MutantStack<int>::iterator ite = myStack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(myStack);

	std::cout << std::endl << std::endl;

	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator lit = mstack.begin();
	std::list<int>::iterator lite = mstack.end();
	++it;
	--it;
	while (lit != lite)
	{
	std::cout << *lit << std::endl;
	++lit;
	}
	std::list<int> ss(mstack);
} */
