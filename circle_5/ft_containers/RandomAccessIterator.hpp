#ifndef __RANDOMACCESSITERATOR_H__
#define __RANDOMACCESSITERATOR_H__

#include "Iterator.hpp"

namespace ft {
	
	template <typename T>
	class random_access_iterator : public ft::iterator<random_access_iterator_tag, T> {

		public:
			typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;

		private:
			pointer	_ptr;

		public:
			// constructors ===================================================
			random_access_iterator() : _ptr(NULL) {}
			random_access_iterator(pointer ptr) : _ptr(ptr) {}
			random_access_iterator(const random_access_iterator& it) : _ptr(it._ptr) {}
			virtual ~random_access_iterator() {}
			// =================================================================

			// operator overloads ==============================================
			random_access_iterator& operator=(const random_access_iterator& it) {
				if (this != &it)
					_ptr = it._ptr;
				return (*this);
			}
			random_access_iterator& operator++() {
				++_ptr;
				return (*this);
			}
			random_access_iterator& operator--() {
				--_ptr;
				return (*this);
			}
			random_access_iterator operator++(int) {
				random_access_iterator tmp(*this);
				++_ptr;
				return (tmp);
			}
			random_access_iterator operator--(int) {
				random_access_iterator tmp(*this);
				--_ptr;
				return (tmp);
			}
			random_access_iterator operator+(difference_type n) {
				random_access_iterator tmp(*this);
				tmp._ptr += n;
				return (tmp);
			}
			random_access_iterator operator-(difference_type n) {
				random_access_iterator tmp(*this);
				tmp._ptr -= n;
				return (tmp);
			}
			random_access_iterator& operator+=(difference_type n) {
				_ptr += n;
				return (*this);
			}
			random_access_iterator& operator-=(difference_type n) {
				_ptr -= n;
				return (*this);
			}
			reference operator*() const { return (*_ptr); }
			const reference operator*() { return (*_ptr); }
			pointer operator->() const { return (_ptr); }
			reference operator[](difference_type n) { return (_ptr[n]); }
			const reference operator[](difference_type n) const { return (_ptr[n]); }

			// =================================================================

			pointer base() const { return _ptr; }
			operator random_access_iterator<const T> () const { return (random_access_iterator<const T>(_ptr)); }
	};
	
	template <typename T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& it){
		random_access_iterator<T> tmp = it;
		return (tmp + n);
	}

	template <typename ITER>
	typename ft::random_access_iterator<ITER>::difference_type operator-(const random_access_iterator<ITER>& it1, const random_access_iterator<ITER>& it2) {
		return (it1.base() - it2.base());
	}

	template <typename ITER1, typename ITER2>
	typename ft::random_access_iterator<ITER1> operator-(const random_access_iterator<ITER1>& it1, const random_access_iterator<ITER2>& it2) {
		return (it1.base() - it2.base());
	}

	template <typename ITER>
	bool operator==(const random_access_iterator<ITER>& it1, const random_access_iterator<ITER>& it2) {
		return (it1.base() == it2.base());
	}

	template <typename ITER>
	bool operator!=(const random_access_iterator<ITER>& it1, const random_access_iterator<ITER>& it2) {
		return (it1.base() != it2.base());
	}

	template <typename ITER>
	bool operator<(const random_access_iterator<ITER>& it1, const random_access_iterator<ITER>& it2) {
		return (it1.base() < it2.base());
	}

	template <typename ITER>
	bool operator>(const random_access_iterator<ITER>& it1, const random_access_iterator<ITER>& it2) {
		return (it1.base() > it2.base());
	}

	template <typename ITER>
	bool operator<=(const random_access_iterator<ITER>& it1, const random_access_iterator<ITER>& it2) {
		return (!(it2 < it1));
	}

	template <typename ITER>
	bool operator>=(const random_access_iterator<ITER>& it1, const random_access_iterator<ITER>& it2) {
		return (!(it1 < it2));
	}

	template <typename ITER1, typename ITER2>
	bool operator==(const random_access_iterator<ITER1>& it1, const random_access_iterator<ITER2>& it2) {
		return (it1.base() == it2.base());
	}

	template <typename ITER1, typename ITER2>
	bool operator!=(const random_access_iterator<ITER1>& it1, const random_access_iterator<ITER2>& it2) {
		return (it1.base() != it2.base());
	}

	template <typename ITER1, typename ITER2>
	bool operator<(const random_access_iterator<ITER1>& it1, const random_access_iterator<ITER2>& it2) {
		return (it1.base() < it2.base());
	}

	template <typename ITER1, typename ITER2>
	bool operator>(const random_access_iterator<ITER1>& it1, const random_access_iterator<ITER2>& it2) {
		return (it1.base() > it2.base());
	}

	template <typename ITER1, typename ITER2>
	bool operator<=(const random_access_iterator<ITER1>& it1, const random_access_iterator<ITER2>& it2) {
		return (!(it2 < it1));
	}

	template <typename ITER1, typename ITER2>
	bool operator>=(const random_access_iterator<ITER1>& it1, const random_access_iterator<ITER2>& it2) {
		return (!(it1 < it2));
	}

} // namespace ft

#endif // __RANDOMACCESSITERATOR_H__