#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

// # include "red_black_node.hpp"

namespace ft
{

	enum Color
	{
		BLACK,
		RED
	};

	template <class T>
	struct Node
	{
		typedef	T value_type;

		struct Node *parent;
		struct Node *left;
		struct Node *right;

		value_type data;
		Color color;

		Node(value_type data, Node* parent, Node* left, Node* right,calor color): data(data), parent(parent), left(left), right(right), color(color) {}
	};

	template <class Key, class T, class Compare = std::less<T>, class Alloc = std::allocator<Node<T> > >
	class RBTree
	{
		public:
			typedef T					value_type;
			typedef Key					key_type;
			typedef Compare				Key_compare;
			typedef Alloc				allocator_type;

			typedef Node<value_type>	node_type;
			typedef Node<value_type>*	node_ptr;

			typedef std::size_t			size_type;

			// constructor
			RBTree(const Key_compare &comp = Key_compare(), const allocator_type &alloc = allocator_type()): _comp(comp), _alloc(alloc), _size(0)
			{
				_nil = _alloc.allocate(1);
				_alloc.construct(_nil, node_type(value_type(), NULL, NULL, NULL, BLACK));
				_root = _nil;
			}

			// destructor
			~RBTree() {}

			node_ptr getRoot()
			{
				return (this->_root);
			}

			node_ptr min(node_ptr node)
			{
				while (node->left != _nil)
					node = node->left;
				return node;
			}

			node_ptr max(node_ptr node)
			{
				while (node->right != _nil)
					node = node->right;
				return node;
			}

			// left rotation
			void left_rotation(node_ptr x)
			{
				node_ptr y = x->right; // get y (x right child)

				x->right = y->left; // y old left child is now x new right child
				if (y->left != _nil)
					y->left->parent = x;
				y->parent = x->parent; // x old parent is now y new parent
				if (x->parent == _nil)
					this->_root = y;
				else if (x == x->parent->left) // see if x was a left or right child to replace it by y
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x; // x become y left child
				x->parent = y;
			}

			// right rotation
			void right_rotation(node_ptr *x)
			{
				node_ptr *y = x->left; // get y (x left child)

				x->left = y->right; // y old right child is now x new left child
				if (y->right != _nil)
					y->right->parent = x;
				y->parent = x->parent; // x old parent is now y new parent
				if (x->parent == _nil)
					this->_root = y;
				else if (x == x->parent->right) // see if x was a right or left child to replace it by y
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x; // x become y right child
				x->parent = y;
			}

			void insert(node_ptr node)
			{
				// Different case :
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

				node_ptr y = NULL;
				node_ptr x = this->_root;

				while (x != _nil)
				{
					y = x;
					if (_comp(node->data, x->data)) // to finish
						x = x->left;
					else
						x = x->right;
				}
				node->parent = y;
				if (y == NULL)
					this->_root = node;
				else if (_comp(node->data, y->data))
					y->left = node;
				else
					y->right = node;
				if (node->parent == NULL)
				{
					node->color = BLACK;
					return ;
				}
				if (node->parent->parent == NULL)
					return ;
				fix_insert(node);
				_size++;
			}

			// remove node

			void fix_insert(node_type *node)
			{
				node_type *u;

				while (node->parent->color == RED)
				{
					if (node->parent == node->parent->parent->right) // where is uncle
						u = node->parent->parent->left;
					else
						u = node->parent->parent->right;
					if (u->color == RED)
					{
						// case 3.1
						u->color = BLACK;
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					}
					else if (node->parent == node->parent->parent->right) // is node parent a right child ?
					{
						if (node == node->parent->left) // is node a left child ?
						{
							// case 3.2.2
							node = node->parent;
							right_rotation(node);
						}
						// case 3.2.1
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						left_rotation(node->parent->parent);
					}
					else if (node->parent == node->parent->parent->left) // is node parent a left child ?
					{
						if (node == node->parent->right) // is node a right child ?
						{
							// mirror case 3.2.2
							node = node->parent;
							left_rotation(node);
						}
						// mirror case 3.2.1
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						right_rotation(node->parent->parent);
					}
					if (node == _root)
					{
						break;
					}
				}
				_root->color = BLACK;
			}

			node_ptr search(key_type key)
			{
				return searchRecursive(_root, key);
			}

			node_ptr searchRecursive(node_ptr node, key_type key)
			{
				if (node == _nil || key == node->data)
					return node;
				if (node != _nil)
				{
					if (key < node->data) // to finish
						return searchRecursive(node->left, key);
					return searchRecursive(node->right, key);
				}
			}

			node_ptr successor(node_ptr x)
			{
				// if the right subtree is not null the successor is the leftmost node in the sright subtree
				if (x->right != _nil)
				{
					return min(x->right);
				}
				// else it is the lowest ancestor of x whose left child is also an ancestor of x
				node_ptr y = x->parent;
				while (y != _nil && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			node_ptr predecessor(node_ptr x)
			{
				// if the left subtree is not null the predecessor is the rightmost node in the left subtree
				if (x->left != _nil)
				{
					return max(x->left);
				}
				node_ptr y = x->parent;
				while (y != _nil && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}

			protected:
				node_ptr		_root;
				node_ptr		_nil;
				Key_compare		_comp;
				allocator_type	_alloc;
				size_type		_size;
	};
}

#endif
