#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "Iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::category			iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

		protected:
			iterator_type _current;

		public:
			// CONSTRUCTOR (default, initialization, copy)
			reverse_iterator(): _current() {};
			reverse_iterator (iterator_type it): _current(it) {};

			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it): _current(rev_it.base()) {};

			// MEMBER FUNCTIONS
			iterator_type base() const { return _current; }

			// *it
			reference operator*() const
			{
				iterator_type tmp = _current;
				return *--tmp;
			}

			// it + n
			reverse_iterator operator+(difference_type n) const
			{
				return reverse_iterator(_current - n);
			}

			// ++it
			reverse_iterator& operator++()
			{
				--_current;
				return *this;
			}

			// it++
			reverse_iterator  operator++(int)
			{
				reverse_iterator tmp = *this;
				--_current;
				return tmp;
			}

			// it += n
			reverse_iterator& operator+= (difference_type n)
			{
				_current -= n;
				return *this;
			}

			// it - n
			reverse_iterator operator- (difference_type n) const
			{
				return reverse_iterator (_current + n);
			}
			// --it
			reverse_iterator& operator--()
			{
				++_current;
				return *this;
			}
			// it--
			reverse_iterator& operator--(int)
			{
				reverse_iterator tmp = *this;
				++_current;
				return tmp;
			}

			// it -= n
			reverse_iterator& operator-=(difference_type n)
			{
				_current += n;
				return *this;
			}

			// it->
			pointer operator->() const
			{
				iterator_type tmp = _current;
				return &(*--tmp);
			}

			// it[]
			reference operator[](difference_type n) const
			{
					return *(*this + n);
			}
	};

	// NON MEMBER OPERATION
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return reverse_iterator<Iterator>(rev_it.base() - n);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return rhs.base() - lhs.base();
	}

}

#endif
