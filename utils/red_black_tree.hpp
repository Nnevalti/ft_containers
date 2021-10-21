#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "red_black_node.hpp"

namespace ft
{
	template <class T, class Compare = std::less<Key>>
	class rb_Tree
	{
		public:
			typedef T				value_type;
			typedef rb_Node<T>		node_type;
			typedef std::size_t		size_type;

			node_type				*root;
			node_type				*nil;
			size_type				size;

			// constructor
			rb_Tree(): nil(node_type(NULL, BLACK)), size(0), root(nil) {}
			// copy
			rb_Tree(const rb_Tree &src): root(src.root), size(src.size), nil(src.nil) {}

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
			rb_Node *BST_insert(value_type *new_data)
			{
				node_type *tmp = root;
				node_type *parent;

				while (tmp != nil)
				{
					parent = tmp;
					if (Compare(new_data, tmp->data))
						tmp = tmp->left;
					else
						tmp = tmp->right;
				}

				node_type *new_node(new_data, RED, parent, nil, nil);
				if (Compare(new_data, parent->data))
					parent->left = new_node;
				else
					parent->right = new_node;
				return new_node;
			}

			void fix_insert(node_type *k)
			{
				node_type *u;

				while (k->parent->color == RED)
				{
					u = k->parent->get_sibling();
					if (u->color == RED)
					{
						// case 3.1
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else if (k->parent->is_a_right_child())
					{
						if (k == k->parent->left)
						{
							// case 3.2.2
							k = k->parent;
							right_rotation(k);
						}
						// case 3.2.1
						k->parent->color = 0;
						k->parent->parent->color = 1;
						left_rotation(k->parent->parent);
					}
					else if (k->parent->is_a_left_child())
					{
						if (k == k->parent->right)
						{
							// mirror case 3.2.2
							k = k->parent;
							left_rotation(k);
						}
						// mirror case 3.2.1
						k->parent->color = 0;
						k->parent->parent->color = 1;
						right_rotation(k->parent->parent);
					}
					if (k == root) {
						break;
					}
				}
				root->color = BLACK;
			}

			void insert(value_type &new_data)
			{
				// 1/ root is nil new node K is inserted as root and colored black
				// 2/ Parent is black nothing to do
				// 3/ Parent is red check whether uncle is red or black
					// 3.1/ if Uncle is red
						// Grand parent become red, uncle become black, Parent become black
					// 3.2/ if Uncle is black
						// 3.2.1/ Parent is a right child, K is a right child
							// Left rotation on Grand parent, G become K Sibling, Parent set to black and Sibling set to red
						// 3.2.2/ Parent is a right child, K is a left child
							// Right rotation on Parent and reuse 3.2.1 step to fix the tree
						// 3.2.3/ Parent is a left child, K is a left child (symmetry of 3.2.1)
							// Right rotation on Grand parent, G become K Sibling, Parent set to black and Sibling set to red
						// 3.2.4/ Parent is left child, K is right child (symmetry of 3.2.2)
							// Left rotation on Parent and reuse 3.2.3 step to fix the tree

				if (root == nil)
				{
					node_type *new_root(new_data, BLACK, nil, nil, nil);
					root = new_root;
					return ;
				}
				// classic BST insertion
				node_type *k = BST_insert(new_data);
				if (k->parent->parent == nil)
					return ;
				fix_insert(k);
			}

			// remove
			// left rotation
			void left_rotation(node_type *x)
			{
				// get y (x right child)
				node_type *y = x->right;

				// y left child is now x right child
				x->right = y->left;
				if (y->left != nil)
				{
					y->left->parent = x;
				}
				// x parent is now y parent
				y->parent = x->parent;
				if (x->parent == nil)
				{
					this->root = y;
				}
				else if (x->is_a_left_child())
				{
					x->parent->left = y;
				}
				else
				{
					x->parent->right = y;
				}
				// x become y left child
				y->left = x;
				x->parent = y;
			}

			// right rotation
			void right_rotation(node_type *x)
			{
				// get y (x left child)
				node_type *y = x->left;

				// y right child is now x left child
				x->left = y->right;
				if (y->right != nil)
				{
					y->right->parent = x;
				}
				// x parent is now y parent
				y->parent = x->parent;
				if (x->parent == nil)
				{
					this->root = y;
				}
				else if (x->is_a_right_child())
				{
					x->parent->right = y;
				}
				else
				{
					x->parent->left = y;
				}
				// x become y right child
				y->right = x;
				x->parent = y;
			}

			void recolor(node_type *node)
			{
				if (node->color == BLACK)
					node->color = RED;
				else
					node->color = BLACK;
			}

	}
}

#endif
