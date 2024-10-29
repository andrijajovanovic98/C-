#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
class sorting {
public:

	std::vector<int> vsort;
	std::deque<int> desort;
	std::vector<int> aa;
	std::vector<int> bb;
	int lastElement;
	bool oddOrAdd;
	void addVsort(int value){
		vsort.push_back(value);
	}
	void addDesort(int value){
		desort.push_back(value);
	}
};

void executingVector(sorting &obj);
void executingDeque(sorting &obj);
int	setUp(int argc, char **argv, sorting &obj);
std::vector<int> calculate_jacobsthal_sequence(int length);

template <typename Container>
typename Container::iterator binaryInsertPosition(Container& cont, int value) {
    typename Container::iterator left = cont.begin();
    typename Container::iterator right = cont.end();

    while (left < right) {
        typename Container::iterator mid = left + (right - left) / 2;

        if (*mid < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}


template <typename Container>
void prepareForFordJohnson(Container& cont, sorting &obj) {
    if (cont.size() % 2 != 0) {
        obj.lastElement = cont.back();
        cont.pop_back();
        obj.oddOrAdd = true;
    } else {
        obj.oddOrAdd = false;
    }
}


template <typename Container>
void create_pairsT(Container &vsort) {
    int n = vsort.size();

    int i = 0;
    while (i < n - 1) {
        if (vsort[i] > vsort[i + 1]) {
            typename Container::value_type temp = vsort[i];
            vsort[i] = vsort[i + 1];
            vsort[i + 1] = temp;
        }
        i += 2; 
    }
}

template <typename Container>
void sortByLargerValueTT(Container &desort) {
    int n = desort.size();
    if (n < 4) return;

    bool sorted = false;
    while (!sorted) {
        sorted = true;
        int i = 1;
        while (i < n - 1) {
            if (desort[i] > desort[i + 2]) {
                typename Container::value_type temp_left = desort[i - 1];
                typename Container::value_type temp_right = desort[i];
                desort[i - 1] = desort[i + 1];
                desort[i] = desort[i + 2];
                desort[i + 1] = temp_left;
                desort[i + 2] = temp_right;
                sorted = false;
            }
            i += 2;
        }
    }
}


template <typename Container>
void sortByLargerValueT(Container &desort) {
    int n = desort.size();
    if (n < 4) return;

    int i = 1;
    while (i < n - 1) {
        if (desort[i] > desort[i + 2]) {
            typename Container::value_type temp_left = desort[i - 1];
            typename Container::value_type temp_right = desort[i];
            desort[i - 1] = desort[i + 1];
            desort[i] = desort[i + 2];
            desort[i + 1] = temp_left;
            desort[i + 2] = temp_right;
            sortByLargerValueT(desort);
        }
        i += 2;
    }
}

template <typename Container1, typename Container2>
void fordJohnsonT(Container1 &vsort, Container2 &aa, Container2 &bb) {
    int g = 0;
    int gy = 0;
    int n = vsort.size();

    int i = 0;
    while (i < n - 1) {
        if (vsort[i] < vsort[i + 1]) {
            aa.push_back(vsort[i]);
            bb.push_back(vsort[i + 1]);
            gy++;
            g++;
        } else {
            bb.push_back(vsort[i]);
            aa.push_back(vsort[i + 1]);
            g++;
            gy++;
        }
        i += 2;
    }
}

template <typename Container1, typename Container2>
void johnsonMergeT(Container1 &vsort, const Container2 &aa, const Container2 &bb) {
    int g = 1;
    int gy = 0;
    int n = aa.size() + bb.size();

    vsort.clear();
    vsort.push_back(aa[0]);
    int i = 1;
    while (i < n) {
        if (g < static_cast<int>(aa.size()) && (gy >= static_cast<int>(bb.size()) || aa[g] < bb[gy])) {
            vsort.push_back(aa[g]);
            g++;
        } else if (gy < static_cast<int>(bb.size())) {
            vsort.push_back(bb[gy]);
            gy++;
        }
        i++;
    }
}

template <typename T>
void printVectorValues(T &obj)
{
	for (typename T::iterator it = obj.begin(); it != obj.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;	
}

template <typename T>
void sortInsert(T &a)
{
    typename T::size_type n = a.size();
    for (typename T::size_type i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            typename T::value_type temp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = temp;
            sortInsert(a);
        }
    }
}

template <typename Container>
void usingJacobsthalT(Container& con, sorting &obj) {
    con.clear();
    
    con.insert(con.end(), obj.bb.begin(), obj.bb.end());


    if (!obj.aa.empty()) {
        con.insert(con.begin(), obj.aa[0]);
    }

    std::vector<int> jacobsthal_sequence = calculate_jacobsthal_sequence(obj.aa.size() - 1);

    for (size_t i = 1; i < obj.aa.size() && i - 1 < jacobsthal_sequence.size(); ++i) {
        int position = jacobsthal_sequence[i - 1];
        if (static_cast<typename Container::size_type>(position) < con.size()) {
            con.insert(con.begin() + position, obj.aa[i]);
        } else {
            con.push_back(obj.aa[i]);
        }
    }
}

#endif