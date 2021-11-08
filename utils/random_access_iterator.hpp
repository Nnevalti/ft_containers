#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

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

		/* Contructor and Destructor */
			// Default
			randomAccessIterator(): _ptr(NULL) {}
			// Type specific
			randomAccessIterator(pointer ptr): _ptr(ptr) {}
			// Copy
			randomAccessIterator(const randomAccessIterator &src): _ptr(src._ptr) {}
			// Destructor
			virtual ~randomAccessIterator() {}

		/* Operator overload */
			// Assignement operator
			randomAccessIterator operator=(const randomAccessIterator &src)
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

			// Relational operator
			bool operator==(const randomAccessIterator& src) const { return _ptr == src._ptr; }
			bool operator!=(const randomAccessIterator& src) const { return _ptr != src._ptr; }
			bool operator<(const randomAccessIterator& src) const { return _ptr < src._ptr; }
			bool operator>(const randomAccessIterator& src) const { return _ptr > src._ptr; }
			bool operator<=(const randomAccessIterator& src) const { return _ptr <= src._ptr; }
			bool operator>=(const randomAccessIterator& src) const { return _ptr >= src._ptr; }

			// Const and non const relational operator
			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator==(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs);
			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator!=(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs);
			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator<(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs);
			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator<=(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs);
			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator>(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs);
			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator>=(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs);

			// Increment / Decrement
			randomAccessIterator& operator++() { ++_ptr; return *this; }
			randomAccessIterator operator++(int)
			{
				randomAccessIterator tmp(*this);
				++_ptr;
				return (tmp);
			}
			randomAccessIterator& operator--() { --_ptr; return *this;}
			randomAccessIterator operator--(int)
			{
				randomAccessIterator tmp(*this);
				--_ptr;
				return (tmp);
			}

			// Arithmetic
			randomAccessIterator operator+(difference_type n) const { return randomAccessIterator<T>(_ptr + n); }
			randomAccessIterator operator-(difference_type n) const { return randomAccessIterator<T>(_ptr - n); }
			difference_type operator-(randomAccessIterator const &src) const { return _ptr - src._ptr; }

			randomAccessIterator& operator+=(difference_type n) { _ptr += n; return *this; }
			randomAccessIterator& operator-=(difference_type n) { _ptr -= n; return *this; }

			// Access
			reference operator*(){ return *_ptr; }
			pointer operator->(){ return _ptr; }
			reference operator[](const difference_type n) const { return _ptr[n]; }

		protected:
		/* protected attributes */
			pointer _ptr;
	};

	template <class Iterator_lhs, class Iterator_rhs>
	bool operator==(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs) { return lhs._ptr == rhs._ptr; }
	template <class Iterator_lhs, class Iterator_rhs>
	bool operator!=(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs) { return lhs._ptr != rhs._ptr; }
	template <class Iterator_lhs, class Iterator_rhs>
	bool operator<(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs) { return lhs._ptr < rhs._ptr; }
	template <class Iterator_lhs, class Iterator_rhs>
	bool operator<=(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs) { return lhs._ptr <= rhs._ptr; }
	template <class Iterator_lhs, class Iterator_rhs>
	bool operator>(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs) { return lhs._ptr > rhs._ptr; }
	template <class Iterator_lhs, class Iterator_rhs>
	bool operator>=(const randomAccessIterator<Iterator_lhs>& lhs, const randomAccessIterator<Iterator_rhs>& rhs) { return lhs._ptr >= rhs._ptr; }

	// n + randIte
	template<class T>
	ft::randomAccessIterator<T> operator+(typename ft::randomAccessIterator<T>::difference_type n, ft::randomAccessIterator<T> const& rhs)
	{
		return rhs + n;
	}
}

#endif
