#ifndef MAP_HPP
# define MAP_HPP

# include "utils/pair.hpp"
# include "utils/red_black_tree.hpp"

# include <functional>
# include <memory>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;

			typedef ft::bidirectionalIterator<value_type>		iterator;
			typedef ft::bidirectionalIterator<value_type const>	const_iterator;
			typedef ft::reverseIterator<iterator>				reverse_iterator;
			typedef ft::reverseIterator<const_iterator>			const_reverse_iterator;

			// CONSTRUCTOR
			// default
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp) _alloc(alloc), _rbTree(NULL), _size(0) {}

			// range
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _comp(comp) _alloc(alloc), size(0)
			{
				this->insert(first, last);
			}

			// copy
			map (const map& x)
			{
				this->insert(x.begin(), x.end());
			}

			// DESTRUCTOR
			~map()
			{
				~_rbTree();
			}
			// = operator overload
			map& operator= (const map& x)
			{
				if (this != &x)
				{
					this->clear();
					this->_alloc = x._alloc;
					this->_comp = x._comp;
					this->insert(x.begin(), x.end());
				}
				return (*this);
			}

			// begin
			iterator				begin() { return iterator(this->_rbTree->_root->data); }
			const_iterator			begin() const { return const_iterator(this->_rbTree->_root->data); }

			// end
			iterator				end() { return iterator(this->_rbTree->_root->max()->data); }
			const_iterator			end() const { return const_iterator(this->_rbTree->_root->max()->data); }

			// rbegin
			reverse_iterator		rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }

			// rend
			reverse_iterator		rend() { return reverse_iterator(begin()); }
			const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); }

			// empty
			bool empty() const { return (_size == 0); }
			// size
			size_type size() const { return _size; }
			// max_size
			size_type max_size() const { return _alloc.max_size(); }

			// insert
			// erase
			// swap
			// clear

			// key_comp
			key_compare		key_comp() const { return this->_comp; }
			// value_comp
			value_compare	value_comp() const { return value_compare(this->_comp); }

			// find
			iterator find(const Key_type& k)
			{
				Node node = _rbTree.search(k);
				return (iterator(node->data));
			}
			
			// count
			// lower_bound
			// upper_bound
			// equal_range

			// get_allocator
			allocator_type get_allocator() const { return _alloc; }

			protected:
				key_compare											_comp;
				allocator_type										_alloc;
				rb_Tree<value_type, key_compare, allocator_type>	_rbTree;
				size_type											_size;

	};

	// relational operator
}

#endif
