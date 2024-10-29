#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	sorting obj;

	if (setUp(argc,argv,obj) == 1)
		return (1);

	// Vector
	executingVector(obj);

	std::cout << std::endl;
	
	// Deque
	executingDeque(obj);
	return (0);

}