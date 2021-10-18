#ifndef reverseIterator_HPP
# define reverseIterator_HPP

# include "iterator_traits.hpp"
# include <iostream>
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
		/* Contructor and Destructor */
			// Default
			reverseIterator(): _current(iterator_type()) {};
			// Type specific
			explicit reverseIterator (iterator_type _current): _current(_current) {};
			// Copy
			template <class Iter>
			reverseIterator (reverseIterator<Iter> const& rev_it): _current(rev_it.base()) {};
			// Destructor
			virtual ~reverseIterator() {}

			iterator_type base() const { return _current; }

		/* Overload operator */
			// Access
			reference operator*() const { iterator_type tmp(_current); return *--tmp; }
			pointer operator->() const { return &(operator*()); }
			reference operator[](difference_type n) const { return *(*this + n); }

			// Assignement operator
			reverseIterator& operator=(reverseIterator const& rhs)
			{
				if (this != &rhs)
					_current = rhs._current;
				return *this;
			}

			// Increment / Decrement
			reverseIterator& operator++() { --_current; return *this; }
			reverseIterator  operator++(int) { reverseIterator<iterator_type> tmp(*this); --_current; return tmp; }
			reverseIterator& operator--() { ++_current; return *this; }
			reverseIterator operator--(int) { reverseIterator<iterator_type> tmp(*this); ++_current; return tmp; }

			// Arithmetic
			reverseIterator operator+(difference_type n) const { return reverseIterator<iterator_type>(_current - n); }
			reverseIterator operator-(difference_type n) const { return reverseIterator<iterator_type>(_current + n); }
			difference_type operator+(const Iterator &src) const { return _current - src._current; }
			difference_type operator-(const Iterator &src) const { return _current + src._current; }

			reverseIterator& operator+= (difference_type n) { _current -= n; return *this; }
			reverseIterator& operator-=(difference_type n) { _current += n; return *this; }

			difference_type substract(const reverseIterator<Iterator> rhs) const
			{
				return (rhs.base() - this->_current);
			}
	};

/* NON MEMBER OPERATION */
	template <class Iterator>
	bool operator==(const reverseIterator<Iterator> &lhs, const reverseIterator<Iterator> &rhs) { return (lhs.base() == rhs.base()); }

	template <class Iterator>
	bool operator!=(const reverseIterator<Iterator> &lhs, const reverseIterator<Iterator> &rhs) { return (lhs.base() != rhs.base()); }

	template <class Iterator>
	bool operator<(const reverseIterator<Iterator> &lhs, const reverseIterator<Iterator> &rhs) { return (lhs.base() > rhs.base()); }

	template <class Iterator>
	bool operator<=(const reverseIterator<Iterator> &lhs, const reverseIterator<Iterator> &rhs) { return (lhs.base() >= rhs.base()); }

	template <class Iterator>
	bool operator>(const reverseIterator<Iterator> &lhs, const reverseIterator<Iterator> &rhs) { return (lhs.base() < rhs.base()); }

	template <class Iterator>
	bool operator>=(const reverseIterator<Iterator> &lhs, const reverseIterator<Iterator> &rhs) { return (lhs.base() <= rhs.base()); }

	/* NON MEMBER OPERATION CONST AND NON CONST */
	template <class Iterator, class Iter>
	bool operator==(const reverseIterator<Iterator> &lhs, const reverseIterator<Iter> &rhs) { return (lhs.base() == rhs.base()); }

	template <class Iterator, class Iter>
	bool operator!= (const reverseIterator<Iterator> &lhs, const reverseIterator<Iter> &rhs) { return (lhs.base() != rhs.base()); }

	template <class Iterator, class Iter>
	bool operator<(const reverseIterator<Iterator> &lhs, const reverseIterator<Iter> &rhs) { return (lhs.base() > rhs.base()); }

	template <class Iterator, class Iter>
	bool operator<=(const reverseIterator<Iterator> &lhs, const reverseIterator<Iter> &rhs) { return (lhs.base() >= rhs.base()); }

	template <class Iterator, class Iter>
	bool operator>(const reverseIterator<Iterator> &lhs, const reverseIterator<Iter> &rhs) { return (lhs.base() < rhs.base()); }

	template <class Iterator, class Iter>
	bool operator>=(const reverseIterator<Iterator> &lhs, const reverseIterator<Iter> &rhs) { return (lhs.base() <= rhs.base()); }

	template <class Iterator>
	reverseIterator<Iterator> operator+(typename reverseIterator<Iterator>::difference_type n, const reverseIterator<Iterator> &rev_it)
	{
		return (rev_it + n);
	}

	template <class Iterator>
	typename reverseIterator<Iterator>::difference_type operator-(const reverseIterator<Iterator> &lhs, const reverseIterator<Iterator> &rhs)
	{
		return (lhs.substract(rhs));
	}

	template <class Iterator, class Iter>
	typename reverseIterator<Iterator>::difference_type operator-(const reverseIterator<Iterator> &lhs, const reverseIterator<Iter> &rhs)
	{
		return (lhs.substract(rhs));
	}

	template <class Iterator, class Iter>
	reverseIterator<Iterator> operator+(typename reverseIterator<Iterator>::difference_type n, const reverseIterator<Iter> &rev_it)
	{
		return (rev_it + n);
	}
}

#endif
