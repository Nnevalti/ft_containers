#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "random_acces_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::alloc<T> >
	class Vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef allocator_type::reference					reference;
			typedef allocator_type::const_reference				const_reference;
			typedef allocator_type::pointer						pointer;
			typedef allocator_type::const_pointer				const_pointer;
			typedef randomAccessIterator<T>						iterator;
			typedef randomAccessIterator<T, const T*, const T&>	const_iterator;
			typedef reverse_iterator<iterator>					reverse_iterator;
			typedef reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef size_t										size_type;

			explicit vector (const allocator_type& alloc = allocator_type())
			: _size(0), _capacity(0), _alloc(alloc), _array(NULL) {}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _size(n), _capacity(n), _alloc(alloc)
			{
				_array = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
					_array[i] = val;
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

			vector (const vector& x);


		private:
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
			pointer			_array;

			void reAlloc(size_type n)
			{
				pointer tmp = _alloc.allocate(n, _array);
				for (int i = 0; i < _size; i++)
					tmp[i] = _array[i];
				_alloc.deallocate(_array);
				_array = tmp;
				_capacity = n;
			}
	};
}

#endif
