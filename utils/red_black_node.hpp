#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{
	enum Color
	{
		BLACK,
		RED
	};

	template <Class T>
	class rb_Node
	{
		public:
			typedef T		value_type;
			value_type		data;
			rb_Node			*parent;
			rb_Node			*left;
			rb_Node			*right;
			Color			color;

			// CONSTRUCTOR
			// default
			explicit rb_Node(const value_type &val = value_type(), Color col = RED, rb_Node *parent = NULL, rb_Node *left = NULL, rb_Node *right = NULL): data(val), parent(parent), left(left), righ(right), color(col) {}

			// copy
			rb_Node(cont rb_Node &src): data(src.data), parent(src.parent), left(src.left), right(src.right), color(RED) {}

			// DESTRUCTOR
			~rb_Node() {}

			// = operator overload
			rb_Node operator=(const rb_Node &src)
			{
				if (this != &src)
				{
					data = src.data;
					parent = src.parent;
					left = src.left;
					right = src.right;
					color = src.color;
				}
			}

			// comparison operator
			bool operator==(const node &lhs) { return data == lhs.data; }
			bool operator!=(const node &lhs) { return data != lhs.data; }
			bool operator<(const node &lhs) { return data < lhs.data; }
			bool operator>(const node &lhs) { return data > lhs.data; }
			bool operator<=(const node &lhs) { return data <= lhs.data; }
			bool operator>=(const node &lhs) { return data >= lhs.data; }

			const bool is_a_right_child() const { return parent != NULL && parent->right == this; }
			const bool is_a_left_child() const { return parent != NULL && parent->left == this; }
			rb_Node *min() { return left == NULL ? this : left->min(); }
			rb_Node *max() { return right == NULL ? this : right->max(); }

			rb_Node *get_sibling()
			{
				if (parent == NULL)
					return NULL;
				return is_a_left_child() ? parent->right : parent->left;
			}

			rb_Node *getNextNode()
			{
				if (right != NULL)
					return right->min();
				if (is_a_left_child())
					return parent;

				rb_Node *tmp(this);
				while (tmp != NULL && tmp->is_a_right_child())
				{
					tmp = tmp->parent;
				}
				if (tmp != NULL)
					return tmp->parent;
				return NULL;
			}

			rb_Node *getPreviousNode()
			{
				if (left != NULL)
					return left->max();
				if (is_a_right_child())
					return parent;

				rb_Node *tmp(this);
				while (tmp != NULL && tmp->is_a_left_child())
				{
					tmp = tmp->parent;
				}
				if (tmp != NULL)
					return tmp->parent;
				return NULL;
			}

	}
}

#endif
