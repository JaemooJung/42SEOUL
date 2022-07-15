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
			container_type _c;

		public:
			explicit stack(const container_type &ctnr = container_type())
			: _c(ctnr) {}

			~stack() {}

			bool empty() const {
				return _c.empty();
			}

			size_type size() const {
				return _c.size();
			}

			value_type &top() {
				return _c.back();
			}

			const value_type& top() const {
				return _c.back();
			}

			void push(const value_type &val) {
				_c.push_back(val);
			}

			void pop() {
				_c.pop_back();
			}


	};

}; // namespace ft

#endif // __STACK_H__
