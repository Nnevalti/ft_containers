#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"
#include <iostream>
namespace ft
{
	template <typename T>
	class randomAccessIterator
	{
		public:
		/* Member types */
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef const T*								const_pointer;
			typedef const T&								const_reference;
			typedef typename std::ptrdiff_t					difference_type;
			typedef typename ft::random_acces_iterator_tag	iterator_category;
			typedef randomAccessIterator<T>					iterator;

		protected:
		/* protected attributes */
			pointer _ptr;

		public:
		/* Contructor and Destructor */
			// Default
			randomAccessIterator(): _ptr(NULL) {}
			// Type specific
			randomAccessIterator(pointer ptr): _ptr(ptr) {}
			// Copy
			randomAccessIterator(const iterator &src): _ptr(src._ptr){}
			// Destructor
			~randomAccessIterator() {}

		/* Operator overload */
			// Assignement operator
			randomAccessIterator operator=(const iterator &src)
			{
				if (this != &src)
					_ptr = src._ptr;
				return *this;
			}

			// Overload called when trying to copy construct a const_iterator
			// based on an iterator
			operator randomAccessIterator<value_type const>() const
			{
				return randomAccessIterator<value_type const>(_ptr);
			}

			// Increment / Decrement
			iterator& operator++() { ++_ptr; return *this;}
			iterator operator++(int)
			{
				iterator tmp = _ptr;
				++_ptr;
				return (tmp);
			}
			iterator& operator--() { --_ptr; return *this;}
			iterator operator--(int)
			{
				iterator tmp = _ptr;
				--_ptr;
				return (tmp);
			}

			// Relational operator
			bool operator==(const iterator& src) const { return _ptr == src._ptr; }
			bool operator!=(const iterator& src) const { return _ptr != src._ptr; }
			bool operator<(const iterator& src) const { return _ptr < src._ptr; }
			bool operator>(const iterator& src) const { return _ptr > src._ptr; }
			bool operator<=(const iterator& src) const { return _ptr <= src._ptr; }
			bool operator>=(const iterator& src) const { return _ptr >= src._ptr; }

			// Arithmetic
			iterator operator+(const difference_type &n) const { return iterator(_ptr + n); }
			iterator operator-(const difference_type &n) const { return iterator(_ptr - n); }
			difference_type operator-(const iterator &src) const { return _ptr - src._ptr; }

			iterator& operator+=(difference_type n) { _ptr += n; return *this; }
			iterator& operator-=(difference_type n) { _ptr -= n; return *this; }

			// Access
			reference operator*(){ return *_ptr; }
			pointer operator->(){ return _ptr; }
			reference operator[](const difference_type n) const { return _ptr[n]; }

		/* For non const and const comparison */
			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator==(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs)
			{
				return lhs._ptr == rhs._ptr;
			}

			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator!=(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs)
			{
				return lhs._ptr != rhs._ptr;
			}

			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator<(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs)
			{
				return lhs._ptr < rhs._ptr;
			}

			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator<=(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs)
			{
				return lhs._ptr <= rhs._ptr;
			}

			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator>(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs)
			{
				return lhs._ptr > rhs._ptr;
			}

			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator>=(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs)
			{
				return lhs._ptr >= rhs._ptr;
			}
	};

	// n + randIte
	template<class T>
	ft::randomAccessIterator<T>
	operator+(typename ft::randomAccessIterator<T>::difference_type n,
				ft::randomAccessIterator<T> const& rhs)
	{
		return rhs + n;
	}
}

#endif
