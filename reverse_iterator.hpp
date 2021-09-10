#ifndef reverseIterator_HPP
# define reverseIterator_HPP

# include "iterator.hpp"

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

			reference operator[](difference_type n) const
			{
					return *(*this + n);
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
			reverseIterator& operator--(int)
			{
				reverseIterator tmp(*this);
				++_current;
				return tmp;
			}

			// it + n
			reverseIterator operator+(difference_type n) const
			{
				return reverseIterator(_current - n);
			}

			// it += n
			reverseIterator& operator+= (difference_type n)
			{
				_current -= n;
				return *this;
			}

			// it - n
			reverseIterator operator- (difference_type n) const
			{
				return reverseIterator (_current + n);
			}

			// it -= n
			reverseIterator& operator-=(difference_type n)
			{
				_current += n;
				return *this;
			}

		/* MEMBER FUNCTIONS */
			iterator_type base() const { return _current; }
	};

/* NON MEMBER OPERATION */
	template <class Iterator>
	bool operator== (const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator>
	bool operator!= (const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class Iterator>
	bool operator<  (const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		return lhs.base() < rhs.base();
	}


	template <class Iterator>
	bool operator<= (const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		return lhs.base() <= rhs.base();
	}


	template <class Iterator>
	bool operator>  (const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		return lhs.base() > rhs.base();
	}


	template <class Iterator>
	bool operator>= (const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		return lhs.base() >= rhs.base();
	}


	template <class Iterator>
	reverseIterator<Iterator> operator+ (typename reverseIterator<Iterator>::difference_type n, const reverseIterator<Iterator>& rev_it)
	{
		return reverseIterator<Iterator>(rev_it.base() - n);
	}


	template <class Iterator>
	typename reverseIterator<Iterator>::difference_type operator- (const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
	{
		return rhs.base() - lhs.base();
	}

/* For non const and const comparison */
	template <class Iterator_lhs, class Iterator_rhs>
	bool operator== (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator_lhs, class Iterator_rhs>
	bool operator!= (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class Iterator_lhs, class Iterator_rhs>
	bool operator< (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class Iterator_lhs, class Iterator_rhs>
	bool operator<= (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class Iterator_lhs, class Iterator_rhs>
	bool operator> (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class Iterator_lhs, class Iterator_rhs>
	bool operator>= (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class Iterator_lhs, class Iterator_rhs>
	bool operator+ (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
	{
		return lhs.base() + rhs.base();
	}

	template <class Iterator_lhs, class Iterator_rhs>
	bool operator- (const reverseIterator<Iterator_lhs>& lhs, const reverseIterator<Iterator_rhs>& rhs)
	{
		return lhs.base() - rhs.base();
	}
}

#endif
