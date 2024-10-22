#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>



template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;


	// Orthodox FORM

	MutantStack() : std::stack<T, Container>() {};
	MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {
        std::cout << "Copy constructor called" << std::endl;
    }

    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) { 
            std::stack<T, Container>::operator=(other);
        }
        std::cout << "Copy assignment operator called" << std::endl;
        return (*this);
    }
	~MutantStack() {};

	// Iterators

	iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

  	const const_iterator begin() const {
		return this->c.begin();
	}
	const const_iterator end() const {
		return this->c.end();
	}

	reverse_iterator rbegin() {
		return this->c.rbegin();
	}
	reverse_iterator rend() {
		return this->c.rend();
	}

	const reverse_iterator rbegin() const {
		return this->c.rend();
	}
	const reverse_iterator rend() const {
		return this->c.rend();
	}	
};

#endif