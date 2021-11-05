#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <functional>
# include <iostream>

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

		value_type data;

		struct Node *parent;
		struct Node *left;
		struct Node *right;

		Color color;

		Node(value_type data, Node* parent, Node* left, Node* right, Color color): data(data), parent(parent), left(left), right(right), color(color) {}
	};

	template <class Key, class Value, class KeyOfValue, class Compare = std::less<Key>, class Alloc = std::allocator<Node<Value> > >
	class RBTree
	{

		public:
			typedef Key					key_type;
			typedef Value				value_type;
			typedef Compare				value_compare;
			typedef Alloc				allocator_type;

			typedef Node<value_type>	node_type;
			typedef Node<value_type>*	node_ptr;

			typedef std::size_t			size_type;

		private:
			node_ptr		_root;
			node_ptr		_nil;
			value_compare	_comp;
			allocator_type	_alloc;
			size_type		_size;

		public:
			// constructor
			RBTree(const value_compare &comp = value_compare(), const allocator_type &alloc = allocator_type()): _comp(comp), _alloc(alloc), _size(0)
			{
				_nil = _alloc.allocate(1);
				_alloc.construct(_nil, node_type(value_type(), NULL, NULL, NULL, BLACK));
				_root = _nil;
			}

			// destructor
			~RBTree()
			{
				clearRecursive(_root);
				_root = _nil;
				_alloc.destroy(_nil);
				_alloc.deallocate(_nil, 1);
			}

			node_ptr getRoot() const
			{
				return (this->_root);
			}

			node_ptr getNil() const
			{
				return (this->_nil);
			}

			size_type size() const { return _size; }

		    size_type max_size() const { return _alloc.max_size(); }

			node_ptr min() const
			{
				node_ptr node = _root;
				if (_root == _nil)
					return _root;
				while (node->left != _nil)
					node = node->left;
				return node;
			}

			node_ptr max() const
			{
				node_ptr node = _root;
				if (_root == _nil)
					return _root;

				while (node->right != _nil)
					node = node->right;
				return node;
			}

			node_ptr min(node_ptr node) const
			{
				if (node == _nil)
					return _root;

				while (node->left != _nil)
					node = node->left;
				return node;
			}

			node_ptr max(node_ptr node) const
			{
				if (node == _nil)
					return _root;

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
				if (x->parent == NULL)
					this->_root = y;
				else if (x == x->parent->left) // see if x was a left or right child to replace it by y
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x; // x become y left child
				x->parent = y;
			}

			// right rotation
			void right_rotation(node_ptr x)
			{
				node_ptr y = x->left; // get y (x left child)

				x->left = y->right; // y old right child is now x new left child
				if (y->right != _nil)
					y->right->parent = x;
				y->parent = x->parent; // x old parent is now y new parent
				if (x->parent == NULL)
					this->_root = y;
				else if (x == x->parent->right) // see if x was a right or left child to replace it by y
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x; // x become y right child
				x->parent = y;
			}

			node_ptr successor(node_ptr x)
			{
				// if the right subtree is not null the successor is the leftmost node in the right subtree
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
			bool insert(const value_type& data)
			{
				node_ptr node;
				node = _alloc.allocate(1);
				_alloc.construct(node, node_type(data, NULL, _nil, _nil, RED));

				node_ptr y = NULL;
				node_ptr x = this->_root;

				while (x != _nil)
				{
					y = x;
					if (_comp(KeyOfValue()(node->data), KeyOfValue()(x->data)))
						x = x->left;
					else if (_comp(KeyOfValue()(x->data), KeyOfValue()(node->data)))
						x = x->right;
					else
					{
						_alloc.destroy(node);
						_alloc.deallocate(node, 1);
						return false;
					}
				}
				node->parent = y;
				if (y == NULL)
					this->_root = node;
				else if (_comp(KeyOfValue()(node->data), KeyOfValue()(y->data)))
					y->left = node;
				else
					y->right = node;
				this->_size++;
				if (node->parent == NULL)
				{
					node->color = BLACK;
					return true;
				}
				if (node->parent->parent == NULL)
					return true;
				fix_insert(node);
				return true;
			}

			bool deleteNode(const key_type& key)
			{
				return deleteNodeHelper(key);
			}

			node_ptr search(const key_type& key) const
			{
				return searchRecursive(this->_root, key);
			}

			void fix_insert(node_ptr node)
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

			void rbTransplant(node_ptr u, node_ptr v) // replaces u by v
			{
				if (u->parent == NULL)
					_root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}

			bool deleteNodeHelper(const key_type& key)
			{
				// find the node containing key
				node_ptr z, x, y;

				z = search(key);
				if (z == _nil)
					return false;

				y = z; // y saves the suppressed node's placement
				Color y_og_color = y->color;
				if (z->left == _nil) // z only had 1 child whitch is the right one so so it get's replaced by it's child
				{
					x = z->right; // x saves the right child's branch
					rbTransplant(z, z->right);
				}
				else if (z->right == _nil) //mirror case
				{
					x = z->left;
					rbTransplant(z, z->left);
				}
				else // suppressed node had 2 children and is replaced by the minimum of it's right branch
				{
					y = min(z->right); // search for the minimum in the right child's branch
					y_og_color = y->color;
					x = y->right; // x saves the minimum's right branch
					if (y->parent == z) // the minimum is z->right
						x->parent = y;
					else
					{
						rbTransplant(y, y->right); // replaces the minimum by it's right branch
						y->right = z->right; // set the new z's right side
						y->right->parent = y;
					}
					rbTransplant(z, y); // replace z by the correct value whitch is y and maintain the tree as a good search tree
					y->left = z->left; // set the new z's left side
					y->left->parent = y;
					y->color = z->color; // we keep the old z color
				}
				_alloc.destroy(z);
				_alloc.deallocate(z, 1);
				_size--;
				if (y_og_color == BLACK) // fix the lost black color on x
					fixDelete(x);
				return true;
			}

			// fix the rb tree modified by the delete operation
			void fixDelete(node_ptr x)
			{
				node_ptr w;

				while (x != this->_root && x->color == BLACK)
				{
					if (x == x->parent->left) // if x is the left child
					{
						w = x->parent->right; // w is x's right brother
						if (w->color == RED)
						{
							w->color = BLACK;
							x->parent->color = RED;
							left_rotation(x->parent); // new parent is w, old parent p became w's left child, p is still x's parent and x->parent->right bacame old w->left
							w = x->parent->right;
						}

						if (w->left->color == BLACK && w->right->color == BLACK)
						{
							w->color = RED;
							x = x->parent;
						}
						else // at least one child is RED
						{
							if (w->right->color == BLACK) // left child is RED
							{
								w->left->color = BLACK;
								w->color = RED;
								right_rotation(w);
								w = x->parent->right;
							}
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->right->color = BLACK;
							left_rotation(x->parent);
							x = _root;
						}
					}
					else // mirror case
					{
						w = x->parent->left;
						if (w->color == RED)
						{
							w->color = BLACK;
							x->parent->color = RED;
							right_rotation(x->parent);
							w = x->parent->left;
						}

						if (w->left->color == BLACK && w->right->color == BLACK)
						{
							w->color = RED;
							x = x->parent;
						}
						else
						{
							if (w->left->color == BLACK)
							{
								w->right->color = BLACK;
								w->color = RED;
								left_rotation(w);
								w = x->parent->left;
							}
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->left->color = BLACK;
							right_rotation(x->parent);
							x = _root;
						}
					}
				}
				x->color = BLACK; // root is BLACK
			}

			node_ptr searchRecursive(node_ptr node, const key_type& key) const
			{
				if (node == _nil)
					return _nil;
				else if (key == KeyOfValue()(node->data))
					return node;
				if (node != _nil)
				{
					if (_comp(key, KeyOfValue()(node->data)))
						return searchRecursive(node->left, key);
					return searchRecursive(node->right, key);
				}
				return _nil;
			}

			void clearRecursive(node_ptr const &node)
			{
				// Base case of recursion
				if (node == _nil)
					return ;

				// Clear all nodes to the left and right of it
				clearRecursive(node->left);
				clearRecursive(node->right);

				// Clear the node itself
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);

				_size--;
			}

			void printHelper(node_ptr root, std::string indent, bool last)
			{
				// print the tree structure on the screen
				if (root != _nil)
				{
					std::cout << indent;
					if (last)
					{
						std::cout << "R----";
						indent += "     ";
					}
					else
					{
						std::cout << "L----";
						indent += "|    ";
					}
					std::string sColor = root->color?"RED":"BLACK";
					std::cout << root->data.first << "(" << sColor << ")" << std::endl;
					printHelper(root->left, indent, false);
					printHelper(root->right, indent, true);
				}
			}

			void prettyPrint()
			{
				if (_root) {
					printHelper(this->_root, "", true);
				}
			}

			void swap (RBTree& x)
			{
				node_ptr		tmp_root = _root;
				this->_root = x._root;
				x._root = tmp_root;

				node_ptr		tmp_nil = _nil;
				this->_nil = x._nil;
				x._nil = tmp_nil;

				size_type		tmp_size = _size;
				this->_size = x._size;
				x._size = tmp_size;
			}

	};
}

#endif
