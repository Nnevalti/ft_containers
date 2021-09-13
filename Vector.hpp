#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
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
				size_type diff = 0;
				for (InputIterator it = first; it != last; it++)
				{
					diff++;
				}
				_size = diff;
				_capacity = _size;
				_array = _alloc.allocate(_capacity);
				for (int i = 0; first != last; i++, first++)
					_alloc.construct(&_array[i], *first);
			}

			// copy
			vector (const vector& x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
			{
				_array = _alloc.allocate(_capacity);
				for (int i = 0; i < _size; i++)
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
				_size = src._size;
				_capacity = src._capacity;
				_alloc = src._alloc;
				_array = _alloc.allocate(_capacity);
				for (int i = 0; i < _size; i++)
					_alloc.construct(&_array[i], src._array[i]);
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
					while (_size != n)
						pop_back();
				if (n > _size)
					while (_size != n)
						push_back(val);
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
			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last)
			// {
			// }
			
			// fill
			// void assign (size_type n, const value_type& val)
			// {
			// }

			void push_back (const value_type& val)
			{
				if (_size + 1 > _capacity)
					reAlloc(!_capacity ? 1 : _capacity * 2);
				_alloc.construct(&_array[_size++], val);
			}

			void pop_back()
			{
				if (_size)
				{
					_alloc.destroy(&_array[_size - 1]);
					_size--;
				}
			}
			// iterator insert (iterator position, const value_type& val);
			// void insert (iterator position, size_type n, const value_type& val);
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);

			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);

			void swap (vector& x);

			void clear()
			{
				while (_size)
					pop_back();
			}
			// get_allocator

		private:
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			pointer			_array;

			void reAlloc(size_type n)
			{
				pointer tmp = _alloc.allocate(n);
				for (int i = 0; i < _size; i++)
					_alloc.construct(&tmp[i], _array[i]);
				this->~vector();

				_array = tmp;
				_capacity = n;
			}
	};
}

// relational operators: ==, !=, <, <=, >, >=
// swap

#endif
