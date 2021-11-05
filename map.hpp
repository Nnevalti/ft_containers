#ifndef MAP_HPP
# define MAP_HPP

# include <memory>

# include "utils/algorithm.hpp"
# include "utils/pair.hpp"
# include "utils/red_black_tree.hpp"
# include "utils/iterator_traits.hpp"
# include "utils/bidirectional_iterator.hpp"
# include "utils/reverse_iterator.hpp"

# include <functional>
# include <memory>

namespace ft
{
	template <class T, class U>
	struct select1st : public std::unary_function<T, U>
	{
	    const U& operator()(const T& x) const { return x.first; }
	};

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;
			typedef Compare										key_compare;
			class												value_compare;
			typedef Alloc										allocator_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;

			typedef ft::RBTree<key_type, value_type, select1st<value_type, key_type>, key_compare>	tree_type;
			typedef Node<value_type>	node_type;
			typedef Node<value_type>*	node_ptr;

			typedef ft::bidirectionalIterator<value_type, node_type>		iterator;
			typedef ft::bidirectionalIterator<value_type const, node_type const>	const_iterator;
			typedef ft::reverseIterator<iterator>				reverse_iterator;
			typedef ft::reverseIterator<const_iterator>			const_reverse_iterator;


			// CONSTRUCTOR
			// default
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _rbTree() {}

			// range
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc)
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
				// _rbTree.prettyPrint();
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
			iterator				begin()
			{ return iterator(_rbTree.getRoot(), _rbTree.getNil(), _rbTree.min()); }
			const_iterator			begin() const
			{ return const_iterator(_rbTree.getRoot(), _rbTree.getNil(), _rbTree.min()); }

			// end
			iterator				end()
			{ return iterator(_rbTree.getRoot(), _rbTree.getNil(), _rbTree.getNil()); }

			const_iterator			end() const
			{ return const_iterator(_rbTree.getRoot(), _rbTree.getNil(), _rbTree.getNil()); }

			// rbegin
			reverse_iterator		rbegin()
			{ return reverse_iterator(end()); }

			const_reverse_iterator	rbegin() const
			{ return const_reverse_iterator(end()); }

			// rend
			reverse_iterator		rend()
			{ return reverse_iterator(begin()); }

			const_reverse_iterator	rend() const
			{ return const_reverse_iterator(begin()); }

			// empty
			bool empty() const { return (_rbTree.size() == 0); }
			// size
			size_type size() const { return _rbTree.size(); }
			// max_size
			size_type max_size() const { return _rbTree.max_size(); }

			mapped_type& operator[] (const key_type& k)
			{
				node_ptr node = _rbTree.search(k);
				if (node != _rbTree.getNil())
					return node->data.second;
				_rbTree.insert(value_type(k, mapped_type()));
				node = _rbTree.search(k);
				return node->data.second;
			}

			// insert
			ft::pair<iterator, bool> insert(const value_type& val)
			{
				bool succes = _rbTree.insert(val);
				iterator it = find(val.first);
				return ft::pair<iterator, bool>(it, succes);
			}

			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				return insert(val).first;
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
					while (first != last)
						insert(*(first++));
			}

			// erase
			void erase (iterator position)
			{
				this->erase((*position).first);
			}

			size_type erase(const key_type& k)
			{

				if (_rbTree.deleteNode(k))
					return 1;
				return 0;
			}

			void erase (iterator first, iterator last)
			{
				while (first != last)
					this->erase((*(first++)).first);
			}

			// swap
			void swap (map& x)
			{
				_rbTree.swap(x._rbTree);
			}

			// clear
			void clear()
			{
				erase(begin(), end());
			}

			// key_comp and value_comp
			key_compare		key_comp() const { return this->_comp; }
			value_compare	value_comp() const { return value_compare(this->_comp); }

			// find
			iterator find(const key_type& k)
			{
				node_ptr node = _rbTree.search(k);
				if (node == _rbTree.getNil())
					return end();
				return (iterator(_rbTree.getRoot(), _rbTree.getNil(), node));
			}

			const_iterator find (const key_type& k) const
			{
				node_ptr node = _rbTree.search(k);
				if (node == _rbTree.getNil())
					return end();
				return (const_iterator(_rbTree.getRoot(), _rbTree.getNil(), node));
			}

			// count
			size_type count (const key_type& k) const
			{
				const_iterator beg = this->begin();
				const_iterator end = this->end();

				while (beg != end)
					if ((*(beg++)).first == k)
						return (1);
				return (0);
			}
			// lower_bound
			iterator lower_bound (const key_type& k)
			{
				iterator beg = this->begin();
				iterator end = this->end();

				while (beg != end)
				{
					if (_comp((*beg).first, k) == false)
						break;
					beg++;
				}
				return (beg);
			}

			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator beg = this->begin();
				const_iterator end = this->end();

				while (beg != end)
				{
					if (_comp((*beg).first, k) == false)
						break;
					beg++;
				}
				return (beg);
			}

			// upper_bound
			iterator upper_bound (const key_type& k)
			{
				iterator beg = this->begin();
				iterator end = this->end();

				while (beg != end)
				{
					if (_comp(k, (*beg).first))
						break;
					beg++;
				}
				return (beg);
			}
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator beg = this->begin();
				const_iterator end = this->end();

				while (beg != end)
				{
					if (_comp(k, (*beg).first))
						break;
					beg++;
				}
				return (beg);
			}

			// equal_range
			ft::pair<iterator, iterator> equal_range (const key_type& k)
			{
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}

			ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			{
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}

			// get_allocator
			allocator_type get_allocator() const { return _alloc; }

			protected:
				key_compare			_comp;
				allocator_type		_alloc;
				tree_type			_rbTree;

	};

	// relational operator
	// == !=
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(rhs == lhs);
	}
	// < >
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	// <= >=
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	// other
	template <class Key, class T, class Compare, class Alloc>
	class map<Key, T, Compare, Alloc>::value_compare
	{
		friend class map;

		protected:
			Compare _comp;
			value_compare (Compare c): _comp(c) {}
		public:
			typedef bool			result_type;
			typedef value_type		first_argument_type;
			typedef value_type		second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return _comp(x.first, y.first);
			}
	};
}

#endif
