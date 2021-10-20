#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "red_black_node.hpp"

namespace ft
{
	template <class T>
	class rb_Tree
	{
		public:
			typedef T				value_type;
			typedef rb_Node<T>		node_type;
			typedef std::size_t		size_type;

			node_type				*root;
			size_type				size;

			// constructor
			rb_Tree(): root(NULL), size(0) {}
			// copy
			rb_Tree(const rb_Tree &src): root(src.root), size(src.size) {}

			// destructor
			~rb_Tree() {}

			// copy operator
			rb_Tree operator=(const rb_Tree &lhs)
			{
				if (this != &src)
				{
					root = lhs.root;
					size = lhs.size;
				}
				return *this;
			}

			// search
			// insert
			// remove
			// left rotation
			// right rotation

	}
}

#endif
