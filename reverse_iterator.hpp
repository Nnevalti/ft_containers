#ifndef reverseIterator_HPP
# define reverseIterator_HPP

# include "iterator.hpp"
#include <iostream>
namespace ft
{
	template <class Iterator>
	class reverseIterator
	{
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

		protected:
			iterator_type _current;

		public:
		/*Contructor and Destructor */
			reverseIterator(): _current(iterator_type()) {};
			reverseIterator (iterator_type _current): _current(_current) {};
			template <class Iter>
			reverseIterator (const reverseIterator<Iter>& rev_it): _current(rev_it.base()) {};
			virtual ~reverseIterator() {}

		/* Overload operator */
			reverseIterator& operator=(reverseIterator const& rhs)
			{
				if (this != &rhs)
					_current = rhs._current;
				return *this;
			}

			// ++it
			reverseIterator& operator++()
			{
				--_current;
				return *this;
			}

			// it++
			reverseIterator  operator++(int)
			{
				reverseIterator tmp(*this);
				--_current;
				return tmp;
			}

			// --it
			reverseIterator& operator--()
			{
				++_current;
				return *this;
			}
			// it--
			reverseIterator operator--(int)
			{
				reverseIterator tmp(*this);
				++_current;
				return tmp;
			}

			bool operator==(const reverseIterator& src) const { return _current == src._current; }
			bool operator!=(const reverseIterator& src) const { return _current != src._current; }
			bool operator<(const reverseIterator& src) const { return _current < src._current; }
			bool operator>(const reverseIterator& src) const { return _current > src._current; }
			bool operator<=(const reverseIterator& src) const { return _current <= src._current; }
			bool operator>=(const reverseIterator& src) const { return _current >= src._current; }

			// it + n /  it - n / n - it
			reverseIterator operator+(difference_type n) const { return reverseIterator(_current - n); }
			reverseIterator operator-(difference_type n) const { return reverseIterator(_current + n); }
			difference_type operator-(const Iterator &src) const { return _current - src._current; }

			// it += n / it -= n
			reverseIterator& operator+= (difference_type n) { _current -= n; return *this; }
			reverseIterator& operator-=(difference_type n) { _current += n; return *this; }

			// *it
			reference operator*() const
			{
				iterator_type tmp = _current;
				return *--tmp;
			}

			// it->
			pointer operator->() const
			{
				iterator_type tmp = _current;
				return &(*--tmp);
			}

			// it[n]
			reference operator[](difference_type n) const { return *(*this + n); }

		/* MEMBER FUNCTIONS */
			iterator_type base() const { return _current; }

			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator== (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
			{
				return lhs._current == rhs._current;
			}

			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator!= (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
			{
				return lhs._current != rhs._current;
			}

			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator< (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
			{
				return lhs._current < rhs._current;
			}

			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator<= (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
			{
				return lhs._current <= rhs._current;
			}

			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator> (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
			{
				return lhs._current > rhs._current;
			}

			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator>= (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
			{
				return lhs._current >= rhs._current;
			}
	};

/* NON MEMBER OPERATION */
	template<class T>
	ft::reverseIterator<T>
	operator+(typename ft::reverseIterator<T>::difference_type n,
				ft::reverseIterator<T> const& rhs)
	{
		return rhs + n;
	}

	template <class Iterator_lhs, class Iterator_rhs>
	typename reverseIterator<Iterator_lhs>::difference_type operator- (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
	{
		// std::cout << (lhs.base() - rhs.base()) << '\n';
		return lhs.base() - rhs.base();
	}
}

#endif
