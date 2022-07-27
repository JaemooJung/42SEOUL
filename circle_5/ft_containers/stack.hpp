#ifndef __STACK_HPP__
#define __STACK_HPP__

#include "vector.hpp"

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef Container							container_type;
			typedef typename container_type::value_type	value_type;
			typedef typename container_type::size_type	size_type;

		protected:
			container_type c;

		public:
			explicit stack(const container_type &ctnr = container_type())
			: c(ctnr) {}

			~stack() {}

			bool empty() const {
				return c.empty();
			}

			size_type size() const {
				return c.size();
			}

			value_type &top() {
				return c.back();
			}

			const value_type& top() const {
				return c.back();
			}

			void push(const value_type &val) {
				c.push_back(val);
			}

			void pop() {
				c.pop_back();
			}

			template <class Tn, class Containern>
				friend bool operator==(const stack<Tn, Containern> &lhs, const stack<Tn, Containern> &rhs);
			template <class Tn, class Containern>
				friend bool operator<(const stack<Tn, Containern> &lhs, const stack<Tn, Containern> &rhs);
	};

	template <class T, class Containern>
	bool operator==(const stack<T, Containern> &lhs, const stack<T, Containern> &rhs) {
		return lhs.c == rhs.c;
	}

	template <class T, class Containern>
	bool operator!=(const stack<T, Containern> &lhs, const stack<T, Containern> &rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Containern>
	bool operator<(const stack<T, Containern> &lhs, const stack<T, Containern> &rhs) {
		return lhs.c < rhs.c;
	}
	
	template <class T, class Containern>
	bool operator>(const stack<T, Containern> &lhs, const stack<T, Containern> &rhs) {
		return rhs < lhs;
	}

	template <class T, class Containern>
	bool operator<=(const stack<T, Containern> &lhs, const stack<T, Containern> &rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Containern>
	bool operator>=(const stack<T, Containern> &lhs, const stack<T, Containern> &rhs) {
		return !(lhs < rhs);
	}

}; // namespace ft

#endif // __STACK_H__
