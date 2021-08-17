#ifndef ITERATOR_CATEGORY_HPP
# define ITERATOR_CATEGORY_HPP

namespace ft
{
	// Empty class to identify the category of the iterator
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_acces_iterator_tag : public bidirectional_iterator_tag {};
}

#endif
