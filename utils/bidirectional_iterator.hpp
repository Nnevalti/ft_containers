#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <functional>
# include "iterator_traits.hpp"

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
			typedef Node<value_type>*							node_ptr;

		/* Contructor and Destructor */
			// Default
			bidirectionalIterator(): _root(NULL), _nil(NULL), _ptr(NULL) {}
			// Type specific
			bidirectionalIterator(node_ptr root, node_ptr nil, node_ptr ptr): _root(root), _nil(nil), _ptr(ptr) {}
			// Copy
			bidirectionalIterator(const bidirectionalIterator &src):_root(src._root), _nil(src._nil), _ptr(src._ptr) {}
			// Destructor
			virtual ~bidirectionalIterator() {}

		/* Operator overload */
			// Assignement operator
			bidirectionalIterator operator=(const bidirectionalIterator &src)
			{
				if (this != &src)
				{
					_root = src._root;
					_nil = src._nil;
					_ptr = src._ptr;
				}
				return *this;
			}

			// Overload called when trying to copy construct a const_iterator
			// based on an iterator
			operator bidirectionalIterator<value_type const>() const
			{
				return bidirectionalIterator<value_type const>(_root, _nil, _ptr);
			}

			// Relational operator
			bool operator==(const bidirectionalIterator& src) const { return _ptr == src._ptr; }
			bool operator!=(const bidirectionalIterator& src) const { return _ptr != src._ptr; }

			// Const and non const relational operator
			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator==(const bidirectionalIterator<Iterator_lhs>& lhs, const bidirectionalIterator<Iterator_rhs>& rhs) { return lhs._ptr == rhs._ptr; }
			template <class Iterator_lhs, class Iterator_rhs>
			friend bool operator!=(const bidirectionalIterator<Iterator_lhs>& lhs, const bidirectionalIterator<Iterator_rhs>& rhs) { return !(lhs._ptr == rhs._ptr); }

			// Increment / Decrement
			bidirectionalIterator& operator++()
			{
				if (_ptr != _nil)
					_ptr = successor(_ptr);
				return *this;
			}

			bidirectionalIterator operator++(int)
			{
				bidirectionalIterator tmp(*this);
				operator++();
				return (tmp);
			}

			bidirectionalIterator &operator--()
			{
				if (_ptr == _nil)
					_ptr = maximum(_root);
				else
					_ptr = predecessor(_ptr);
				return (*this);
			}

			bidirectionalIterator operator--(int)
			{
				bidirectionalIterator tmp(*this);
				operator--();
				return (tmp);
			}

			// Access
			reference operator*(){ return this->_ptr->data; }
			pointer operator->(){ return &(this->_ptr->data); }

			protected:
			/* protected attributes */
				node_ptr	_root;
				node_ptr	_nil;
				node_ptr	_ptr;

				// same as in rbTree class
				node_ptr minimum(node_ptr node)
				{
					while (node->left != _nil)
						node = node->left;
					return node;
				}

				// same as in rbTree class
				node_ptr maximum(node_ptr node)
				{
					while (node->right != _nil)
						node = node->right;
					return node;
				}

				// same as in rbTree class
				node_ptr successor(node_ptr x)
				{
					if (x->right != _nil)
					{
						return minimum(x->right);
					}
					node_ptr y = x->parent;
					while (y != NULL && x == y->right)
					{
						x = y;
						y = y->parent;
					}
					if (y == NULL)
						return _nil;
					return y;
				}

				// same as in rbTree class
				node_ptr predecessor(node_ptr x)
				{
					if (x->left != _nil)
					{
						return maximum(x->left);
					}
					node_ptr y = x->parent;
					while (y != _nil && x == y->left)
					{
						x = y;
						y = y->parent;
					}
					return y;
				}
	};
}

#endif
