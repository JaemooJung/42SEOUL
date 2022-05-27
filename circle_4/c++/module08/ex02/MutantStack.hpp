#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}

		reverse_iterator rbegin() {
			return this->c.rbegin();
		}

		reverse_iterator rend() {
			return this->c.rend();
		}

		const_iterator cbegin() const {
			return this->c.begin();
		}

		const_iterator cend() const {
			return this->c.end();
		}

		const_reverse_iterator crbegin() const {
			return this->c.rbegin();
		}

		const_reverse_iterator crend() const {
			return this->c.rend();
		}

		MutantStack& operator=(const MutantStack& other) {
			std::stack<T>::operator=(other);
			return *this;
		}

		MutantStack() {

		}

		MutantStack(const MutantStack& other) {
			*this = other;
		}

		~MutantStack() {

		}
};

#endif // __MUTANTSTACK_H__