#include <iostream>
#include <vector>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"
#include "algorithm.hpp"
#include "random_access_iterator.hpp"
#include "Vector.hpp"

int main()
{
	/*
	*
	*	CONSTRUCTOR
	*
	*/
	// default
	ft::vector<int> vector_default;
	// fill
	ft::vector<int> vector_fill(10, 42);
	// range
	// copy
	ft::vector<int> vector_copy = vector_fill;


	for (int i = 0; i < 10; i++)
	{
		vector_default.push_back(i * 42);
	}
	std::cout << "vector_default (iterator): ";
	for (ft::vector<int>::iterator it = vector_default.begin(); it != vector_default.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "vector_default (reverse_iterator): ";
	for (ft::vector<int>::reverse_iterator rit = vector_default.rbegin(); rit != vector_default.rend(); rit++)
			std::cout << *rit << " ";
	std::cout << std::endl;

	// std::cout << "vector_default (const_iterator): ";
	// for (ft::vector<int>::const_iterator it = vector_default.begin(); it != vector_default.end(); it++)
	// 		std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << "vector_default (const_reverse_iterator): ";
	// for (ft::vector<int>::const_reverse_iterator rit = vector_default.rbegin(); rit != vector_default.rend(); rit++)
	// 		std::cout << *it << " ";
	// std::cout << std::endl;

	// std::cout << vector_default.size() << std::endl;
	// vector_default.clear();
	// std::cout << vector_default.size() << std::endl;
	// system("leaks a.out");
	return 0;
}
