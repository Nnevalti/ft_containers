#ifndef MAP_HPP
# define MAP_HPP

# include "utils/pair.hpp"
# include "utils/red_black_node.hpp"
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
			explicit map (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _rbTree(NULL), _size(0) {}

			// DESTRUCTOR
			// = operator overload

			// begin
			// end
			// rbegin
			// rend

			// empty
			// size
			// max_size

			// insert
			// erase
			// swap
			// clear

			// key_comp
			// value_comp

			// find
			// count
			// lower_bound
			// upper_bound
			// equal_range

			// get_allocator

			protected:
				allocator_type						_alloc;
				rb_Tree<value_type>					_rbTree;
				size_type							_size;

	};

	// relational operator
}

#endif
