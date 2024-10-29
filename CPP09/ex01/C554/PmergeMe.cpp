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
	return (0);

}

void executingVector(sorting &obj)
{
	clock_t startVector = clock();
	prepareForFordJohnson(obj.vsort, obj);
	create_pairsT(obj.vsort);
	sortByLargerValueT(obj.vsort);
	fordJohnsonT(obj.vsort, obj.aa, obj.bb);;
	sortInsert(obj.aa);
	sortInsert(obj.bb);
	johnsonMergeT(obj.vsort, obj.aa, obj.bb);
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
	fordJohnsonT(obj.desort, obj.aa, obj.bb);;
	sortInsert(obj.aa);
	sortInsert(obj.bb);
	johnsonMergeT(obj.desort, obj.aa, obj.bb);
    if (obj.oddOrAdd == true)
	{
		std::deque<int>::iterator posDeque = binaryInsertPosition(obj.desort, obj.lastElement);
		obj.desort.insert(posDeque, obj.lastElement);
		obj.oddOrAdd = false;
	}
	
	std::cout << "Deque: ";
	printVectorValues(obj.desort);
    clock_t endDeque = clock();
    double durationDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC;
    std::cout << "Time for std::deque: " << durationDeque << " seconds" << std::endl;
 }