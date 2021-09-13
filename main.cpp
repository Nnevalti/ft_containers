#include <iostream>
#include <vector>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"
#include "algorithm.hpp"
#include "random_access_iterator.hpp"
#include "Vector.hpp"

// TEST for Vector:
//	Constructors
//		default, fill, range, copy, assignation operator
//	Accessors, iterators, getters, setters:
//		iterator, const_iterator, reverse_iterator, const_reverse_iterator, begin, end, rbegin, rend
//		size, max_size, resize, capacity, empty, reserve
//		operator[], at, front, back
//		assign, push_back, pop_back, insert, erase, swap, clear

int main()
{
	/********************************/
	/*		DEFAULT CONSTRUCTOR		*/
	/********************************/
	std::cout << "DEFAULT CONSTRUCTOR: ft::vector vs std::vector" << std::endl;
	ft::vector<int> ft_vector;
	std::vector<int> std_vector;

	std::cout << "ft_vector size: " << ft_vector.size() << ", capacity: " << ft_vector.capacity() << std::endl;
	std::cout << "std_vector size: " << std_vector.size() << ", capacity: " << std_vector.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "FILL CONSTRUCTOR: ft::vector vs std::vector" << std::endl;
	ft::vector<int> ft_vector_fill(10, 42);
	std::vector<int> std_vector_fill(10, 42);

	std::cout << "ft_vector_fill size: " << ft_vector_fill.size() << ", capacity: " << ft_vector_fill.capacity() << std::endl;
	std::cout << "std_vector_fill size: " << std_vector_fill.size() << ", capacity: " << std_vector_fill.capacity() << std::endl;
	std::cout << std::endl;
	std::cout << "ft_vector_fill: ";
	for (ft::vector<int>::iterator it = ft_vector_fill.begin(); it != ft_vector_fill.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "std_vector_fill: ";
	for (std::vector<int>::iterator it = std_vector_fill.begin(); it != std_vector_fill.end(); it++)
			std::cout << *it << " ";
	std::cout << "\n" << std::endl;

	std::cout << "RANGE CONSTRUCTOR: ft::vector vs std::vector" << std::endl;
	ft::vector<int> ft_vector_range(ft_vector_fill.begin(), ft_vector_fill.end());
	std::vector<int> std_vector_range(std_vector_fill.begin(), std_vector_fill.end());

	std::cout << "ft_vector_range size: " << ft_vector_range.size() << ", capacity: " << ft_vector_range.capacity() << std::endl;
	std::cout << "std_vector_range size: " << std_vector_range.size() << ", capacity: " << std_vector_range.capacity() << std::endl;
	std::cout << std::endl;
	std::cout << "ft_vector_range: ";
	for (ft::vector<int>::iterator it = ft_vector_range.begin(); it != ft_vector_range.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "std_vector_range: ";
	for (std::vector<int>::iterator it = std_vector_range.begin(); it != std_vector_range.end(); it++)
			std::cout << *it << " ";
	std::cout << "\n" << std::endl;

	std::cout << "COPY CONSTRUCTOR (copy of range): ft::vector vs std::vector" << std::endl;
	ft::vector<int> ft_vector_copy(ft_vector_range);
	std::vector<int> std_vector_copy(std_vector_range);

	std::cout << "ft_vector_copy size: " << ft_vector_copy.size() << ", capacity: " << ft_vector_copy.capacity() << std::endl;
	std::cout << "std_vector_copy size: " << std_vector_copy.size() << ", capacity: " << std_vector_copy.capacity() << std::endl;
	std::cout << std::endl;
	std::cout << "ft_vector_copy: ";
	for (ft::vector<int>::iterator it = ft_vector_copy.begin(); it != ft_vector_copy.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "std_vector_copy: ";
	for (std::vector<int>::iterator it = std_vector_copy.begin(); it != std_vector_copy.end(); it++)
			std::cout << *it << " ";
	std::cout << "\n" << std::endl;

	std::cout << "ASSIGNATION OPERATOR: ft::vector vs std::vector" << std::endl;
	ft::vector<int> ft_vector_assignation;
	std::vector<int> std_vector_assignation;
	ft_vector_assignation = ft_vector_copy;
	std_vector_assignation = std_vector_copy;

	std::cout << "ft_vector_assignation size: " << ft_vector_assignation.size() << ", capacity: " << ft_vector_assignation.capacity() << std::endl;
	std::cout << "std_vector_assignation size: " << std_vector_assignation.size() << ", capacity: " << std_vector_assignation.capacity() << std::endl;
	std::cout << std::endl;
	std::cout << "ft_vector_assignation: ";
	for (ft::vector<int>::iterator it = ft_vector_assignation.begin(); it != ft_vector_assignation.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "std_vector_assignation: ";
	for (std::vector<int>::iterator it = std_vector_assignation.begin(); it != std_vector_assignation.end(); it++)
			std::cout << *it << " ";
	std::cout << "\n" << std::endl;

	ft_vector = ft_vector_assignation;
	std_vector = std_vector_assignation;
	std::cout << "ITERATOR TEST:\n" << std::endl;
	std::cout << "ft_vector (iterator): ";
	for (ft::vector<int>::iterator it = ft_vector.begin(); it != ft_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "std_vector (iterator): ";
	for (std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << "\n" << std::endl;

	std::cout << "ft_vector (const_iterator): ";
	for (ft::vector<int>::const_iterator it = ft_vector.begin(); it != ft_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "std_vector (const_iterator): ";
	for (std::vector<int>::const_iterator it = std_vector.begin(); it != std_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << "\n" << std::endl;

	std::cout << "ft_vector (reverse_iterator): ";
	for (ft::vector<int>::reverse_iterator rit = ft_vector.rbegin(); rit != ft_vector.rend(); rit++)
			std::cout << *rit << " ";
	std::cout << std::endl;

	std::cout << "std_vector (reverse_iterator): ";
	for (std::vector<int>::reverse_iterator rit = std_vector.rbegin(); rit != std_vector.rend(); rit++)
			std::cout << *rit << " ";
	std::cout << "\n" << std::endl;

	std::cout << "ft_vector (const_reverse_iterator): ";
	for (ft::vector<int>::const_reverse_iterator rit = ft_vector.rbegin(); rit != ft_vector.rend(); rit++)
			std::cout << *rit << " ";
	std::cout << std::endl;

	std::cout << "std_vector (reverse_iterator): ";
	for (std::vector<int>::const_reverse_iterator rit = std_vector.rbegin(); rit != std_vector.rend(); rit++)
			std::cout << *rit << " ";
	std::cout << "\n" << std::endl;

	std::cout << "ACCESSOR AND MEMBER FUNCTIONS:\nsize, max_size, capacity, resize, empty, reserve\n" << std::endl;

	std::cout << "BEFORE RESIZE" << std::endl;
	std::cout << "ft_vector :" << "size: "<< ft_vector.size() << ", max_size: "<< ft_vector.max_size() <<  ", capacity: " << ft_vector.capacity() << std::endl;
	std::cout << "std_vector :" << "size: "<< std_vector.size() << ", max_size: "<< std_vector.max_size() <<  ", capacity: " << std_vector.capacity() << std::endl;
	std::cout << std::endl;

// rezize(15) test
	std::cout << "AFTER RESIZE(15)" << std::endl;
	ft_vector.resize(15);
	std_vector.resize(15);
	std::cout << "ft_vector :" << "size: "<< ft_vector.size() << ", max_size: "<< ft_vector.max_size() <<  ", capacity: " << ft_vector.capacity() << std::endl;
	std::cout << "std_vector :" << "size: "<< std_vector.size() << ", max_size: "<< std_vector.max_size() <<  ", capacity: " << std_vector.capacity() << std::endl;
	std::cout << "ft_vector : ";
	for (ft::vector<int>::iterator it = ft_vector.begin(); it != ft_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "std_vector : ";
	for (std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << "\n" << std::endl;


// resize(20, 42 test)
	std::cout << "AFTER RESIZE(20, 42)" << std::endl;
	ft_vector.resize(20, 42);
	std_vector.resize(20, 42);
	std::cout << "ft_vector :" << "size: "<< ft_vector.size() << ", max_size: "<< ft_vector.max_size() <<  ", capacity: " << ft_vector.capacity() << std::endl;
	std::cout << "std_vector :" << "size: "<< std_vector.size() << ", max_size: "<< std_vector.max_size() <<  ", capacity: " << std_vector.capacity() << std::endl;
	std::cout << "ft_vector : ";
	for (ft::vector<int>::iterator it = ft_vector.begin(); it != ft_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "std_vector : ";
	for (std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << "\n" << std::endl;

	std::cout << "ft_vector : ";
	for (ft::vector<int>::iterator it = ft_vector.begin(); it != ft_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "std_vector : ";
	for (std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << "\n" << std::endl;

	std::cout << "VECTOR EMPTY():" << std::endl;
	std::cout << "ft_vector empty() (1/true if empty 0/false if not): " << ft_vector.empty() << std::endl;
	std::cout << "std_vector empty() (1/true if empty 0/false if not): " << std_vector.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "VECTOR RESERVE(max_size):" << std::endl;
	try
	{
		ft_vector.reserve(ft_vector.max_size());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std_vector.reserve(std_vector.max_size());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "VECTOR RESERVE(max_size + 1):" << std::endl;
	try
	{
		ft_vector.reserve(4611686018427387904);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std_vector.reserve(4611686018427387904);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "VECTOR RESERVE(50):" << std::endl;
	ft_vector.reserve(50);
	std_vector.reserve(50);
	std::cout << "ft_vector :" << "size: "<< ft_vector.size() << ", max_size: "<< ft_vector.max_size() <<  ", capacity: " << ft_vector.capacity() << std::endl;
	std::cout << "std_vector :" << "size: "<< std_vector.size() << ", max_size: "<< std_vector.max_size() <<  ", capacity: " << std_vector.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "VECTOR [] OPERATOR:" << std::endl;
	std::cout << "ft_vector : ";
	for (int i = 0; ft_vector[i]; i++)
			std::cout << ft_vector[i] << " ";
	std::cout << std::endl;
	std::cout << "std_vector : ";
	for (int i = 0; std_vector[i]; i++)
			std::cout << std_vector[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "VECTOR AT():" << std::endl;
	try
	{
		std::cout << "ft_vector : ";
		for (int i = 0; i < ft_vector.size() + 1; i++)
				std::cout << ft_vector.at(i) << " ";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "std_vector : ";
		for (int i = 0; i < std_vector.size() + 1; i++)
				std::cout << std_vector.at(i) << " ";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "VECTOR FRONT():" << std::endl;
	std::cout << "ft_vector : " << ft_vector.front() << std::endl;
	std::cout << "std_vector : " << std_vector.front() << std::endl;
	std::cout << std::endl;

	std::cout << "VECTOR BACK():" << std::endl;
	std::cout << "ft_vector : " << ft_vector.back() << std::endl;
	std::cout << "std_vector : " << std_vector.back() << std::endl;
	std::cout << std::endl;

	std::cout << "VECTOR ASSIGN():" << std::endl;
	std::cout << std::endl;

	std::cout << "VECTOR PUSH_BACK(i * 42):" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		ft_vector.push_back(i * 42);
		std::cout << "ft_vector push_back(" << i * 42 << "), size: " << ft_vector.size() << ", capacity: " << ft_vector.capacity() << std::endl;
		std_vector.push_back(i * 42);
		std::cout << "std_vector push_back(" << i * 42 << "), size: " << std_vector.size() << ", capacity: " << std_vector.capacity() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "ft_vector : ";
	for (ft::vector<int>::iterator it = ft_vector.begin(); it != ft_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "std_vector : ";
	for (std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << "\n" << std::endl;

	std::cout << "VECTOR POP_BACK():" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		ft_vector.pop_back();
		std::cout << "ft_vector push_back(" << i * 42 << "), size: " << ft_vector.size() << ", capacity: " << ft_vector.capacity() << std::endl;
		std_vector.pop_back();
		std::cout << "std_vector push_back(" << i * 42 << "), size: " << std_vector.size() << ", capacity: " << std_vector.capacity() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "ft_vector : ";
	for (ft::vector<int>::iterator it = ft_vector.begin(); it != ft_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "std_vector : ";
	for (std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); it++)
			std::cout << *it << " ";
	std::cout << "\n" << std::endl;
	std::cout << std::endl;

	std::cout << "VECTOR CLEAR():\n" << std::endl;
	ft_vector.clear();
	std_vector.clear();
	std::cout << "ft_vector after clear(), size: " << ft_vector.size() << ", capacity: " << ft_vector.capacity() << std::endl;
	std::cout << "std_vector after clear(), size: " << std_vector.size() << ", capacity: " << std_vector.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "VECTOR EMPTY():" << std::endl;
	std::cout << "ft_vector empty() (1/true if empty 0/false if not): " << ft_vector.empty() << std::endl;
	std::cout << "std_vector empty() (1/true if empty 0/false if not): " << std_vector.empty() << std::endl;
	std::cout << std::endl;

	system("leaks a.out");
	return 0;
}
