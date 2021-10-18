#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
	/*
	** ITERATOR_CATEGORY
	** Empty class to identify the category of the iterator
	*/
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_acces_iterator_tag : public bidirectional_iterator_tag {};

	/*
	** ITERATOR TRAITS
	** Traits class defining properties of iterators.
	** Useful link to understand iterator traits : https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
	*/
	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public:
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef ft::random_acces_iterator_tag			iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public:
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef const T*								pointer;
			typedef const T&								reference;
			typedef ft::random_acces_iterator_tag			iterator_category;
	};
}

#endif
