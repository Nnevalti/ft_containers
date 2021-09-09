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
	// ft::vector<const int> vector_default_const;
	// // fill
	// ft::vector<int> vector_fill(10, 42);
	// // range
	// // ft::vector<int> vector_range(vector_fill.begin(), vector_fill.end());
	// // copy
	// ft::vector<int> vector_copy(vector_fill);
	// ft::vector<int> vector_assignation_operator;
	// vector_assignation_operator = vector_fill;


	for (int i = 0; i < 10; i++)
	{
		vector_default.push_back(i * 42);
	}
	std::cout << "vector_default (iterator): ";
	for (ft::vector<int>::iterator it = vector_default.begin(); it != vector_default.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "vector_default (const_iterator): ";
	for (ft::vector<int>::const_iterator it = vector_default.begin(); it != vector_default.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "vector_default (reverse_iterator): ";
	for (ft::vector<int>::reverse_iterator rit = vector_default.rbegin(); rit != vector_default.rend(); rit++)
			std::cout << *rit << " ";
	std::cout << std::endl;

	std::cout << "vector_default (const_reverse_iterator): ";
	for (ft::vector<int>::const_reverse_iterator rit = vector_default.rbegin(); rit != vector_default.rend(); rit++)
			std::cout << *rit << " ";
	std::cout << std::endl;

	// vector_copy.push_back(420);
	// vector_assignation_operator.push_back(420);
	//
	// std::cout << "vector_fill (iterator): ";
	// for (ft::vector<int>::iterator it = vector_fill.begin(); it != vector_fill.end(); it++)
	// 		std::cout << *it << " ";
	// std::cout << std::endl;
	//
	// std::cout << "vector_copy (iterator): ";
	// for (ft::vector<int>::iterator it = vector_copy.begin(); it != vector_copy.end(); it++)
	// 		std::cout << *it << " ";
	// std::cout << std::endl;
	//
	// std::cout << "vector_assignation_operator (iterator): ";
	// for (ft::vector<int>::iterator it = vector_assignation_operator.begin(); it != vector_assignation_operator.end(); it++)
	// 		std::cout << *it << " ";
	// std::cout << std::endl;
	//
	// vector_assignation_operator = vector_default;
	// std::cout << "vector_assignation_operator (iterator): ";
	// for (ft::vector<int>::iterator it = vector_assignation_operator.begin(); it != vector_assignation_operator.end(); it++)
	// 		std::cout << *it << " ";
	// std::cout << std::endl;
	//

	// system("leaks a.out");
	return 0;
}
