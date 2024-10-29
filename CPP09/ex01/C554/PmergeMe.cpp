#include "PmergeMe.hpp"

int	setUp(int argc, char **argv, sorting &obj)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Two arguments required." << std::endl;
		return (1);
	}
	std::string input = argv[1];  
    std::istringstream ss(input);
	int number;

	while (ss >> number) {
		obj.addVsort(number);
		obj.addDesort(number);
	}
	if (obj.vsort.size() < 2)
	{
		std::cerr << "Minimum 2 numbers required." << std::endl;
		return (1);
	}
	return (0);

}

std::vector<int> calculate_jacobsthal_sequence(int length) {
    std::vector<int> jacobsthal;
    if (length > 0) jacobsthal.push_back(1);
    if (length > 1) jacobsthal.push_back(3);
    
    int i = 2;
	int lastNum = 3;
    while (jacobsthal.size() < static_cast<std::vector<int>::size_type>(length)) {
        int next_jacobsthal = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		if (next_jacobsthal > 200)
			next_jacobsthal = lastNum + 1;
		jacobsthal.push_back(next_jacobsthal);
        ++i;
        lastNum = next_jacobsthal;
    }
    return jacobsthal;
}

void executingVector(sorting &obj)
{
	clock_t startVector = clock();
	prepareForFordJohnson(obj.vsort, obj);
	create_pairsT(obj.vsort);
	sortByLargerValueT(obj.vsort);
	fordJohnsonT(obj.vsort, obj.aa, obj.bb);;
	usingJacobsthalT(obj.vsort, obj);
	sortInsert(obj.vsort);

    clock_t endVector = clock();
	obj.aa.clear();
	obj.bb.clear();
	if (obj.oddOrAdd == true)
	{
		std::vector<int>::iterator pos = binaryInsertPosition(obj.vsort, obj.lastElement);
		obj.vsort.insert(pos, obj.lastElement);
		obj.oddOrAdd = false;
	}
	double durationVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC;
	std::cout << "Vector: ";
	printVectorValues(obj.vsort);
	  std::cout << "Time for std::vector: " 
              << durationVector << " seconds" << std::endl;
	std::cout << std::endl;
}


void executingDeque(sorting &obj)
 {
	clock_t startDeque = clock();
	prepareForFordJohnson(obj.desort, obj);
	
	create_pairsT(obj.desort);
	sortByLargerValueT(obj.desort);
	fordJohnsonT(obj.desort, obj.aa, obj.bb);
	usingJacobsthalT(obj.desort, obj);
	sortInsert(obj.desort);
    clock_t endDeque = clock();
    if (obj.oddOrAdd == true)
	{
		std::deque<int>::iterator posDeque = binaryInsertPosition(obj.desort, obj.lastElement);
		obj.desort.insert(posDeque, obj.lastElement);
		obj.oddOrAdd = false;
	}
	std::cout << "Deque: ";
	printVectorValues(obj.desort);
    double durationDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC;
    std::cout << "Time for std::deque: " << durationDeque << " seconds" << std::endl;
 }