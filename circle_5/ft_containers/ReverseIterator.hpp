#ifndef __REVERSEITERATOR_H__
#define __REVERSEITERATOR_H__

#include "Iterator.hpp"

namespace ft {
	template<typename Iterator>
	class reverse_iterator {

		public:
			typedef Iterator	iterator_type;
			typedef typename	ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename	ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename	ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename	ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename	ft::iterator_traits<Iterator>::reference			reference;

		private:
			iterator_type	_iter;

		public:

			// constructors ===================================================
			reverse_iterator() : _iter() {}
			template <typename U>
			reverse_iterator(const reverse_iterator<U>& it) : _iter(it.base()) {}
			explicit reverse_iterator(const iterator_type& it) : _iter(it) {}
			virtual ~reverse_iterator() {}
			// =================================================================

			// base ===========================================================
			iterator_type base() const {
				return (_iter);
			}
			// =================================================================

			// operator overloads ==============================================
			template <typename U>
			reverse_iterator& operator=(const reverse_iterator<U>& it) {
				_iter = it.base();
				return (*this);
			}
			reverse_iterator& operator++() {
				--_iter;
				return (*this);
			}
			reverse_iterator operator++(int) {
				reverse_iterator tmp(*this);
				--_iter;
				return (tmp);
			}
			reverse_iterator& operator--() {
				++_iter;
				return (*this);
			}
			reverse_iterator operator--(int) {
				reverse_iterator tmp(*this);
				++_iter;
				return (tmp);
			}
			reverse_iterator operator+(difference_type n) {
				reverse_iterator tmp(*this);
				tmp._iter -= n;
				return (tmp);
			}
			reverse_iterator operator-(difference_type n) {
				reverse_iterator tmp(*this);
				tmp._iter += n;
				return (tmp);
			}
			difference_type operator-(reverse_iterator other) {
				return (other._iter - _iter);
			}
			reverse_iterator& operator+=(difference_type n) {
				_iter -= n;
				return (*this);
			}
			reverse_iterator& operator-=(difference_type n) {
				_iter += n;
				return (*this);
			}
			reference operator[](difference_type n) {
				return (*(_iter - n - 1));
			}
			const reference operator[](difference_type n) const {
				return (*(_iter - n - 1));
			}
			reference operator*() {
				iterator_type tmp = _iter;
				return (*(--tmp));
			}
			const reference operator*() const {
				iterator_type tmp = _iter;
				return (*(--tmp));
			}
			pointer operator->() {
				iterator_type tmp = _iter;
				return (&(*(--tmp)));
			}
			// =================================================================

	};
	
	template <typename ITER>
	bool operator==(const reverse_iterator<ITER>& it1, const reverse_iterator<ITER>& it2) {
		return (it1.base() == it2.base());
	}
	template <typename ITER>
	bool operator!=(const reverse_iterator<ITER>& it1, const reverse_iterator<ITER>& it2) {
		return (it1.base() != it2.base());
	}
	template <typename ITER>
	bool operator<(const reverse_iterator<ITER>& it1, const reverse_iterator<ITER>& it2) {
		return (it1.base() > it2.base());
	}
	template <typename ITER>
	bool operator<=(const reverse_iterator<ITER>& it1, const reverse_iterator<ITER>& it2) {
		return (!(it1 > it2));
	}
	template <typename ITER>
	bool operator>(const reverse_iterator<ITER>& it1, const reverse_iterator<ITER>& it2) {
		return (it1.base() < it2.base());
	}
	template <typename ITER>
	bool operator>=(const reverse_iterator<ITER>& it1, const reverse_iterator<ITER>& it2) {
		return (!(it1 < it2));
	}

	template <typename ITER1, typename ITER2>
	bool operator==(const reverse_iterator<ITER1>& it1, const reverse_iterator<ITER2>& it2) {
		return (it1.base() == it2.base());
	}
	template <typename ITER1, typename ITER2>
	bool operator!=(const reverse_iterator<ITER1>& it1, const reverse_iterator<ITER2>& it2) {
		return (it1.base() != it2.base());
	}
	template <typename ITER1, typename ITER2>
	bool operator<(const reverse_iterator<ITER1>& it1, const reverse_iterator<ITER2>& it2) {
		return (it1.base() > it2.base());
	}
	template <typename ITER1, typename ITER2>
	bool operator<=(const reverse_iterator<ITER1>& it1, const reverse_iterator<ITER2>& it2) {
		return (!(it1 > it2));
	}
	template <typename ITER1, typename ITER2>
	bool operator>(const reverse_iterator<ITER1>& it1, const reverse_iterator<ITER2>& it2) {
		return (it1.base() < it2.base());
	}
	template <typename ITER1, typename ITER2>
	bool operator>=(const reverse_iterator<ITER1>& it1, const reverse_iterator<ITER2>& it2) {
		return (!(it1 < it2));
	}

	template <typename ITER>
	reverse_iterator<ITER> operator+(typename reverse_iterator<ITER>::difference_type n, const reverse_iterator<ITER>& it) {
		return (it + n);
	}
	template <typename ITER>
	typename reverse_iterator<ITER>::difference_type operator-(const reverse_iterator<ITER>& it1, const reverse_iterator<ITER>& it2) {
		return (it2 - it1);
	}

} // namespace ft


#endif // __REVERSEITERATOR_H__