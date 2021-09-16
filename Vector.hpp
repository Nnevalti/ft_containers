#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "algorithm.hpp"
# include "type_traits.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type				size_type;


			typedef ft::randomAccessIterator<value_type>		iterator;
			typedef ft::randomAccessIterator<value_type const>	const_iterator;
			typedef reverseIterator<iterator>					reverse_iterator;
			typedef reverseIterator<const_iterator>				const_reverse_iterator;

			// CONSTRUCTOR
			// default
			explicit vector (const allocator_type& alloc = allocator_type())
			: _size(0), _capacity(0), _alloc(alloc), _array(NULL) {}

			// fill
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _size(n), _capacity(n), _alloc(alloc)
			{
				_array = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_array[i], val);
			}

			// range
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
			: _size(0), _capacity(0), _alloc(alloc), _array(NULL)
			{
				difference_type diff = 0;

				for (InputIterator tmp = first; tmp != last; tmp++, diff++);
				_size = diff;
				_capacity = _size;
				_array = _alloc.allocate(_capacity);
				for (int i = 0; first != last; i++, first++)
					_alloc.construct(&_array[i], *first);
			}

			// copy
			vector (const vector& x) : _size(x._size), _capacity(x._capacity), _alloc(x._alloc)
			{
				_array = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_array[i], x._array[i]);
			}

			// DESTRUCTOR
			~vector()
			{
				for (iterator it = begin(); it != end(); it++)
					_alloc.destroy(&(*it));
				_alloc.deallocate(_array, _capacity);
			}

			// = operator overload
			vector operator=(const vector &src)
			{
				if (this != &src)
				{
					this->~vector();
					_size = src._size;
					if (src._size > _capacity)
						_capacity = src._size;
					_array = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&_array[i], src._array[i]);
				}
				return *this;
			}

			// begin, end, rbegin, rend
			iterator begin() { return iterator(_array); }
			const_iterator begin() const { return const_iterator(_array); }

			iterator end() { return iterator(_array + _size); }
			const_iterator end() const { return const_iterator(_array + _size); }

			reverse_iterator rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

			reverse_iterator rend() { return iterator(begin()); }
			const_reverse_iterator rend() const { return const_iterator(begin()); }

			// size, max_size, resize, capacity, empty, reserve
			size_type size() const { return _size; }

			size_type max_size() const { return _alloc.max_size(); }

			void resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					while (n < _size)
						_alloc.destroy(&_array[--_size]);
				}
				else
				{
					if (n > _capacity * 2)
						reserve(n);
					else if (n > _capacity)
						reserve(_capacity * 2);
					while (_size != n)
						push_back(val);

				}
			}

			size_type capacity() const { return _capacity; }

			bool empty() const
			{
				if (this->_size == 0)
					return true;
				return false;
			}

			void reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
				if (n > _capacity)
					reAlloc(n);
			}

			// operator[], at, front, back
			reference operator[] (size_type n) { return _array[n]; }
			const_reference operator[] (size_type n) const { return _array[n]; }

			reference at (size_type n)
			{
				if (n >= this->_size)
					throw std::out_of_range("vector");
				return _array[n];
			}
			const_reference at (size_type n) const
			{
				if (n > this->_size)
					throw std::out_of_range("vector");
				return _array[n];
			}

			reference front() { return _array[0]; }
			const_reference front() const { return _array[0]; }

			reference back() { return _array[_size - 1]; }
			const_reference back() const { return _array[_size - 1]; }

			// assign, push_back, pop_back, insert, erase, swap, clear
			// range
			template <class InputIterator>
			void assign (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
			{
				difference_type len = 0;

				for (InputIterator tmp = first; tmp != last; tmp++, len++);
				if (static_cast<size_type>(len) > _capacity)
				{
					this->~vector();
					_capacity = static_cast<size_type>(len);
					_size = 0;
					_array = _alloc.allocate(_capacity);
					while (first != last)
						_alloc.construct(&_array[_size++], *first++);
				}
				else
				{
					clear();
					while (first != last)
						_alloc.construct(&_array[_size++], *first++);
				}
			}

			// fill
			void assign (size_type n, const value_type& val)
			{
				if (n > _capacity)
				{
					this->~vector();
					_capacity = n;
					_size = n;
					_array = _alloc.allocate(_capacity);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&_array[i], val);
				}
				else
				{
					clear();
					while (_size < n)
						_alloc.construct(&_array[_size++], val);
				}
			}

			void push_back (const value_type& val)
			{
				if (_size == _capacity)
					resize(this->_size + 1, val);
				else
					_alloc.construct(&_array[_size++], val);
			}

			void pop_back()
			{
				_alloc.destroy(&_array[--_size]);
			}

			// single element
			iterator insert (iterator position, const value_type& val)
			{
				difference_type idx = position - begin();

				insert(position, 1, val);
				return (iterator(this->begin() + idx));
			}

			// fill
			void insert (iterator position, size_type n, const value_type& val)
			{
				difference_type const pos_diff = position - begin();
				difference_type const old_end_diff = end() - begin();
				iterator old_end, new_end;

				resize(this->_size + n);
				new_end = end();
				position = begin() + pos_diff;
				old_end = begin() + old_end_diff;
				while (old_end != position)
					*--new_end = *--old_end;
				while (n-- > 0)
					*position++ = val;
			}

			// range
			template <class InputIterator>
			void insert (iterator position, InputIterator first, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type last)
			{
				difference_type n = 0;
				difference_type const pos_diff = position - begin();
				difference_type const old_end_diff = end() - begin();
				iterator old_end, new_end;

				for (InputIterator tmp = first; tmp != last; tmp++, n++);
				resize(_size + n);
				new_end = end();
				position = begin() + pos_diff;
				old_end = begin() + old_end_diff;
				while (old_end != position)
					*--new_end = *--old_end;
				while (first != last)
					*position++ = *first++;
			}

			iterator erase (iterator position)
			{
				_alloc.destroy(&*position);

				for (iterator it = position; it + 1 != end(); it++)
				{
					_alloc.construct(&*it, *(it + 1));
					_alloc.destroy(&*it + 1);
				}
				_size--;

				return position;
			}

			iterator erase (iterator first, iterator last)
			{
				difference_type diff = last - first;
				for (iterator it = first; it != last; it++)
					_alloc.destroy(&*it);
				for (iterator it = first; it + diff != end(); it++)
				{
					_alloc.construct(&*it, *(it + diff));
					_alloc.destroy(&*(it + diff));
				}
				_size -= diff;
				return first;
			}

			void swap (vector& x)
			{
				vector tmp;
				tmp.swap_content(x);
				x.swap_content(*this);
				this->swap_content(tmp);
			}

			void clear()
			{
				while (!empty())
					pop_back();
			}
			// get_allocator
			allocator_type get_allocator() const
			{
				return _alloc;
			}

		private:
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			pointer			_array;

			void reAlloc(size_type n)
			{
				pointer tmp = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&tmp[i], _array[i]);
				this->~vector();

				_array = tmp;
				_capacity = n;
			}

			void swap_content(vector& x)
			{
				_size = x._size;
				_alloc = x._alloc;
				_capacity = x._capacity;
				_array = x._array;

				x._array = NULL;
				x._size = 0;
				x._capacity = 0;
			}
	};
	// relational operators: ==, !=, <, <=, >, >=
	template<class T, class A>
	bool operator==(const vector<T, A> &lhs, const vector<T, A> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<class T, class A>
	bool operator!=(const vector<T, A> &lhs, const vector<T, A> &rhs)
	{
		return !(rhs == lhs);
	}

	template<class T, class A>
	bool operator<(const vector<T, A> &lhs, const vector<T, A> &rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T, class A>
	bool operator<=(const vector<T, A> &lhs, const vector<T, A> &rhs)
	{
		return !(rhs < lhs);
	}

	template<class T, class A>
	bool operator>(const vector<T, A> &lhs, const vector<T, A> &rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class A>
	bool operator>=(const vector<T, A> &lhs, const vector<T, A> &rhs)
	{
		return !(lhs < rhs);
	}

	// swap
	template<class T, class A>
	void swap(vector<T, A>& lhs, vector<T, A>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
