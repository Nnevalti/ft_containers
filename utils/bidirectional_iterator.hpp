#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

namespace ft
{
	template <class T>
	class bidirectionalIterator
	{
		public:
			typedef T											value_type;
			typedef T*											pointer;
			typedef T&											reference;
			typedef const T*									const_pointer;
			typedef const T&									const_reference;
			typedef typename std::ptrdiff_t						difference_type;
			typedef typename ft::bidirectional_iterator_tag		iterator_category;
			typedef rb_Node<value_type>*						node_ptr;

		/* Contructor and Destructor */
			// Default
			bidirectionalIterator(): _ptr(NULL);
			// Type specific
			bidirectionalIterator(node_ptr ptr): _ptr(ptr) {}
			// Copy
			bidirectionalIterator(const bidirectionalIterator &src): _ptr(src._ptr) {}
			// Destructor
			virtual ~bidirectionalIterator() {}

		/* Operator overload */
			// Assignement operator
			bidirectionalIterator operator=(const bidirectionalIterator &src)
			{
				if (this != &src)
					_ptr = src._ptr;
				return *this;
			}

			// Overload called when trying to copy construct a const_iterator
			// based on an iterator
			operator bidirectionalIterator<value_type const>() const
			{
				return bidirectionalIterator<value_type const>(_ptr);
			}

			// Relational operator
			bool operator==(const bidirectionalIterator& src) const { return _ptr == src._ptr; }
			bool operator!=(const bidirectionalIterator& src) const { return _ptr != src._ptr; }

			// Const and non const relational operator
			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator==(const bidirectionalIterator<Iterator_lhs>& lhs, const bidirectionalIterator<Iterator_rhs>& rhs) { return lhs._ptr == rhs._ptr; }
			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator!=(const bidirectionalIterator<Iterator_lhs>& lhs, const bidirectionalIterator<Iterator_rhs>& rhs) { return lhs._ptr != rhs._ptr; }

			// Increment / Decrement
			bidirectionalIterator& operator++() { _ptr = _ptr->getNextNode(); return *this; }
			bidirectionalIterator operator++(int)
			{
				bidirectionalIterator tmp(*this);
				++_ptr;
				return (tmp);
			}
			bidirectionalIterator& operator--() { --_ptr; return *this;}
			bidirectionalIterator operator--(int)
			{
				bidirectionalIterator tmp(*this);
				--_ptr;
				return (tmp);
			}

			// Access
			reference operator*(){ return *_ptr; }
			pointer operator->(){ return _ptr; }

			value_type& value(rb_Node *)
			{
				return _ptr;
			}

			protected:
			/* protected attributes */
				node_ptr _ptr;
	}
}

#endif
