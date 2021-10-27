#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T				value_type;
			typedef Container		container_type;
			typedef std::size_t		size_type;

			// CONSTRUCTOR
			// default
			explicit stack(const container_type &cont = container_type()) : _c(cont) {}

			// copy
			stack(const stack& src): _c(src._c) {}

			// DESTRUCTOR
			~stack() {}

			// = operator overload
			stack operator=(const stack &lhs)
			{
				if (this != &lhs)
				{
					_c = lhs._c;
				}
				return *this;
			}

			bool empty() const
			{
				return _c.empty();
			}

			size_type size() const
			{
				return _c.size();
			}

			value_type &top()
			{
				return _c.back();
			}

			const value_type &top() const
			{
				return _c.back();
			}

			void push(const value_type &val)
			{
				_c.push_back(val);
			}

			void pop()
			{
				_c.pop_back();
			}

			/* _c is a private member so to access it from the non members comparison functions we need to make them friend */
			template <class U, class ctnr>
			friend bool operator==(const stack<U,ctnr> &lhs, const stack<U,ctnr> &rhs);

			template <class U, class ctnr>
			friend bool operator!=(const stack<U,ctnr> &lhs, const stack<U,ctnr> &rhs);

			template <class U, class ctnr>
			friend bool operator<(const stack<U,ctnr> &lhs, const stack<U,ctnr> &rhs);

			template <class U, class ctnr>
			friend bool operator<=(const stack<U,ctnr> &lhs, const stack<U,ctnr> &rhs);

			template <class U, class ctnr>
			friend bool operator>(const stack<U,ctnr> &lhs, const stack<U,ctnr> &rhs);

			template <class U, class ctnr>
			friend bool operator>=(const stack<U,ctnr> &lhs, const stack<U,ctnr> &rhs);

		private:
			container_type _c;

	};

	template <class T, class Container>
	bool operator==(const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{
		return (lhs._c == rhs._c);
	}

	template <class T, class Container>
	bool operator!=(const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{
		return (lhs._c != rhs._c);
	}

	template <class T, class Container>
	bool operator<(const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{
		return (lhs._c < rhs._c);
	}

	template <class T, class Container>
	bool operator<=(const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{
		return (lhs._c <= rhs._c);
	}

	template <class T, class Container>
	bool operator>(const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{
		return (lhs._c > rhs._c);
	}

	template <class T, class Container>
	bool operator>=(const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{
		return (lhs._c >= rhs._c);
	}
}

#endif
