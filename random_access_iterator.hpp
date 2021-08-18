#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template <typename T, typename Pointer = T*, typename Reference = T&>
	class randomAccessIterator
	{
		public:
			typedef T								value_type;
		    typedef std::ptrdiff_t					difference_type;
		    typedef Pointer							pointer;
		    typedef Reference						reference;
		    typedef ft::random_acces_iterator_tag	iterator_category;
			typedef randomAccessIterator<T>			iterator;

		protected:
			pointer _ptr;

		public:
			// X a, X(); X b(a), b = a, ~X()
			randomAccessIterator(): _ptr(NULL) {}
			randomAccessIterator(pointer ptr): _ptr(ptr) {}
			randomAccessIterator(const randomAccessIterator &src) { *this = src; }
			randomAccessIterator operator=(const randomAccessIterator &src)
			{
				if (this != &src)
					_ptr = src._ptr;
				return *this;
			}
			~randomAccessIterator() {}

			// ++a, a++
			iterator& operator++() { ++_ptr; return *this;}
			iterator& operator++(int)
			{
				iterator tmp = _ptr;
				++_ptr;
				return (tmp);
			}
			// --a, a--, *a--
			iterator& operator--() { --_ptr; return *this;}
			iterator& operator--(int)
			{
				iterator tmp = _ptr;
				--_ptr;
				return (tmp);
			}

			// a == b, a != b
			bool operator==(const randomAccessIterator& src) const { return _ptr == src._ptr; }
			bool operator!=(const randomAccessIterator& src) const { return _ptr != src._ptr; }
			// *a, a->m
			// *a = t
			reference operator*(){ return *_ptr; }
			pointer operator->(){ return _ptr; }

			// a + n, n + a, a - n, a - b
			// iterator operator+(const difference_type &n) { return iterator(_ptr - n); }
			// iterator operator-(const ) {}

			// a < b, a > b, a <= b, a >= b
			bool operator<(const iterator& src) const { return _ptr < src._ptr; }
			bool operator>(const iterator& src) const { return _ptr > src._ptr; }
			bool operator<=(const iterator& src) const { return _ptr <= src._ptr; }
			bool operator>=(const iterator& src) const { return _ptr >= src._ptr; }

			// a += n, a -= n
			iterator& operator+=(int n) { _ptr += n; return *this;}
			iterator& operator-=(int n) { _ptr -= n; return *this;}

			// a[n]
			reference operator[](const difference_type n) const { return _ptr[n]; }
	};
}

#endif
